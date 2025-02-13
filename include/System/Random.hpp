#pragma once

#include "global.h"
#include "types.h"

struct Random {
    /* 00 */ u64 mRandomValue;
    /* 08 */ u64 mFactor;
    /* 10 */ u64 mAddend;
    /* 18 */

    /**
     * Generate a random number from 0 (inclusive) to `max` (exclusive)
     */
    inline u32 Next(u32 max) {
        mRandomValue = mAddend + mFactor * mRandomValue;
        u64 result   = (mRandomValue >> 32) * max;
        return result >> 32;
    }

    //! TODO: cleanup when it's figured out
    inline u32 Next2(s32 max) {
        u64 result = 0;

        if (max > 0) {
            result = mRandomValue * mFactor + mAddend;
            // result = (mFactor * (mRandomValue >> 32) + mAddend);
            mRandomValue = result;

            if (max != 0) {
                return (result * max) >> 32;
            }
        }

        return result;
    }

    inline u64 Rand_Next() {
        u64 next     = mRandomValue * mFactor + mAddend;
        mRandomValue = next;
        return next;
    }

    inline u64 Next3_1(s32 value) {
        u64 result   = mAddend + mFactor * mRandomValue;
        mRandomValue = result;

        // u64 result = Rand_Next();

        if (value != 0) {
            result *= value;
        }

        return result;
    }

    inline u32 Next_3_2(s32 max, s32 min) {
        u64 result = 0;
        s32 value  = (max - min) + 1;

        if (value > 0) {
            // result = mAddend + mFactor * mRandomValue;
            // result = (mFactor * (mRandomValue >> 32) + mAddend);
            // mRandomValue = result;

            result = Next3_1(value) >> 32;
        }

        return (u32) result + max;
    }

    inline u32 Next3(s32 val) {
        s32 result = 0;
        // s32 value = ;
        // result = Next_3_2((max - min) + 1);

        return val;
    }
};

extern Random *gRandom;
