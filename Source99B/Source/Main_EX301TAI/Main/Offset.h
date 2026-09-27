#pragma once

#define MAIN_WINDOW				0x05875E10
#define MAIN_CONNECTION_STATUS	0x0587A21C
#define MAIN_SCREEN_STATE		0x007E5ED0
#define MAIN_CHARACTER_STRUCT	0x077A6E48
#define MAIN_VIEWPORT_STRUCT	0x0754D340
#define MAIN_PACKET_SERIAL		0x0587A218
#define MAIN_FONT_SIZE			0x078C30D0
#define MAIN_RESOLUTION			0x05875BD8
#define MAIN_RESOLUTION_X		0x007E5E24
#define MAIN_RESOLUTION_Y		0x007E5E28
#define MAIN_PARTY_MEMBER_COUNT	0x07A25978
#define MAIN_CURRENT_MAP		0x007D4010
#define MAIN_HOOK_RECV			0x007B15BC
#define MAIN_HOOK_SEND			0x007B15CC
#define MAIN_ACTIVE_SOCKET		0x05875FA0
#define CASH_RESOLUTION_X       0x0072DF47
#define CASH_RESOLUTION_Y       0x0072DF51

#define STRUCT_DECRYPT			((void(__thiscall*)(void*,void*))0x0040BD60)((void*)0x05875968,*(void**)0X077A6E4C);
#define STRUCT_ENCRYPT			((void(__thiscall*)(void*,void*))0x0040BE20)((void*)0x05875968,*(void**)0X077A6E4C);

#define ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x00509C50)
#define pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x006B64F4)
#define pCursorX				*(int*)0x07EB164C
#define pCursorY				*(int*)0x07EB1648
#define DrawInterfaceText		((void(*)(int,int,char*))0x006BA590)
#define pDrawText				((char*(__cdecl*)(int,int,char*,int,int,int))0x0059FD10)
#define pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x006B7DD4)
#define pDrawBigText			((void(*)(float,float,DWORD,float,float))0x006B7C19)
#define pDrawImage              ((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x006B7EB7)
#define pDrawMessage			((int(__cdecl*)(char*,int))0x005A01C0)
#define pLoadItemModel			((void(*)(int,char*,char*,int))0x0069A213)
#define pLoadItemTexture		((void(*)(int,char*,int,int,int))0x00699D97)
#define pCheckWindow			((bool(__stdcall*)(int))0x006F43B6)
#define pViewportAddress		*(DWORD*)(0x0754D32C)
#define pPetMixIndex			*(BYTE*)(0x00836B84)
#define pChaosMixIndex			((DWORD(__thiscall*)(DWORD))0x00465305)(0x90*((DWORD(__thiscall*)(DWORD*))0x0046681D)(&*(DWORD*)(0x008351B8))+0x008351BC)

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x00692362)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x005155B9)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x00592E28)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x0057EB91))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x00547780)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x00453896)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x0053E2E7)
#define pSettingMonster			((DWORD(*)(int,int))0x0054043D)
#define pSetCharacterScale		((void(*)(DWORD))0x0053E455)

#define pGetTextLine(x)			((char*)(0x077E2174+(0x12C*x)))

#define pMouseLButton			*(BYTE*)(0x07EB16A4)
#define pMouseRButton			*(BYTE*)(0x07EB167C)

#define pLoadWaveFile			((void(*)(int,char*,int,int))0x004204ED)
#define pSetTextColor			*(DWORD*)0x007D2BD0
#define pSetBGTextColor			*(DWORD*)0x007D2BD8
#define pLoadImageJPG			((int(*)(char*,int,GLint,GLint,int,int))0x006D42FB)
#define pLoadImageTGA			((int(*)(char*,int,GLint,GLint,int,int))0x006D484C)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x00420875)
#define pRenderTipText			((void(*)(int,int,char*))0x0059FED0)
#define pMouseOnZone			((int(__cdecl*)(int,int,int,int,int))0x0047CAB4)
#define pRenderBitmapRotate		((void(*)(int,float,float,float,float,float))0x006B808C)
#define pSetPlayerStop			((void(*)(DWORD))0x0051D2B9)

#define pglViewport2			((void(*)(int,int,int,int))0x006B6CA0)
#define pgluPerspective2		((void(*)(float,float,float,float))0x006B6295)
#define pGetOpenGLMatrix		((void(*)(LPVOID))0x006B622A)
#define pCameraMatrix			(LPVOID*)0x07EB1510
#define pEnableDepthTest		((void(*)())0x006B6792)
#define pEnableDepthMask		((void(*)())0x006B67D6)
#define pRenderItem3D			((void(*)(float,float,float,float,int,int,int,int,int))0x00650080)
#define pBeginBitmap			((void(*)())0x006B7CD4)
#define pCameraPosition			(GLfloat*)0x07EB16B4
#define pVectorIRotate			((int(*)(int,int,int*,int))0x006B6398)

#define pFontHDC				*(HDC*)0x05875DB8
#define pFontNormal				*(HFONT*)0x05875E20
#define pFontBold				*(HFONT*)0x05875E24
#define pFontBig				*(HFONT*)0x05875E28
#define pFontFixed				*(HFONT*)0x05875E2C

#define	EnableLightMap			((void(*)())0x006B6C14)
#define	EnableAlphaBlend		((void(*)())0x006B69E4)
#define	EnableAlphaBlend2		((void(*)())0x006B6AF9)
#define	EnableAlphaBlendMinus	((void(*)())0x006B6A6D)
#define	EnableAlphaTest			((void(*)(bool))0x006B6949)
#define	DisableAlphaBlend		((void(*)())0x006B68CA)

#define ITEM_BASE_MODEL			634

#define GET_ITEM(x,y)			(((x)*512)+(y))
#define GET_ITEM_MODEL(x,y)		((((x)*512)+(y))+ITEM_BASE_MODEL)
#define GET_ITEM_OPT_LEVEL(x)	((x>>3)&15)
#define GET_ITEM_OPT_EXC(x)		((x)-(x&64))
#define GET_MAX_WORD_VALUE(x)	(((x)>65000)?65000:((WORD)(x)))

enum eWindowsType
{
	WINDOWS_NONE				= 0,
	WINDOWS_FRIEND_LIST			= 1,
	WINDOWS_MOVE_LIST			= 2,
	WINDOWS_PARTY				= 3,
	WINDOWS_QUEST				= 4,
	WINDOWS_GUILD				= 5,
	WINDOWS_TRADE				= 6,
	WINDOWS_WAREHOUSE			= 7,
	WINDOWS_UNKNOWN_1			= 8,
	WINDOWS_CHAOS_MIX			= 9,
	WINDOWS_COMMAND				= 10,
	WINDOWS_PET					= 11,
	WINDOWS_STORE				= 12,
	WINDOWS_DEVIL_SQUARE		= 13,
	WINDOWS_MOVING_SERVER		= 14,
	WINDOWS_BLOOD_CASTLE		= 15,
	WINDOWS_PET_TRAINER			= 16,
	WINDOWS_SHOP				= 17,
	WINDOWS_STORE_OTHER			= 18,
	WINDOWS_GUILD_MASTER		= 19,
	WINDOWS_GUARDMAN_SIEGUE		= 20,
	WINDOWS_SENIOR_MIX			= 21,
	WINDOWS_GUARDMAN_LAND		= 22,
	WINDOWS_CATAPULT_INVADING	= 23,
	WINDOWS_CATAPULT_DEFENDING	= 24,
	WINDOWS_CASTLE_GATE_SWITCH	= 25,
	WINDOWS_CHARACTER			= 26,
	WINDOWS_INVENTORY			= 27,
	WINDOWS_REFINERY			= 28,
	WINDOWS_REFINERY_WARNING	= 29,
	WINDOWS_KANTURU_GATE		= 30,
	WINDOWS_WEREWOLF			= 31,
	WINDOWS_ILLUSION_TEMPLE1	= 32,
	WINDOWS_ILLUSION_TEMPLE2	= 34,
	WINDOWS_CHAOS_CARD			= 35,
};