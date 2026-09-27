#include "stdafx.h"
#include "MiniMap.h"
#include "Offset.h"
#include "Util.h"

bool MiniMapTable[MAX_MINI_MAP];

void InitMiniMap() // OK
{
	memset(MiniMapTable,0,sizeof(MiniMapTable));

	MemorySet(0x0063E7E4,0x90,0x02);

	SetCompleteHook(0xFF,0x0062EB26,&MiniMapCore);

	SetCompleteHook(0xE8,0x00888D5F,&MiniMapLoad);

	SetCompleteHook(0xFF,0x00886CD7,&MiniMapCheck);

	SetCompleteHook(0xFF,0x007D3CBD,&MiniMapCheck);
}

void MiniMapCore() // OK
{
	((void(*)())0x00629180)();

	MiniMapLoad();
}

void MiniMapLoad() // OK
{
	char buff[64];

	wsprintf(buff,"World%d\\Map1.jpg",(*(DWORD*)MAIN_CURRENT_MAP)+1);

	if(MiniMapFileCheck(*(DWORD*)MAIN_CURRENT_MAP) != 0)
	{
		MiniMapTable[*(DWORD*)MAIN_CURRENT_MAP]=1;
		((int(__cdecl*)(char*,int,int,int,int,int))0x00772330)(buff,0x7B7A,0x2601,0x2900,1,0);
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
