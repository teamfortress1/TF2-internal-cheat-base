#include "../valve/interfaces/interfaces.h"
#include "../ext/win32/console.h"
#include "hooks/hooks.h"
#include "../ext/netvars manager/netvars.h"
#include <fstream>
void startHack(HMODULE hModule)
{
	console::init();

	interfaces::init(); 

	Netvars::SetupNetvars();

	hooks::init();

	while (!GetAsyncKeyState(VK_DELETE))
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	
	hooks::detach();
	
	console::detach();

	FreeLibraryAndExitThread(hModule, 0);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD sReason, LPVOID lpReserved)
{
	switch (sReason)
	{
	case DLL_PROCESS_ATTACH:
		const auto pHandle = CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(startHack), hModule, 0, nullptr);
		if (pHandle)
			CloseHandle(pHandle);
		break;
	}
	return TRUE;
}