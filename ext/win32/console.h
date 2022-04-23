#pragma once
#include <Windows.h>
#include <iostream>
namespace console {
	inline FILE* pFile;
	void init();
	void detach();
	void color(WORD color);
}