#include "stdafx.h"
#include "Map.h"
#include "CustomMap.h"
#include "Offset.h"
#include "Util.h"

void InitMap()  // OK
{
	SetByte(0x00627499,0xEB); // Check .map files
	
	SetByte(0x0062749F,0xEB); // Check .map files
	
	SetByte(0x006276C6,0xEB); // Check .att files
	
	SetByte(0x006276CC,0xEB); // Check .att files
	
	SetByte(0x00627763,0xEB); // Check .obj files
	
	SetByte(0x00627769,0xEB); // Check .obj files
	
	SetByte(0x00627498,0x69); // Increase terrain
	
	SetByte(0x006276C5,0x69); // Increase terrain
	
	SetByte(0x00627762,0x69); // Increase terrain

	SetCompleteHook(0xE8,0x0052AA39,&LoadMapName);
	
	SetCompleteHook(0xE8,0x0052AA80,&LoadMapName);
	
	SetCompleteHook(0xE8,0x00639C8D,&LoadMapName);
	
	SetCompleteHook(0xE8,0x007C35AB,&LoadMapName);
	
	SetCompleteHook(0xE8,0x007D230F,&LoadMapName);
	
	SetCompleteHook(0xE8,0x0099170C,&LoadMapName);
	
	SetCompleteHook(0xE8,0x00998A14,&LoadTitleName);
}

char* LoadMapName(int index) //OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(index);

	if(lpInfo != 0)
	{
		return lpInfo->MapName;
	}

	return ((char*(*)(int))0x005C8392)(index);
}

char* LoadTitleName(int index) // OK
{
	CUSTOM_MAP_INFO* lpInfo = gCustomMap.GetInfoByNumber(index);

	if(lpInfo != 0)
	{
		return lpInfo->TitlePath;
	}

	return ((char*(*)(int))0x005C8392)(index);
}