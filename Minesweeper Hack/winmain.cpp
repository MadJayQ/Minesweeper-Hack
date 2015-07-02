#include "pch.h"
#include "Console.h"


namespace
{
	CConsole* Console = nullptr;
}

int __cdecl _tmain(int arc, _TCHAR* argv[])
{
	Console = new CConsole();
	Console->InitConsole();
	for (;;)
	{
		if (GetAsyncKeyState(0xA4))
		{
			printf("WOAH!\n");
		}
	}

	return 0;
}