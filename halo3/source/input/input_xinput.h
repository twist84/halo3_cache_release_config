#ifndef __INPUT_XINPUT_H__
#define __INPUT_XINPUT_H__
#pragma once

/* ---------- headers */

#include "math/integer_math.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

struct rumble_state
{
    unsigned short left_speed; // 0x0
    unsigned short right_speed; // 0x2
};
static_assert(sizeof(rumble_state) == 0x4);

struct rumble_state_be
{
    rex::be<unsigned short> left_speed; // 0x0
    rex::be<unsigned short> right_speed; // 0x2
};
static_assert(sizeof(rumble_state_be) == 0x4);

struct debug_gamepad_data
{
    point2d sticks[2]; // 0x0
};
static_assert(sizeof(debug_gamepad_data) == 8);

struct debug_gamepad_data_be
{
    point2d_be sticks[2]; // 0x0
};
static_assert(sizeof(debug_gamepad_data_be) == 8);

/* ---------- prototypes */

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __INPUT_XINPUT_H__
