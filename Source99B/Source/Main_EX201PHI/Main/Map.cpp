#include "stdafx.h"
#include "Map.h"
#include "CustomMap.h"
#include "Offset.h"
#include "Util.h"

void InitMap()  // OK
{
	SetByte(0x00690262,0xEB); // Fix Check .map files

	SetByte(0x00690268,0xEB); // Fix Check .map files

	SetByte(0x00690455,0xEB); // Fix Check .att files

	SetByte(0x0069045B,0xEB); // Fix Check .att files

	SetByte(0x006904F8,0xEB); // Fix Check .obj files

	SetByte(0x006904FE,0xEB); // Fix Check .obj files

	SetByte(0x00690261,0x69); // Increase terrain

	SetByte(0x00690454,0x69); // Increase terrain

	SetByte(0x006904F7,0x69); // Increase terrain

	SetByte(0x006904F7,0x69); // Increase terrain

	SetCompleteHook(0xE8,0x004DD9C9,&LoadMapName);

	SetCompleteHook(0xE8,0x004E09FA,&LoadMapName);

	SetCompleteHook(0xE8,0x0064A866,&LoadMapName);

	SetCompleteHook(0xE8,0x006D950E,&LoadMapTitle);
}

char* LoadMapName(int index) //OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(index);

	if(lpInfo != 0)
	{
		return lpInfo->MapName;
	}

	return ((char*(*)(int))0x0064A4C0)(index);
}

int LoadMapTitle(char* path,int index,int c,int d,int e,int f) // OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(*(DWORD*)MAIN_CURRENT_MAP);

	if(lpInfo != 0)
	{
		path = lpInfo->TitlePath;
	}

	return ((int(__cdecl*)(char*,int,int,int,int,int))0x006B7D6C)(path,index,c,d,e,f);
}