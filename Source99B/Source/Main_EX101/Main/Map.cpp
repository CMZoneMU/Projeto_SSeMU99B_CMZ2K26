#include "stdafx.h"
#include "Map.h"
#include "CustomMap.h"
#include "Offset.h"
#include "Util.h"

void InitMap()  // OK
{
	SetByte(0x00607090,0xEB); // Fix Check .map files

	SetByte(0x00607095,0xEB); // Fix Check .map files

	SetByte(0x00607141,0xEB); // Fix Check .att files

	SetByte(0x00607146,0xEB); // Fix Check .att files

	SetByte(0x006071B3,0xEB); // Fix Check .obj files

	SetByte(0x006071B8,0xEB); // Fix Check .obj files

	SetCompleteHook(0xE8,0x004BEB03,&LoadMapName);

	SetCompleteHook(0xE8,0x004C1900,&LoadMapName);

	SetCompleteHook(0xE8,0x005DF615,&LoadMapName);

	SetCompleteHook(0xE8,0x0064D303,&LoadMapTitle);
}

char* LoadMapName(int index) //OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(index);

	if(lpInfo != 0)
	{
		return lpInfo->MapName;
	}

	return ((char*(*)(int))0x005DF2A0)(index);
}

int LoadMapTitle(char* path,int index,int c,int d,int e,int f) // OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(*(DWORD*)MAIN_CURRENT_MAP);

	if(lpInfo != 0)
	{
		path = lpInfo->TitlePath;
	}

	return ((int(__cdecl*)(char*,int,int,int,int,int))0x0062C670)(path,index,c,d,e,f);
}