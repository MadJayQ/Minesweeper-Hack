#include "Console.h"


CConsole::CConsole()
{

}


CConsole::~CConsole()
{

}

void CConsole::InitConsole()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	saved_colors = static_cast<uint8_t>(Memory::GetConsoleWAttribute(hConsole));
	SetConsoleTextAttribute(hConsole, LRED);
	printf("hello");
}
