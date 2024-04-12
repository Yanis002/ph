#pragma once

#include "global.h"
#include "lib/touch.h"
#include "types.h"

typedef u16 TouchFlags;
enum TouchFlag_ {
    TouchFlag_TouchedNow = 0x0001,
    TouchFlag_UntouchedNow = 0x0002,
    TouchFlag_Repeat = 0x0004,
};

class TouchControl {
  public:
    /* 00 */ u16 mSpeed;
    /* 02 */ u16 mTimeBetweenTouches; // gets set to mTimeSinceTouch when touching the screen
    /* 04 */ u16 mTimeSinceTouch; // increases by mSpeed every frame
    /* 06 */ unk16 mRepeatStart;
    /* 08 */ unk16 mRepeatLoop;
    // mRepeatTimer starts at mRepeatStart, decreases by mSpeed while touching the screen.
    // if equal to 0, mRepeatTimer gets set to mRepeatLoop and the Repeat flag is set
    /* 0a */ unk16 mRepeatTimer;
    /* 0c */ bool mTouch;
    /* 10 */ s32 mTouchX;
    /* 14 */ s32 mTouchY;
    /* 18 */ bool mTouchPrev;
    /* 1c */ s32 mTouchPrevX;
    /* 20 */ s32 mTouchPrevY;
    /* 24 */ s32 mTouchLastX;
    /* 28 */ s32 mTouchLastY;
    /* 2c */ s32 mTouchStartX;
    /* 30 */ s32 mTouchStartY;
    /* 34 */ TouchFlags mFlags;
    /* 36 */

    TouchControl();
    void IncreaseSpeed(s16 increase);
    void UpdateFlags(u16 speed);
    void UpdateWithStateFlags(TouchStateFlags* state, u16 speed);
    void Update(TouchState* state, u16 speed);
    bool func_ov00_0207aeac();
    void UpdateConditionally(TouchState* state, u16 speed);
    void func_ov00_0207af38(u16 speed, bool param2);
};
