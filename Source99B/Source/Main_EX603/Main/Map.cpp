#include "stdafx.h"
#include "Map.h"
#include "CustomMap.h"
#include "Offset.h"
#include "Util.h"

void InitMap()  // OK
{
	SetByte(0x0062EBF8,0xEB); // Check .map files
	
	SetByte(0x0062EBFE,0xEB); // Check .map files
	
	SetByte(0x0062EE42,0xEB); // Check .att files
	
	SetByte(0x0062EE48,0xEB); // Check .att files
	
	SetByte(0x0062EEE5,0xEB); // Check .obj files
	
	SetByte(0x0062EEEB,0xEB); // Check .obj files
	
	SetByte(0x0062EBF7,0x69); // Increase terrain
	
	SetByte(0x0062EE41,0x69); // Increase terrain
	
	SetByte(0x0062EEE4,0x69); // Increase terrain

	SetCompleteHook(0xE8,0x00520ECF,&LoadMapName);
	
	SetCompleteHook(0xE8,0x00520F1F,&LoadMapName);
	
	SetCompleteHook(0xE8,0x0063E743,&LoadMapName);
	
	SetCompleteHook(0xE8,0x00640EB2,&LoadMapName);
	
	SetCompleteHook(0xE8,0x007D2DD9,&LoadMapName);
	
	SetCompleteHook(0xE8,0x007E6C0F,&LoadMapName);
	
	SetCompleteHook(0xE8,0x0084AEF7,&LoadMapName);

	SetCompleteHook(0xE8,0x0047FE12,&LoadMapTitle);
}

char* LoadMapName(int index) //OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(index);

	if(lpInfo != 0)
	{
		return lpInfo->MapName;
	}

	return ((char*(*)(int))0x005D2C10)(index);
}

int LoadMapTitle(char* path,int index,int c,int d,int e,int f) // OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(*(DWORD*)MAIN_CURRENT_MAP);

	if(lpInfo != 0)
	{
		path = lpInfo->TitlePath;
	}

	return ((int(__cdecl*)(char*,int,int,int,int,int))0x00772330)(path,index,c,d,e,f);
}