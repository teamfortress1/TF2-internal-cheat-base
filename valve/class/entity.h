#pragma once
#include "../../ext/netvars manager/netvars.h"
#include "../math/vec3d.h"
#include "colid.h"

class CEntity {
public:
	NETVAR(health, "CBasePlayer->m_iHealth", int)
	NETVAR(team, "CBaseEntity->m_iTeamNum", int)
	NETVAR(flags, "CBasePlayer->m_fFlags", int)
	int GetMaxHealth()
	{
		using original_fn = int(__thiscall*)(CEntity*);
		return (*(original_fn**)this)[107](this);
	}
	bool isAlive()
	{
		if (!this) return false;
		return this->health() > 1;
	}
	vec3_t& absOrigin() {
		using original_fn = vec3_t & (__thiscall*)(void*);
		return (*(original_fn**)this)[10](this);;
	}
	collideable_t* collideable() {
		using original_fn = collideable_t * (__thiscall*)(void*);
		return (*(original_fn**)this)[3](this);
	}
};