#include "ProcessManager.h"


CProcessManager::CProcessManager()
{

}


CProcessManager::~CProcessManager()
{
}

DWORD CProcessManager::FindProcessByName(char *_ProcessName, PROCESSENTRY32 &ProcessEntry)
{
	PROCESSENTRY32 processEntry32;
	processEntry32.dwSize = sizeof(PROCESSENTRY32);
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (!hSnapshot)
		return 0;
	while (Process32Next(hSnapshot, &processEntry32) == TRUE)
	{
		if (!strcmp(processEntry32.szExeFile, _ProcessName))
		{
			if (debug) {
				Console::SetColor(LGREEN);
				printf("%s Process Match\n", _ProcessName);
				Console::SetColor(saved_colors);
			}
			memmove((void*)&ProcessEntry, (void*)&processEntry32, sizeof(PROCESSENTRY32));
			CloseHandle(hSnapshot);
			return processEntry32.th32ProcessID;
		}
		else
		{
			if (debug){
				Console::SetColor(LRED);
				printf("%s Process Does Not Match %s\n", processEntry32.szExeFile, _ProcessName);
				Console::SetColor(saved_colors);
			}

		}
	}

	CloseHandle(hSnapshot);
	return 0x0;

}

DWORD CProcessManager::FindThreadByProcessID(DWORD PID)
{
	THREADENTRY32 threadEntry32;
	threadEntry32.dwSize = sizeof(THREADENTRY32);
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (!hSnapshot)
		return 0;
	if (!Thread32First(hSnapshot, &threadEntry32))
		return 0;
	do
	{
		if (threadEntry32.th32OwnerProcessID == PID)
		{
			if (debug) {
				Console::SetColor(LGREEN);
				printf("%x == %x\n", PID, threadEntry32.th32OwnerProcessID);
				Console::SetColor(saved_colors);
			}
			CloseHandle(hSnapshot);
			return threadEntry32.th32ThreadID;
		}
		else
		{
			if (debug) {
				Console::SetColor(RED);
				printf("%x != %x\n", PID, threadEntry32.th32OwnerProcessID);
				Console::SetColor(saved_colors);
			}
		}
	} while (Thread32Next(hSnapshot, &threadEntry32) == TRUE);

	CloseHandle(hSnapshot);
	return 0x0;
}

bool CProcessManager::LoadProcess(DWORD pid, HANDLE &hProcessHandle)
{
	hProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	if (!hProcessHandle)
	{
		if (debug) {
			Console::SetColor(RED);
			printf("FAILURE\n");
			Console::SetColor(saved_colors);
		}
		return false;
	}
	return true;
}