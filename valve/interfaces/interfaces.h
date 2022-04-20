#pragma once
#include <Windows.h>
#include <cstdlib>
#include <cstdint>
#include <TlHelp32.h>
#include <iostream>
#include <thread>
#include "../class/clientclass.h"

// lista interfejsów
#include "data/IClientEntityList.h"
#include "data/IVDebugOverlay.h"
#include "data/IEngineClient.h"
#include "data/IClientBaseDll.h"

namespace interfaces {
	// interfaces
	inline IClientEntityList* entitylist = nullptr;
	inline IVDebugOverlay* debugOverlay = nullptr;
	inline IClientMode* clientmode = nullptr;
	inline IClientBaseDll* client = nullptr;
	inline IEngineClient* engine = nullptr;
	// init
	bool init();
}

inline CEntity* localPlayer = nullptr;


inline struct consoleColor { /// gdzies na zadupiu
	int blue = 1;
	int green = 2;
	int aqua = 3;
	int red = 4;
	int purple = 5;
	int yellow = 6;
	int white = 7;
	int gray = 8;
	int lightBlue = 9;
	int lightGreen = 2 | FOREGROUND_INTENSITY;
	int lightAqua = 3 | FOREGROUND_INTENSITY;
	int lightRed = 4 | FOREGROUND_INTENSITY;
	int lightPurple = 5 | FOREGROUND_INTENSITY;
	int lightYellow = 6 | FOREGROUND_INTENSITY;
	int lightWhite = 7 | FOREGROUND_INTENSITY;
}clr;