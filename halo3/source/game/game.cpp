/* ---------- headers */

#include "game/game.h"

#include "game/game_options.h"
#include "memory/static_array.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

// $TODO move to cseries/location.h
struct s_cluster_reference
{
	char bsp_index; // 0x0
	unsigned char cluster_index; // 0x1
};
static_assert(sizeof(s_cluster_reference) == 0x2);

struct s_game_cluster_bit_vectors
{
	c_static_array<c_static_flags<256>, 16> bit_vectors; // 0x0
};
static_assert(sizeof(s_game_cluster_bit_vectors) == 512);

struct game_globals_storage
{
	bool initializing; // 0x0
	bool map_active; // 0x1

	bool __unknown2; // 0x2
	bool __unknown3; // 0x3

	rex::be<unsigned long> active_structure_bsp_mask; // 0x4
	rex::be<unsigned long> active_designer_zone_mask; // 0x8
	rex::be<unsigned long> active_cinematic_zone_mask; // 0xC
	game_options options; // 0x10
	bool game_in_progress; // 0xD310
	bool game_lost; // 0xD311
	bool game_revert; // 0xD312

	bool __unknownD313; // 0xD313

	rex::be<long> game_loss_timer; // 0xD314
	bool game_finished; // 0xD318

	bool __unknownD319; // 0xD319
	bool __unknownD31A; // 0xD31A
	bool __unknownD31B; // 0xD31B

	rex::be<long> game_finished_timer; // 0xD31C
	rex::be<long> game_ragdoll_count; // 0xD320
	s_game_cluster_bit_vectors cluster_pvs; // 0xD324
	s_game_cluster_bit_vectors cluster_pvs_local; // 0xD524
	s_game_cluster_bit_vectors cluster_activation; // 0xD724

	bool __unknownD924; // 0xD924

	bool game_had_an_update_tick_this_frame; // 0xD925

	bool __unknownD926; // 0xD926
	bool __unknownD927; // 0xD927

	bool pvs_use_scripted_camera; // 0xD928
	unsigned char unused_pad; // 0xD929
	rex::be<short> pvs_activation_type; // 0xD92A
	union
	{
		rex::be<long> object_index; // 0x0
		s_cluster_reference cluster_reference; // 0x0
	} pvs_activation; // 0xD92C
};
static_assert(sizeof(game_globals_storage) == 0xD930);

/* ---------- prototypes */

/* ---------- globals */

thread_local game_globals_storage* game_globals = nullptr;

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(__tls_set_g_game_globals_allocator);
REX_PPC_EXTERN_IMPORT(game_dispose_from_old_map);
REX_PPC_EXTERN_IMPORT(game_in_progress);
REX_PPC_EXTERN_IMPORT(game_initialize);

// hooks

REX_PPC_HOOK(__tls_set_g_game_globals_allocator);
REX_PPC_HOOK(game_in_progress);

/* ---------- public code */

void __tls_set_g_game_globals_allocator(void* new_address)
{
	REX_PPC_INVOKE(__tls_set_g_game_globals_allocator, new_address);

	game_globals = static_cast<game_globals_storage*>(new_address);
}

void game_dispose_from_old_map(void)
{
	REX_PPC_INVOKE(game_dispose_from_old_map);
}

bool game_in_progress(void)
{
	bool result;
	if (game_globals != nullptr)
	{
		result = game_globals->game_in_progress;
	}
	else
	{
		result = false;
	}
	return result;
}

void game_initialize(void)
{
	REX_PPC_INVOKE(game_initialize);
}

bool game_is_ui_shell()
{
	bool result;
	if (game_globals != nullptr)
	{
		result = game_globals->options.game_mode == _game_mode_ui_shell;
	}
	else
	{
		result = false;
	}
	return result;
}

/* ---------- private code */
