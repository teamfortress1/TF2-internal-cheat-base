#pragma once
#include "../../ext/minhook/minhook.h"
#include "../../valve/class/cusercommands.h"
#include "../../valve/interfaces/interfaces.h"
#include "../../ext/win32/console.h"

#include "../features/features.h"

namespace hooks {
	inline unsigned int getVirtualTable(void* _class, unsigned int index) { return static_cast<unsigned int>((*static_cast<int**>(_class))[index]); } //krzysztof learn vtables

	bool init();
	void detach();


	namespace CreateMove {
		using fn = bool(__thiscall*)(IClientMode*, float, CUserCmd*);
		bool __stdcall hook(float frameTime, CUserCmd* cmd);
	};
}