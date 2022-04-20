#include "../features.h"

void BunnyHop(CUserCmd* cmd)
{
	if (!(localPlayer->flags() & fl_onground))
		cmd->buttons &= ~in_jump;
};

void misc::CreateMove(CUserCmd* cmd)
{
	if (!interfaces::engine->isConnected() || !interfaces::engine->isInGame())
		return;

	BunnyHop(cmd);
}