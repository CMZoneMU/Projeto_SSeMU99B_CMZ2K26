#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

#ifndef DEBUG_CONSOLE
#define DEBUG_CONSOLE 1
#endif

#ifndef LUA_SCRIPT
#define LUA_SCRIPT 0
#endif

// System Include
#include <windows.h>
#include <iostream>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <gl\GL.h>
#include <shellapi.h>
#include "..\\..\\..\\Util\\detours\\detours.h"
#if(LUA_SCRIPT == 1)
#include "..\\..\\..\\Util\\lua\\include\\lua.hpp"
#endif

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"..\\..\\..\\Util\\cryptopp\\Release\\cryptlib.lib")
#pragma comment(lib,"..\\..\\..\\Util\\detours\\detours.lib")
#if(LUA_SCRIPT == 1)
#pragma comment(lib,"..\\..\\..\\Util\\lua\\lua52.lib")
#endif

extern DWORD gLevelExperience[1001];
extern DWORD CharacterMaxLevel;