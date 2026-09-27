#include "stdafx.h"
#include "Common.h"
#include "Offset.h"
#include "Protect.h"
#include "Protocol.h"
#include "Util.h"

int CustomAttack;
char WindowName[64];

void InitCommon() // OK
{
	SetCompleteHook(0xE8,0x006CFCFC,&CalcFPS);

	SetCompleteHook(0xE9,0x006D6D64,&CharacterCreationLevel);

	SetCompleteHook(0xE9,0x006D0BF2,&CheckTickCount);
}

void CalcFPS() // OK
{
	((void(*)())0x00513626)();

	if(*(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		if(WindowName[0] == 0)
		{
			SetWindowText(*(HWND*)(MAIN_WINDOW),gProtect.m_MainInfo.WindowName);
		}
		else
		{
			SetWindowText(*(HWND*)(MAIN_WINDOW),WindowName);
		}

		if(pMouseRButton)
		{
			if(CustomAttack != 0)
			{
				CustomAttack = 0;

				PBMSG_HEAD pMsg;

				pMsg.set(0x04,sizeof(pMsg));

				DataSend((BYTE*)&pMsg,pMsg.size);
			}
		}
	}
	else
	{
		CustomAttack = 0;
		WindowName[0] = 0;
		SetWindowText(*(HWND*)(MAIN_WINDOW),gProtect.m_MainInfo.WindowName);
	}
}

__declspec(naked) void CharacterCreationLevel() // OK
{
	static DWORD CheckCreateClassAddress1 = 0x006D6DD5;
	static DWORD CheckCreateClassAddress2 = 0x006D7F90;
	
	_asm
	{
		Push 0x01
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*0+0x270]
		Call[CheckCreateClassAddress2]
		Push 0x01
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*1+0x270]
		Call[CheckCreateClassAddress2]
		Push 0x01
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*2+0x270]
		Call[CheckCreateClassAddress2]
		Movzx Edx,Byte Ptr Ds:[0x07EB504C]
		And Edx,0x04
		Sar Edx,0x02
		Push Edx
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*3+0x270]
		Call[CheckCreateClassAddress2]
		Movzx Edx,Byte Ptr Ds:[0x07EB504C]
		And Edx,0x02
		Sar Edx,0x01
		Push Edx
		Mov Eax,[Ebp-0x0C]
		Lea Ecx,[Eax+0xE0*4+0x270]
		Call[CheckCreateClassAddress2]
		Jmp[CheckCreateClassAddress1]
	}
}

void __declspec(naked) CheckTickCount() // OK
{
	static DWORD CheckTickCountAddress1 = 0x006D0BF8;

	_asm
	{
		Push 1
		Call Dword Ptr Ds:[Sleep]
		Call Dword Ptr Ds:[GetTickCount]
		Jmp[CheckTickCountAddress1]
	}
}