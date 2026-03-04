/* ---------- headers */

#include "game/game.h"

#include "game/game_options.h"
#include "memory/thread_local_storage.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

struct game_globals_storage
{
	bool initializing;
	bool map_active;
	bool __unknown2;
	bool __unknown3;
	rex::be<unsigned long> active_structure_bsp_mask;
	rex::be<unsigned long> active_designer_zone_mask;
	rex::be<unsigned long> active_cinematic_zone_mask;
	game_options options;
	bool game_in_progress;
	bool game_lost;
	bool game_revert;
	bool __unknownD313;
	rex::be<long> game_lost_wait_time;
	bool game_finished;
	bool __unknownD319;
	bool __unknownD31A;
	bool __unknownD31B;
	rex::be<long> game_finished_wait_time;
	rex::be<long> game_ragdoll_count;
	char cluster_pvs[512];
	char cluster_pvs_local[512];
	char cluster_activation[512];
	bool __unknownD924;
	bool had_an_update_tick_this_frame;
	bool __unknownD926;
	bool __unknownD927;
	bool scripted_camera_pvs;
	bool __unknownD929;
	rex::be<unsigned short> scripted;
	rex::be<unsigned long> scripted_object_index;
};
static_assert(sizeof(game_globals_storage) == 0xD930);

/* ---------- prototypes */

REX_PPC_EXTERN_IMPORT(game_dispose_from_old_map);
REX_PPC_EXTERN_IMPORT(game_in_progress);

/* ---------- globals */

/* ---------- private variables */

/* ---------- public code */

void game_dispose_from_old_map(void)
{
	REX_PPC_INVOKE(game_dispose_from_old_map);
}

bool game_in_progress(void)
{
	game_globals_storage* game_globals = get_thread_local_by_offset<game_globals_storage>(k_tls_game_globals_offset);

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

PPC_HOOK(rex_game_in_progress, game_in_progress);

/* ---------- private code */
