#include "stdafx.h"
#include "MiniMap.h"
#include "Offset.h"
#include "Util.h"

bool MiniMapTable[MAX_MINI_MAP];

void InitMiniMap() // OK
{
	memset(MiniMapTable,0,sizeof(MiniMapTable));

	//MemorySet(0x0063E7E4,0x90,0x02);

	SetCompleteHook(0xFF,0x006272F0,&MiniMapCore);

	SetCompleteHook(0xE8,0x0081B145,&MiniMapLoad);

	SetCompleteHook(0xFF,0x008192DF,&MiniMapCheck);

	SetCompleteHook(0xFF,0x007C47FD,&MiniMapCheck);
}

void MiniMapCore() // OK
{
	((void(*)())0x006217A2)();

	MiniMapLoad();
}

void MiniMapLoad() // OK
{
	char buff[64];

	wsprintf(buff,"World%d\\Map1.jpg",(*(DWORD*)MAIN_CHARACTER_MAP)+1);

	if(MiniMapFileCheck(*(DWORD*)MAIN_CHARACTER_MAP) != 0)
	{
		MiniMapTable[*(DWORD*)MAIN_CHARACTER_MAP] = 1;
		((int(__cdecl*)(char*,int,int,int,int,int))0x00787BE2)(buff,0x7B7A,0x2601,0x2900,1,0);
	}
}

bool MiniMapCheck(int map) // OK
{
	if(MiniMapTable[map] != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool MiniMapFileCheck(int map) // OK
{
	char buff[64];

	wsprintf(buff,".\\Data\\World%d\\Map1.ozj",(map+1));

	FILE* file;

	if(fopen_s(&file,buff,"r") != 0)
	{
		return 0;
	}
	else
	{
		fclose(file);
		return 1;
	}
}
