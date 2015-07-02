#pragma once

#include "pch.h"


namespace Memory
{
	static inline WORD GetConsoleWAttribute(HANDLE hConsoleHandle)
	{
		CONSOLE_SCREEN_BUFFER_INFO con_info;
		GetConsoleScreenBufferInfo(hConsoleHandle, &con_info);
		return con_info.wAttributes;
	}

	template <class cClass>
	static inline void Write(DWORD dwAdress, cClass data, HANDLE hProcessHandle)
	{
		WriteProcessMemory(hProcessHandle, (void**)dwAdress, &data, sizeof(cClass), nullptr);
	}

	template<class cClass>
	static inline cClass Read(DWORD dwAddress, HANDLE hProcessHandle)
	{
		cClass cData;
		ReadProcessMemory(hProcessHandle, (void**)dwAddress, &cData, sizeof(cClass), nullptr);
		return cData;
	}
}