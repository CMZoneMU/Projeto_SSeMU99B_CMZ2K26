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
	SetCompleteHook(0xE8,0x0066F55C,&CalcFPS);

	SetCompleteHook(0xE9,0x006756D7,&CharacterCreationLevel);

	SetCompleteHook(0xE9,0x00676D7B,&CharacterDeleteLevel);

	SetCompleteHook(0xE9,0x00670405,&CheckTickCount);
}

void CalcFPS() // OK
{
	((void(*)())0x00508CE0)();

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
	static DWORD CheckCreateClassAddress1 = 0x0067572C;
	
	_asm
	{
		Lea Ecx,[Esi+0xE0*0+0x318]
		Mov Byte Ptr Ds:[Ecx],1
		Lea Ecx,[Esi+0xE0*1+0x318]
		Mov Byte Ptr Ds:[Ecx],1
		Lea Ecx,[Esi+0xE0*2+0x318]
		Mov Byte Ptr Ds:[Ecx],1
		Mov Dl,Byte Ptr Ds:[0x07DCE94C]
		And Dl,0x04
		Sar Dl,0x02
		Lea Ecx,[Esi+0xE0*3+0x318]
		Mov Byte Ptr Ds:[Ecx],Dl
		Mov Dl,Byte Ptr Ds:[0x07DCE94C]
		And Dl,0x02
		Sar Dl,0x01
		Lea Ecx,[Esi+0xE0*4+0x318]
		Mov Byte Ptr Ds:[Ecx],Dl
		Jmp[CheckCreateClassAddress1]
	}
}

void __declspec(naked) CharacterDeleteLevel()
{
	static DWORD ChangeDeleteLevelAddress1 = 0x00676D84;

	_asm
	{
		Mov Cx,CharacterDeleteMaxLevel
		Cmp Word Ptr Ss:[Eax+0x20A],Cx
		Jmp [ChangeDeleteLevelAddress1]
	}
}

void __declspec(naked) CheckTickCount() // OK
{
	static DWORD CheckTickCountAddress1 = 0x0067040B;

	_asm
	{
		Push 1
		Call Dword Ptr Ds:[Sleep]
		Call Dword Ptr Ds:[GetTickCount]
		Jmp[CheckTickCountAddress1]
	}
}