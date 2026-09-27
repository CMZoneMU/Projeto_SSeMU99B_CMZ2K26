#include "stdafx.h"
#include "ServerList.h"
#include "Offset.h"
#include "Util.h"

int ServerCode = -1;
char ServerName[32][400];

void InitServerList() // OK
{
	MemorySet(0x006C4B72,0x90,0x0E);

	SetCompleteHook(0xE9,0x006C4CAA,&PrintServerCode);

	SetCompleteHook(0xE8,0x006C4CC4,&PrintServerName1); // ServerList

	SetCompleteHook(0xE8,0x006C0CAB,&PrintServerName2); // LoginBox

	SetCompleteHook(0xE8,0x006C0CD8,&PrintServerName2); // LoginBox

	SetCompleteHook(0xE8,0x00647163,&PrintServerName2); // CharInfo

	SetCompleteHook(0xE8,0x0047BD7F,&PrintServerName3); // Friend
}

__declspec(naked) void PrintServerCode() // OK
{
	static DWORD PrintServerCodeAddress1 = 0x006C4CB1;

	_asm
	{
		Mov Edx,[Ebp-0xB0]
		Imul Edx,0x1A
		Mov Eax,[Ebp-0x8C]
		Xor Ecx,Ecx
		Mov Cx,[Eax+Edx+0x2C]
		Mov Eax,Ecx
		Push Eax
		Jmp[PrintServerCodeAddress1]
	}
}

void PrintServerName1(char* a,char* b,char* c,DWORD d) // OK
{
	wsprintf(a,"%s",ServerName[d]);
}

void PrintServerName2(char* a,char* b,char* c,DWORD d) // OK
{
	wsprintf(a,"%s",ServerName[ServerCode]);
}

void PrintServerName3(char* a,char* b,DWORD c) // OK
{
	wsprintf(a,"%s",ServerName[c-1]);
}