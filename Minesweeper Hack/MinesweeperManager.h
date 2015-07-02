#pragma once
#include "pch.h"

class MinesweeperManager
{
public:
	MinesweeperManager();
	~MinesweeperManager();

private:

	PROCESSENTRY32 _WINMINEPROCESS32;
	HANDLE _hMinesweeperHandle;
	HWND _hMinesweeperWindow;


	UINT8 width;
	UINT8 height;

	DWORD dwWidthAddress = 0x1005334;
	DWORD dwHeightAddress = 0x1005338;

	DWORD dwStartOffset;

	POINT CursorPosOld;
};

