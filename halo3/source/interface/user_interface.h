#ifndef __USER_INTERFACE_H__
#define __USER_INTERFACE_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

enum e_controller_component
{
    _controller_component_button_a = 0,
    _controller_component_button_b,
    _controller_component_button_x,
    _controller_component_button_y,
    _controller_component_button_black,
    _controller_component_button_white,
    _controller_component_button_left_trigger,
    _controller_component_button_right_trigger,
    _controller_component_button_dpad_up,
    _controller_component_button_dpad_down,
    _controller_component_button_dpad_left,
    _controller_component_button_dpad_right,
    _controller_component_button_start,
    _controller_component_button_back,
    _controller_component_button_left_thumb,
    _controller_component_button_right_thumb,
    _controller_component_stick_left_thumb,
    _controller_component_stick_right_thumb,

    k_number_of_controller_components,

    _controller_component_button_right_shoulder = _controller_component_button_black,
    _controller_component_button_left_shoulder = _controller_component_button_white,
};

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __USER_INTERFACE_H__
