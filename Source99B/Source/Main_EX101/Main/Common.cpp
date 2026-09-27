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
	SetDword(0x0061F3DA,0xFF); // Fix ServerList Position
	SetDword(0x0061F3E0,0xFF); // Fix ServerList Position
	SetDword(0x0061F431,0x120); // Fix ServerList Position
	SetByte(0x0061F463,0x4C);  // Fix ServerList Position
	SetDword(0x0061F7E0,0xFC); // Fix ServerList Position
	SetDword(0x0061F814,0x16D); // Fix ServerList Position
	SetDword(0x0061F81F,0x1F3); // Fix ServerList Position
	SetDword(0x0061FE1D,0xFF); // Fix ServerList Position
	SetDword(0x0061FE24,0xFF); // Fix ServerList Position
	SetDword(0x0061FE8F,0x118); // Fix ServerList Position
	SetDword(0x0061FE9E,0x127); // Fix ServerList Position
	SetDword(0x0061FEC7,0x127); // Fix ServerList Position
	SetDword(0x0061FE8F,0x11D); // Fix ServerList Position
	SetDword(0x0061FF12,0x3F700000); // Fix ServerList Position
	SetDword(0x006201B7,0x3F700000); // Fix ServerList Position
	SetDword(0x006201D6,0x43B68000); // Fix ServerList Position
	SetDword(0x00620251,0x1B0); // Fix ServerList Position
	SetFloat(0x006A9788,383.0f); // Fix ServerList Position
	SetByte(0x42FB81,0xEB); // Slide Bug
	SetByte(0x42FB82,0x41); // Slide Bug
	SetByte(0x42FB83,0x90); // Slide Bug
	SetByte(0x42FB84,0x90); // Slide Bug
	SetByte(0x42FB85,0x90); // Slide Bug
	SetByte(0x42FB86,0x90); // Slide Bug
	SetByte(0x42FB87,0x90); // Slide Bug

	SetCompleteHook(0xE8,0x0062814C,&CalcFPS);

	SetCompleteHook(0xE9,0x00623441,&CharacterDeleteLevel);

	SetCompleteHook(0xE9,0x00628F99,&CheckTickCount);

	SetCompleteHook(0xE9,0x00573F6B,&SkillIndex1);

	SetCompleteHook(0xE9,0x0057CCC4,&SkillIndex2);

	SetCompleteHook(0xE9,0x0057DA42,&SkillIndex3);

	SetCompleteHook(0xE9,0x0057F7E3,&SkillIndex4);

	SetCompleteHook(0xE9,0x005812ED,&SkillIndex5);
}

void CalcFPS() // OK
{
	((void(*)())0x004E3B20)();

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

		if(*(BYTE*)(pMouseRButton))
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

void __declspec(naked) CharacterDeleteLevel()
{
	static DWORD ChangeDeleteLevelAddress1 = 0x00623449;

	_asm
	{
		Mov Ax,CharacterDeleteMaxLevel
		Cmp Word Ptr Ss:[Edi+0x1C6],Ax
		Jmp [ChangeDeleteLevelAddress1]
	}
}

void __declspec(naked) CheckTickCount() // OK
{
	static DWORD CheckTickCountAddress1 = 0x00628F9F;

	_asm
	{
		Push 0x01
		Call Dword Ptr Ds:[Sleep]
		Call Dword Ptr Ds:[GetTickCount]
		Jmp[CheckTickCountAddress1]
	}
}

void __declspec(naked) SkillIndex1() // OK
{
	static DWORD SkillIndexAddress1 = 0x00573F70;

	_asm
	{
		Cmp Byte Ptr Ds:[pMouseLButton],0x00
		Je EXIT
		Mov Byte Ptr Ds:[pMouseRButton],0x00
		Jmp EXIT
		EXIT:
		Mov Eax,Dword Ptr Ss:[MAIN_VIEWPORT_STRUCT]
		Jmp[SkillIndexAddress1]
	}
}

void __declspec(naked) SkillIndex2() // OK
{
	static DWORD SkillIndexAddress1 = 0x0057CCCD;

	_asm
	{
		Cmp Byte Ptr Ds:[pMouseLButton],0x00
		Je EXIT
		Mov Byte Ptr Ds:[pMouseRButton],0x00
		Jmp EXIT
		EXIT:
		Mov Eax,Dword Ptr Ss:[Ebp+0x08]
		Cmp Word Ptr Ds:[Eax+0x02],0x1FB
		Jmp[SkillIndexAddress1]
	}
}

void __declspec(naked) SkillIndex3() // OK
{
	static DWORD SkillIndexAddress1 = 0x0057DA4B;

	_asm
	{
		Cmp Byte Ptr Ds:[pMouseLButton],0x00
		Je EXIT
		Mov Byte Ptr Ds:[pMouseRButton],0x00
		Jmp EXIT
		EXIT:
		Mov Ecx,Dword Ptr Ss:[Ebp+0x08]
		Cmp Word Ptr Ds:[Ecx+0x02],0x1FB
		Jmp[SkillIndexAddress1]
	}
}

void __declspec(naked) SkillIndex4() // OK
{
	static DWORD SkillIndexAddress1 = 0x0057F7E9;

	_asm
	{
		Cmp Byte Ptr Ds:[pMouseLButton],0x00
		Je EXIT
		Mov Byte Ptr Ds:[pMouseRButton],0x00
		Jmp EXIT
		EXIT:
		Cmp Word Ptr Ds:[Esi+0x02],0x1FB
		Jmp[SkillIndexAddress1]
	}
}

void __declspec(naked) SkillIndex5() // OK
{
	static DWORD SkillIndexAddress1 = 0x005812F3;

	_asm
	{
		Cmp Byte Ptr Ds:[pMouseLButton],0x00
		Je EXIT
		Mov Byte Ptr Ds:[pMouseRButton],0x00
		Jmp EXIT
		EXIT:
		Cmp Word Ptr Ds:[Esi+0x02],0x1FB
		Jmp[SkillIndexAddress1]
	}
}