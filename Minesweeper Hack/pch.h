#pragma once

#define BLUE		 0x1
#define GREEN		 0x2
#define AQUA		 0x3
#define RED			 0x4
#define PURPLE		 0x5
#define YELLOW       0x6
#define WHITE        0x7
#define GRAY         0x8
#define LBLUE		 0x1 | 0x8
#define LGREEN		 0x2 | 0x8
#define LAQUA		 0x3 | 0x8
#define LRED	     0x4 | 0x8
#define LPURPLE		 0x5 | 0x8
#define LYELLOW      0x6 | 0x8
#define LWHITE       0x7 | 0x8
#define LGRAY        0x8 | 0x8


#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <TlHelp32.h>
#include <math.h>
#include <sstream>
#include <memory>