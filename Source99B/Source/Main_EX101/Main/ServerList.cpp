#include "stdafx.h"
#include "ServerList.h"
#include "Offset.h"
#include "Util.h"

int ServerCode = -1;
char ServerName[32][400];

void InitServerList() // OK
{
	SetByte(0x0061FC58,0xEB);

	SetByte(0x0061FCFD,0x50);

	MemorySet(0x0061FCD2,0x90,0x26);

	SetCompleteHook(0xE8,0x0061FD79,&PrintServerName1); // ServerList

	SetCompleteHook(0xE8,0x005DCE0A,&PrintServerName2); // CharInfo

	SetCompleteHook(0xE8,0x0045C895,&PrintServerName3); // Friend
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