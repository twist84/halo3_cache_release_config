/* ---------- headers */

#include "physics/character_physics.h"

#include "cseries/constants.h"
#include "cseries/cseries_macros.h"

#include <cassert>

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

// hooks

// $TODO c_character_physics_component::set_mode

/* ---------- public code */

void c_character_physics_component::initialize(long object_index)
{
	m_object_index = object_index;
	m_mode = _mode_none;
	m_flags = 0;
	assert(m_object_index != NONE);
}

#if 0
void c_character_physics_component::set_mode(e_mode mode)
{
	e_mode old_mode = get_mode();
	switch (old_mode)
	{
	case _mode_ground:
		get_mode_ground()->dispose();
		break;

	case _mode_flying:
		get_mode_flying()->dispose();
		break;

	case _mode_dead:
		get_mode_dead()->dispose();
		break;

	case _mode_posture:
	case _mode_climbing:
		get_mode_sentinel()->dispose(m_object_index);
		break;

	case _mode_melee:
		get_mode_melee()->dispose();
		break;

	default:
		throw "unreachable";
		break;
	}

	m_mode = mode;

	switch (get_mode())
	{
	case _mode_ground:
		get_mode_ground()->initialize();
		break;

	case _mode_flying:
		get_mode_flying()->initialize();
		break;

	case _mode_dead:
		get_mode_dead()->initialize();
		break;

	case _mode_posture:
	case _mode_climbing:
	{
		real_point3d position = {};
		object_get_origin(m_object_index, &position);
		get_mode_sentinel()->initialize(get_mode() == _mode_climbing, &position);
	}
	break;

	case _mode_melee:
		get_mode_melee()->initialize();
		break;

	default:
		throw "unreachable";
		break;
	}

	if (old_mode != get_mode())
	{
		if (old_mode == _mode_dead || get_mode() == _mode_dead
			|| old_mode == _mode_posture || old_mode == _mode_climbing
			|| get_mode() == _mode_posture || get_mode() == _mode_climbing)
		{
			havok_object_rebuild(m_object_index);
		}
	}
}
#endif

c_character_physics_component::e_mode c_character_physics_component::get_mode() const
{
	assert(IN_RANGE_INCLUSIVE(m_mode, _mode_first, _mode_last));

	return static_cast<e_mode>(m_mode);
}

bool c_character_physics_component::is_sentinel_mode() const
{
	e_mode mode = get_mode();
	return mode == _mode_posture || mode == _mode_climbing;
}

bool c_character_physics_component::is_immune_to_collision_damage() const
{
	return m_collision_damage_imunity_counter != 0;
}

c_character_physics_mode_ground_datum *c_character_physics_component::get_mode_ground()
{
	assert(get_mode() == _mode_ground);
	return reinterpret_cast<c_character_physics_mode_ground_datum*>(m_character_physics_mode_datum_buffer);
}

c_character_physics_mode_flying_datum *c_character_physics_component::get_mode_flying()
{
	assert(get_mode() == _mode_flying);
	return reinterpret_cast<c_character_physics_mode_flying_datum*>(m_character_physics_mode_datum_buffer);
}

c_character_physics_mode_dead_datum *c_character_physics_component::get_mode_dead()
{
	assert(get_mode() == _mode_dead);
	return reinterpret_cast<c_character_physics_mode_dead_datum*>(m_character_physics_mode_datum_buffer);
}

c_character_physics_mode_sentinel_datum *c_character_physics_component::get_mode_sentinel()
{
	assert(is_sentinel_mode());
	return reinterpret_cast<c_character_physics_mode_sentinel_datum*>(m_character_physics_mode_datum_buffer);
}

c_character_physics_mode_melee_datum *c_character_physics_component::get_mode_melee()
{
	assert(get_mode() == _mode_melee);
	return reinterpret_cast<c_character_physics_mode_melee_datum*>(m_character_physics_mode_datum_buffer);
}

/* ---------- private code */
