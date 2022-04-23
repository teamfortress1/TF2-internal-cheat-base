#include "console.h"
#include "../../valve/interfaces/interfaces.h"


void console::init()
{
	AllocConsole();
	SetConsoleTitle("cmd");
	freopen_s(&pFile, "CONOUT$", "w", stdout);
}
void console::detach()
{
	if (pFile)
		fclose(pFile);
	FreeConsole();
}

void console::color(WORD color)
{
	HANDLE pHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(pHandle, color);
}
