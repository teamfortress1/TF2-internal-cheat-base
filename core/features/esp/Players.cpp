#include "../features.h"
void debugoverlay() {

	for (int i = 1; i <= 32; i++)
	{
		auto player = interfaces::entitylist->GetClientEntity(i);
		if (!player)
			continue;

		std::string health_unchar = std::to_string(player->health());
		const char* health = health_unchar.c_str();
		if (player->health() <= player->GetMaxHealth() && player->team() != localPlayer->team() && player->isAlive())
		{
			interfaces::debugOverlay->AddEntityTextOverlay(i, 0, 0, 255, 255, 0, 255, "Player");
			interfaces::debugOverlay->AddEntityTextOverlay(i, 2, 0, 255, 255, 0, 255, health);
		}
	}

}
void esp::CreateMove(CUserCmd* cmd)
{
	if (!interfaces::engine->isConnected() || !interfaces::engine->isInGame())
		return;

	debugoverlay();
}