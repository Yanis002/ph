#ifndef CTYPE_H
#define CTYPE_H

extern unsigned char __lower_map[];
extern unsigned char __upper_map[];
extern const unsigned short __ctype_map[];

#define __digit 0x08

inline int tolower(int c) {
    return (c < 0 || c >= 128 ? c : (int) __lower_map[c]);
}

inline int toupper(int c) {
    return (c < 0 || c >= 128 ? c : (int) __upper_map[c]);
}

inline int isdigit(int c) {
    return (c < 0 || c >= 128 ? 0 : __ctype_map[c] & __digit);
}

#endif /* CTYPE_H */
