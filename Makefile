ifeq ($(REGION), EUR)
	REGION_NAME := eur
	REGION_SUFFIX := P
else ifeq ($(REGION), USA)
	REGION_NAME := usa
	REGION_SUFFIX := E
else ifneq ($(REGION),)
	$(error Unknown region '$(REGION)')
endif

ifeq ($(OS),Windows_NT)
	WINE :=
else
	WINE := wine
	PYTHON ?= python3.11
endif

PYTHON ?= python

ROOT       := $(shell pwd)
BUILD_DIR  := build
TARGET_DIR := $(BUILD_DIR)/$(REGION_NAME)
TOOLS_DIR  := tools
BASE_DIR   := ph_$(REGION_NAME)
ARM7_BIOS  := arm7_bios.bin
ASSETS_TXT := assets.txt

ASM_FILES := $(shell find asm -name *.s)
CXX_FILES := $(shell find src -name *.cpp)
ASM_OBJS = $(ASM_FILES:%.s=$(TARGET_DIR)/%.s.o)
ASM_INCS = $(ASM_FILES:%.s=%.inc)
CXX_OBJS = $(CXX_FILES:%.cpp=$(TARGET_DIR)/%.cpp.o)

OV_BINS := $(wildcard $(TARGET_DIR)/overlays/*.bin)
OV_LZS = $(OV_BINS:%.bin=%.lz)

NDS_FILE := ph_$(REGION_NAME).nds
BASE_ROM := baserom_$(REGION_NAME).nds
CHECKSUM := ph_$(REGION_NAME).sha1

MW_VER     := 2.0/sp1p5
MW_ASM     := $(ROOT)/$(TOOLS_DIR)/mwccarm/$(MW_VER)/mwasmarm.exe
MW_CC      := $(ROOT)/$(TOOLS_DIR)/mwccarm/$(MW_VER)/mwccarm.exe
MW_LD      := $(ROOT)/$(TOOLS_DIR)/mwccarm/$(MW_VER)/mwldarm.exe
MW_LICENSE := $(ROOT)/$(TOOLS_DIR)/mwccarm/license.dat
LCF_FILE   := $(ROOT)/$(BUILD_DIR)/arm9_linker_script.lcf
OBJS_FILE  := $(ROOT)/$(BUILD_DIR)/arm9_objects.txt

ASM_FLAGS := -proc arm5te -d $(REGION) -i asm -msgstyle gcc
CC_FLAGS  := -proc arm946e -interworking -O4,p -enum int -i include -nolink -d $(REGION) -char signed -lang=c++ -sym on -msgstyle gcc
LD_FLAGS  := -proc arm946e -nostdlib -interworking -nodead -m Entry -map closure,unused -o main.bin -msgstyle gcc

ifeq ($(NONMATCHING),1)
	CC_FLAGS += -DNONMATCHING
endif

.PHONY: help
help:
	@echo "Usage:"
	@echo "make extract .................... Extracts provided base ROMs"
	@echo "make extract REGION=(USA|EUR) ... Extracts specific base ROM"
	@echo "make eur ........................ Builds European ROM"
	@echo "make usa ........................ Builds American ROM"
	@echo "make clean ...................... Clean up build files"
	@echo "make gen_externs ................ Generates .inc files for Assembly"
	@echo "make format ..................... Formats the codebase"

.PHONY: eur
eur:
	$(MAKE) all REGION=EUR

.PHONY: usa
usa:
	$(MAKE) all REGION=USA

.PHONY: all
all: tools rom
	sha1sum $(NDS_FILE)
	sha1sum -c $(CHECKSUM)

.PHONY: tools
tools:
	cd $(TOOLS_DIR)/compress && $(MAKE)
	cd $(TOOLS_DIR)/rom && $(MAKE)

.PHONY: rom
rom: arm9
ifneq (,$(wildcard $(ARM7_BIOS)))
	$(TOOLS_DIR)/rom/buildrom -a $(BASE_DIR) -b $(TARGET_DIR) -r $(REGION_SUFFIX) -o $(NDS_FILE) -s $(ASSETS_TXT) -7 $(ARM7_BIOS)
else
	$(TOOLS_DIR)/rom/buildrom -a $(BASE_DIR) -b $(TARGET_DIR) -r $(REGION_SUFFIX) -o $(NDS_FILE) -s $(ASSETS_TXT)
endif

.PHONY: extract
extract: tools
ifeq (,$(REGION))
	$(MAKE) extract REGION=EUR
	$(MAKE) extract REGION=USA
else ifneq (,$(wildcard $(BASE_ROM)))
	$(TOOLS_DIR)/rom/extractrom -o $(BASE_DIR) -i $(BASE_ROM)
endif

.PHONY: arm9
arm9: link
	$(MAKE) compress

.PHONY: setup
setup:
	mkdir -p $(TARGET_DIR)/overlays

.PHONY: clean
clean:
	rm -rf build/

.PHONY: lcf
lcf: setup $(TOOLS_DIR)/lcf.py
	$(PYTHON) $(TOOLS_DIR)/lcf.py

$(ASM_OBJS): $(TARGET_DIR)/%.o: %
	mkdir -p $(dir $@)
	LM_LICENSE_FILE=$(MW_LICENSE) $(WINE) $(MW_ASM) $(ASM_FLAGS) $< -o $@

$(CXX_OBJS): $(TARGET_DIR)/%.o: %
	mkdir -p $(dir $@)
	LM_LICENSE_FILE=$(MW_LICENSE) $(WINE) $(MW_CC) $(CC_FLAGS) $< -o $@

.PHONY: link
link: lcf $(ASM_OBJS) $(CXX_OBJS)
	cd $(TARGET_DIR) && LM_LICENSE_FILE=$(MW_LICENSE) $(WINE) $(MW_LD) $(LD_FLAGS) $(LCF_FILE) @$(OBJS_FILE)

.PHONY: compress
compress: $(OV_LZS)
	$(TOOLS_DIR)/compress/compress -s 0x4000 -i $(TARGET_DIR)/arm9.bin -o $(TARGET_DIR)/arm9.lz

$(OV_LZS): %.lz: %.bin
	$(TOOLS_DIR)/compress/compress -p -i $< -o $@

.PHONY: gen_externs
gen_externs: $(ASM_INCS)

$(ASM_INCS): %.inc: %.s
	$(PYTHON) $(TOOLS_DIR)/gen_externs.py $<

.PHONY: format
format:
	find include src -name '*.h' -o -name '*.c' | xargs clang-format -i
	find include src -name '*.hpp' -o -name '*.cpp' | xargs clang-format -i
