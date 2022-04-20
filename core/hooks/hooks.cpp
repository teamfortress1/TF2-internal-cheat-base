#include "hooks.h"
hooks::CreateMove::fn CreateMoveOriginal = nullptr;


bool hooks::init()
{
	const auto CreateMoveTarget = reinterpret_cast<void*>(getVirtualTable(interfaces::clientmode, 21));

	if (MH_Initialize() != MH_OK)
		std::cout << "failed to initialize\n";

	if (MH_CreateHook(CreateMoveTarget, &CreateMove::hook, reinterpret_cast<void**>(&CreateMoveOriginal)) != MH_OK)
		std::cout << "failed to hook createmove\n";

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
		std::cout << "failed to enable hooks\n";

	console::color(clr.purple);
	std::cout << "[SETUP] hooks loaded\n";
	return true;
}

void hooks::detach()
{
	MH_DisableHook(MH_ALL_HOOKS);
	MH_RemoveHook(MH_ALL_HOOKS);
	MH_Uninitialize();
}

bool __stdcall hooks::CreateMove::hook(float frameTime, CUserCmd* cmd)
{
	const bool pResult = CreateMoveOriginal(interfaces::clientmode,frameTime, cmd);

	if (!cmd)
		return pResult;

	localPlayer = interfaces::entitylist->GetClientEntity(interfaces::engine->GetLocalPlayer());
	
	misc::CreateMove(cmd);
	esp::CreateMove(cmd);

	return pResult;
}