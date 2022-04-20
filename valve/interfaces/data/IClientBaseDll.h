#pragma once
#include "../class/clientclass.h"

class IClientBaseDll {
public:
	CClientClass* getClientAllClass() {
		using original_fn = CClientClass * (__thiscall*)(IClientBaseDll*);
		return (*(original_fn**)this)[8](this);
	}
};