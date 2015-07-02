#include "MinesweeperManager.h"


CMinesweeperManager::CMinesweeperManager()
{

}


CMinesweeperManager::~CMinesweeperManager()
{

}

void CMinesweeperManager::AdjustCoords(int x, int y, POINT &pt)
{
	pt = { ((16 * x) + (16 >> 1)) + 12, ((16 * y) + (16 >> 1)) + 55 };
	ClientToScreen(_hMinesweeperWindow, &pt);
}

void CMinesweeperManager::ClickPoint(POINT pt, bool bRightClick = false)
{
	SetCursorPos(pt.x, pt.y);
	if (bRightClick)
	{
		mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
	}
	else
	{
		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
		mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	}
}

BYTE CMinesweeperManager::GetTileData(int x, int y)
{
	int xo = x + 1;
	int yo = (y + 1) * 32;
	return Memory::Read<BYTE>(dwStartOffset + (xo + yo), _hMinesweeperHandle);
}

bool CMinesweeperManager::Initialize()
{
	ProcessManager = new CProcessManager();
	if (!ProcessManager->FindProcessByName("winmine.exe", _WINMINEPROCESS32))
	{
		return false;
	}
	if (!ProcessManager->FindThreadByProcessID(_WINMINEPROCESS32.th32ProcessID))
	{
		
		return false;
	}
	
	if (!ProcessManager->LoadProcess(_WINMINEPROCESS32.th32ProcessID, _hMinesweeperHandle))
	{
		return false;
	}
	_hMinesweeperWindow = FindWindow("Minesweeper", "Minesweeper");
	if (!_hMinesweeperWindow || !IsWindow(_hMinesweeperWindow))
	{
		return false;
	}
	if (debug) {
		Console::SetColor(LGREEN);
		printf("Sucessfully Loaded All Process Information!\n");
	}

	width = Memory::Read<UINT8>(dwWidthAddress, _hMinesweeperHandle);
	height = Memory::Read<UINT8>(dwHeightAddress, _hMinesweeperHandle);

	return true;

}

void CMinesweeperManager::Tick()
{
	GetCursorPos(&CursorPosOld);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			BYTE data = GetTileData(x, y);
			if (debug){
				printf("0x%03x\n", data);
			}
			if (data == MINE_TILE)
			{
				//Click
				POINT coords;
				AdjustCoords(x, y, coords);
				ClickPoint(coords, true);
			}
			if (data != MINE_TILE && data == HIDDEN_TILE)
			{
				POINT coords;
				AdjustCoords(x, y, coords);
				ClickPoint(coords);
			}
		}
	}
	SetCursorPos(CursorPosOld.x, CursorPosOld.y);
}

