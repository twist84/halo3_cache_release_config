#ifndef __STRING_IDS_H__
#define __STRING_IDS_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

enum string_id_namespaces
{
	_string_id_namespace_global = 0,
	_string_id_namespace_gui,
	_string_id_namespace_gui_alert,
	_string_id_namespace_gui_dialog,
	_string_id_namespace_game_engine,
	_string_id_namespace_game_start,
	_string_id_namespace_online,
	_string_id_namespace_saved_game,
	_string_id_namespace_gpu,
	k_string_id_namespace_count,
};

const long _string_id_invalid = -1;
const long _string_id_empty_string = 0;

const long k_string_id_namespace_bits = 14;
const long k_string_id_index_bits = 16;
const long k_string_id_index_mask = 65535;
const long k_string_id_length_shift = 30;
const long k_tag_string_id_length = 128;
const long k_maximum_string_ids = 36864;
const long k_maximum_string_id_namespaces = 256;

#define STRING_ID_FIRST(NAMESPACE) k_string_id_namespace_##NAMESPACE##_first = (_string_id_namespace_##NAMESPACE << k_string_id_index_bits) - 1
#define STRING_ID_ENTRY(NAMESPACE, NAME) _string_id_##NAMESPACE##__##NAME
#define STRING_ID_COUNT(NAMESPACE) k_string_id_namespace_##NAMESPACE##_count
#define STRING_ID(NAMESPACE, NAME) _string_id_##NAMESPACE##__##NAME

/* ---------- definitions */

typedef long string_id;

/* ---------- prototypes */

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __STRING_IDS_H__
