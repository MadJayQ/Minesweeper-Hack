#pragma once
#include "pch.h"
#include "MemoryUtils.h"


class CConsole
{
public:
	CConsole();
	~CConsole();

	void InitConsole();

private:
	HANDLE hConsole;
	uint8_t saved_colors;
};

