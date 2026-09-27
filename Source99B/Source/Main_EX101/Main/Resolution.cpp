#include "stdafx.h"
#include "Resolution.h"
#include "Offset.h"
#include "Util.h"

float Resolution_ClipX1 = 2000.0f;
float Resolution_ClipX2 = 2000.0f;

void InitResolution() // OK
{
	SetCompleteHook(0xE9,0x004B3AAE,&ResolutionSwitch);

	SetCompleteHook(0xE9,0x004B4D54,&ResolutionSwitchFont);

	SetCompleteHook(0xE9,0x00443154,&ResolutionMoveList);

	SetCompleteHook(0xE9,0x00443B65,&ResolutionMoveList2);
}

__declspec(naked) void ResolutionSwitch() // OK
{
	static DWORD ResolutionSwitchAddress1 = 0x004B3B2A;

	_asm
	{
		Mov Eax,Dword Ptr Ds:[MAIN_RESOLUTION]
		Cmp Eax,0x00
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],640
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],480
		Jmp EXIT
		NEXT1:
		Cmp Eax,0x01
		Jnz NEXT2
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],800
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],600
		Jmp EXIT
		NEXT2:
		Cmp Eax,0x02
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1024
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],768
		Jmp EXIT
		NEXT3:
		Cmp Eax,0x03
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1280
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1024
		Jmp EXIT
		NEXT4:
		Cmp Eax,0x04
		Jnz NEXT5
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1360
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],768
		Jmp EXIT
		NEXT5:
		Cmp Eax,0x05
		Jnz NEXT6
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1440
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],900
		Jmp EXIT
		NEXT6:
		Cmp Eax,0x06
		Jnz NEXT7
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1600
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],900
		Jmp EXIT
		NEXT7:
		Cmp Eax,0x07
		Jnz NEXT8
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1680
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1050
		Jmp EXIT
		NEXT8:
		Cmp Eax,0x08
		Jnz EXIT
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_X],1920
		Mov Dword Ptr Ds:[MAIN_RESOLUTION_Y],1080
		EXIT:
		Jmp [ResolutionSwitchAddress1]
	}
}

__declspec(naked) void ResolutionSwitchFont() // OK
{
	static DWORD ResolutionSwitchFontAddress1 = 0x004B4DCD;

	_asm
	{
		Mov Eax,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Mov Dword Ptr Ss:[Ebp-0x241C],Eax
		Cmp Dword Ptr Ss:[Ebp-0x241C],640
		Jnz NEXT1
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0C
		Jmp EXIT
		NEXT1:
		Cmp Dword Ptr Ss:[Ebp-0x241C],800
		Jnz NEXT2
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0D
		Jmp EXIT
		NEXT2:
		Cmp Dword Ptr Ss:[Ebp-0x241C],1024
		Jnz NEXT3
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0E
		Jmp EXIT
		NEXT3:
		Cmp Dword Ptr Ss:[Ebp-0x241C],1280
		Jnz NEXT4
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F
		Jmp EXIT
		NEXT4:
		Mov Dword Ptr Ds:[MAIN_FONT_SIZE],0x0F
		Push Resolution_ClipX1
		Push 0x006A967C
		Call [SetFloat]
		Add Esp,0x08
		Push Resolution_ClipX2
		Push 0x006A9688
		Call [SetFloat]
		Add Esp,0x08
		EXIT:
		Jmp [ResolutionSwitchFontAddress1]
	}
}

__declspec(naked) void ResolutionMoveList() // OK
{
	static DWORD ResolutionMoveListAddress1 = 0x00443198;
	static DWORD ResolutionMoveListAddress2 = 0x0044315B;

	_asm
	{
		Mov Ecx,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Push Edi
		Mov Dword Ptr Ss:[Ebp-0x58],Esi
		Mov Dword Ptr Ss:[Ebp-0x38],Ebx
		Cmp Ecx,0x500
		Jbe EXIT
		Jmp [ResolutionMoveListAddress1]
		EXIT:
		Jmp [ResolutionMoveListAddress2]
	}
}

__declspec(naked) void ResolutionMoveList2() // OK
{
	static DWORD ResolutionMoveListAddress1 = 0x00443BF8;
	static DWORD ResolutionMoveListAddress2 = 0x00443B6E;

	_asm
	{
		Mov Ecx,Dword Ptr Ds:[MAIN_RESOLUTION_X]
		Cmp Ecx,0x500
		Jbe EXIT
		Jmp [ResolutionMoveListAddress1]
		EXIT:
		Jmp [ResolutionMoveListAddress2]
	}
}