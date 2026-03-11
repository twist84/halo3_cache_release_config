#ifndef __CONTROLLERS_H__
#define __CONTROLLERS_H__
#pragma once

/* ---------- headers */

#include "cseries/cseries_macros.h"

#include <cassert>

/* ---------- constants */

enum e_controller_index
{
    _controller0 = 0,
    _controller1 = 1,
    _controller2 = 2,
    _controller3 = 3,

    k_number_of_controllers = 4,

    k_no_controller = -1,
    k_any_controller = 255,
};

/* ---------- definitions */

/* ---------- prototypes */

inline e_controller_index first_controller()
{
    return _controller0;
}

inline e_controller_index next_controller(e_controller_index controller_index)
{
    assert(controller_index == k_no_controller || VALID_INDEX(controller_index, k_number_of_controllers));

    e_controller_index result = k_no_controller;
    if (controller_index >= _controller0 && controller_index < k_number_of_controllers - 1)
    {
        result = static_cast<e_controller_index>(controller_index + 1);
    }

    return result;
}

/* ---------- globals */

/* ---------- public code */

ENUM_OPERATORS(e_controller_index);

/* ---------- private code */

#endif // __CONTROLLERS_H__
