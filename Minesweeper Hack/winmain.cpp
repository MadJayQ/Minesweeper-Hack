#include "pch.h"
#include "Console.h"
#include "MinesweeperManager.h"


CMinesweeperManager* MinesweeperManager = nullptr;
HANDLE hConsole;
int saved_colors;
bool debug = true;


int __cdecl _tmain(int arc, _TCHAR* argv[])
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	saved_colors = Memory::GetConsoleWAttribute(hConsole);

	MinesweeperManager = new CMinesweeperManager();
	if (!MinesweeperManager->Initialize())
	{
		return 0;
	}
	for (;;)
	{
		if (GetAsyncKeyState(0xa4))
		{
			MinesweeperManager->Tick();
		}
	}

	CloseHandle(hConsole);
	return 0;
}