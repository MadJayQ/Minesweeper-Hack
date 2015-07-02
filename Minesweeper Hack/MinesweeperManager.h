#pragma once
#include "pch.h"
#include "ProcessManager.h"

#define MINE_TILE		0x8f
#define HIDDEN_TILE		0x0f

class CMinesweeperManager
{
public:
	CMinesweeperManager();
	~CMinesweeperManager();

	bool Initialize();
	void Tick();
	BYTE GetTileData(int x, int y);
	void AdjustCoords(int x, int y, POINT &pt);
	void ClickPoint(POINT pt, bool bRightClick);

private:

	PROCESSENTRY32 _WINMINEPROCESS32;
	HANDLE _hMinesweeperHandle;
	HWND _hMinesweeperWindow;


	UINT8 width;
	UINT8 height;

	DWORD dwWidthAddress = 0x1005334;
	DWORD dwHeightAddress = 0x1005338;

	DWORD dwStartOffset = 0x1005340;

	POINT CursorPosOld;
	CProcessManager* ProcessManager = nullptr;
};

