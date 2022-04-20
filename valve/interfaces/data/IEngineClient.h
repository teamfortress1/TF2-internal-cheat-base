#pragma once

class IEngineClient {
public:
	int GetLocalPlayer()
	{
			using original = bool(__thiscall*)(IEngineClient*);
			return (*(original**)this)[12](this);
	}
	bool isInGame()
	{
		using original = bool(__thiscall*)(IEngineClient*);
		return (*(original**)this)[26](this);
	}
	bool isConnected()
	{
		using original = bool(__thiscall*)(IEngineClient*);
		return (*(original**)this)[27](this);
	}
	/*int getMaxPlayers()
	{
		using original = int(__thiscall*)(IEngineClient*);
		return (*(original**)this)[20](this);
	}*/
};