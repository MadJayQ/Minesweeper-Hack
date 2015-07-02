#pragma once
#include "pch.h"
#include "Console.h"

class CProcessManager
{
public:
	CProcessManager();
	~CProcessManager();

	DWORD FindProcessByName(char *_ProcessName, PROCESSENTRY32 &ProcessEntry);
	DWORD FindThreadByProcessID(DWORD _dwProcessID);
	bool LoadProcess(DWORD pid, HANDLE &hProcessHandle);

private:
};

