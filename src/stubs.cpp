#pragma region includes

#include "generated/halo3_cache_release_config.h"
#include "generated/halo3_cache_release_init.h"

#include "interface/gui_string_ids.h"
#include "tag_files/string_id_globals.h"

#include <rex/rex_app.h>
#include <rex/ppc/function.h>

#pragma endregion

#pragma region xbox_stubs

PPC_STUB(_IoDismountVolume);
PPC_STUB(_XCustomUnregisterDynamicActions);
PPC_STUB(_XCustomSetDynamicActions);
PPC_STUB(_XCustomGetLastActionPressEx);
PPC_STUB(_XCustomGetCurrentGamercard);
PPC_STUB(_XamShowPlayerReviewUI);
PPC_STUB(_XamShowMessageComposeUI);
PPC_STUB(_XamShowGamerCardUIForXUID);
PPC_STUB(_XamShowFriendsUI);
PPC_STUB(_XamShowFriendRequestUI);
PPC_STUB(_XamShowCustomMessageComposeUI);
PPC_STUB(_NetDll_XNetUnregisterKey);
PPC_STUB(_NetDll_XNetUnregisterInAddr);
PPC_STUB(_NetDll_XNetServerToInAddr);
PPC_STUB(_NetDll_XNetRegisterKey);
PPC_STUB(_NetDll_XNetQosLookup);
PPC_STUB(_NetDll_XNetQosGetListenStats);
PPC_STUB(_NetDll_XNetGetConnectStatus);
PPC_STUB(_NetDll_XNetCreateKey);
PPC_STUB(_NetDll_XNetConnect);
PPC_STUB(_XNetLogonGetTitleID);
PPC_STUB(_XamVoiceSubmitPacket);
PPC_STUB(roundevenf);

#pragma endregion

#pragma region game_stubs

PPC_STUB(rex_hs_runtime_update); // bad switch in `c_havok_component::build_physics_model_component`
PPC_STUB(rex_saved_film_directory_delete_contents)
PPC_STUB(rex_autosave_queue_save_current_game_variant_to_queue)
PPC_STUB_RETURN(rex_chud_text_widget_compute_geometry, false)

#pragma endregion

#pragma region midasm_hooks

#pragma region constants

enum e_gamepad_button
{
	FIRST_GAMEPAD_ANALOG_BUTTON = 0x0,
	_gamepad_analog_button_left_trigger = 0x0,
	_gamepad_analog_button_right_trigger = 0x1,
	NUMBER_OF_GAMEPAD_ANALOG_BUTTONS = 0x2,
	FIRST_GAMEPAD_BINARY_BUTTON = 0x2,
	_gamepad_binary_button_dpad_up = 0x2,
	_gamepad_binary_button_dpad_down = 0x3,
	_gamepad_binary_button_dpad_left = 0x4,
	_gamepad_binary_button_dpad_right = 0x5,
	_gamepad_binary_button_start = 0x6,
	_gamepad_binary_button_back = 0x7,
	_gamepad_binary_button_left_thumb = 0x8,
	_gamepad_binary_button_right_thumb = 0x9,
	_gamepad_binary_button_a = 0xA,
	_gamepad_binary_button_b = 0xB,
	_gamepad_binary_button_x = 0xC,
	_gamepad_binary_button_y = 0xD,
	_gamepad_binary_button_left_bumper = 0xE,
	_gamepad_binary_button_right_bumper = 0xF,
	NUMBER_OF_GAMEPAD_BUTTONS = 0x10,
	NUMBER_OF_GAMEPAD_BINARY_BUTTONS = 0xE,
};

enum e_controller_component
{
	_controller_component_button_a = 0x0,
	_controller_component_button_b = 0x1,
	_controller_component_button_x = 0x2,
	_controller_component_button_y = 0x3,
	_controller_component_button_black = 0x4,
	_controller_component_button_white = 0x5,
	_controller_component_button_left_trigger = 0x6,
	_controller_component_button_right_trigger = 0x7,
	_controller_component_button_dpad_up = 0x8,
	_controller_component_button_dpad_down = 0x9,
	_controller_component_button_dpad_left = 0xA,
	_controller_component_button_dpad_right = 0xB,
	_controller_component_button_start = 0xC,
	_controller_component_button_back = 0xD,
	_controller_component_button_left_thumb = 0xE,
	_controller_component_button_right_thumb = 0xF,
	_controller_component_stick_left_thumb = 0x10,
	_controller_component_stick_right_thumb = 0x11,
	k_number_of_controller_components = 0x12,
	_controller_component_button_right_shoulder = 0x4,
	_controller_component_button_left_shoulder = 0x5,
};

#pragma endregion

void midasm_hook__event_manager_button_pressed(PPCRegister& r10, PPCRegister& r11)
{
	switch (r10.u32)
	{
	case _gamepad_analog_button_left_trigger:
		r11.s64 = _controller_component_button_left_trigger;
		break;
	case _gamepad_analog_button_right_trigger:
		r11.s64 = _controller_component_button_right_trigger;
		break;
	case _gamepad_binary_button_start:
		r11.s64 = _controller_component_button_start;
		break;
	case _gamepad_binary_button_back:
		r11.s64 = _controller_component_button_back;
		break;
	case _gamepad_binary_button_left_thumb:
		r11.s64 = _controller_component_button_left_thumb;
		break;
	case _gamepad_binary_button_right_thumb:
		r11.s64 = _controller_component_button_right_thumb;
		break;
	case _gamepad_binary_button_a:
		r11.s64 = _controller_component_button_a;
		break;
	case _gamepad_binary_button_b:
		r11.s64 = _controller_component_button_b;
		break;
	case _gamepad_binary_button_x:
		r11.s64 = _controller_component_button_x;
		break;
	case _gamepad_binary_button_y:
		r11.s64 = _controller_component_button_y;
		break;
	case _gamepad_binary_button_left_bumper:
		r11.s64 = _controller_component_button_left_shoulder;
		break;
	case _gamepad_binary_button_right_bumper:
		r11.s64 = _controller_component_button_right_shoulder;
		break;
	}
}

void midasm_hook__c_main_menu_screen_widget_post_initialize(PPCRegister& r11, PPCRegister& r28)
{
	switch (r11.u32)
	{
	case 0:
		r28.u32 = STRING_ID(gui, campaign);
		break;
	case 1:
		r28.u32 = STRING_ID(gui, matchmaking);
		break;
	case 2:
		r28.u32 = STRING_ID(global, multiplayer);
		break;
	case 3:
		r28.u32 = STRING_ID(gui, mapeditor);
		break;
	case 4:
		r28.u32 = STRING_ID(gui, theater);
		break;
	default:
		break;
	}
}

#pragma endregion
