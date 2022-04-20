#include "interfaces.h"
#include "../../ext/win32/console.h"
void* getInterface(const char* mod, const char* iface) {
	console::color(clr.green);
	using fn_capture_iface_t = void* (*)(const char*, int*);
	auto fn_addr = (fn_capture_iface_t)GetProcAddress(GetModuleHandleA(mod), "CreateInterface");

	auto iface_addr = fn_addr(iface, nullptr);
	printf("interface %s located 0x%p\n", iface, fn_addr(iface, nullptr));
	return iface_addr;
}

bool interfaces::init()
{
	client = reinterpret_cast<IClientBaseDll*>(getInterface("client.dll", "VClient017"));
	entitylist = reinterpret_cast<IClientEntityList*>(getInterface("client.dll", "VClientEntityList003"));
	debugOverlay = reinterpret_cast<IVDebugOverlay*>(getInterface("engine.dll", "VDebugOverlay003"));
	engine = reinterpret_cast<IEngineClient*>(getInterface("engine.dll", "VEngineClient014"));

	clientmode = **reinterpret_cast<IClientMode***>((*reinterpret_cast<uintptr_t**>(client))[10] + 5); // vtables learn krzysztof

	return true;
}