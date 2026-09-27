#pragma once

#define MAX_CHARACTER_LEVEL		0x3E8
#define MAIN_WINDOW				0x011C3E7C
#define MAIN_CONNECTION_STATUS	0x08B159E4
#define MAIN_SCREEN_STATE		0x0118D320
#define MAIN_CHARACTER_MAP		0x0118EDF8
#define MAIN_CHARACTER_STRUCT	0x08499DCC
#define MAIN_VIEWPORT_STRUCT	0x07F05CAC
#define MAIN_PACKET_SERIAL		0x08B159E0
#define MAIN_HELPER_STRUCT		0x011C4494
#define MAIN_FONT_SIZE			0x08531688
#define MAIN_RESOLUTION			0x011C3B38
#define MAIN_RESOLUTION_X		0x0118EE38
#define MAIN_RESOLUTION_Y		0x0118EE3C
#define MAIN_ACTIVE_SOCKET		0x08B15A70

#define ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x0A425DAA)
#define DrawInterface			((void(*)(DWORD,float,float,float,float))0x00799791)
#define DrawInterfaceText		((void(*)(char*,int,int,int,int,int,float,int))0x007FF712)
#define pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x00630F0A)
#define pSetBlend				((void(__cdecl*)(BYTE))0x0062F75B)
#define pGLSwitchBlend			((void(__cdecl*)())0x0062F7F0)
#define pGLSwitch				((void(__cdecl*)())0x0062F6E1)
#define pDrawMessage			((int(__cdecl*)(LPCSTR,int))0x0059CDA0)
#define pLoadItemModel			((void(*)(int,char*,char*,int))0x006112F7)
#define pLoadItemTexture		((void(*)(int,char*,int,int,int))0x00610D61)
#define pChaosMixIndex			((DWORD(__thiscall*)(DWORD*))0x007A654F)(&*(DWORD*)(0x011FC4C0))

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x006055EC)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x00549F06)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x00786D35)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x0075CCB9))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x006D5DD0)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x008A875F)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x005884B2)
#define pSettingMonster			((DWORD(*)(int,int))0x00589FD1)
#define pSetCharacterScale		((void(*)(DWORD))0x005885E5)

#define pGetTextLine(x)			(((char*(__thiscall*)(void*,int))0x00436D31)(((void(*)())0x008499DE0),x))

#define pMouseLButton			*(BYTE*)(0x08B15636)
#define pMouseRButton			*(BYTE*)(0x08B15633)