#pragma once

#define MAIN_WINDOW				0x0575052C
#define MAIN_CONNECTION_STATUS	0x057548F8
#define MAIN_SCREEN_STATE		0x006C41C0
#define MAIN_CHARACTER_STRUCT	0x07666A78
#define MAIN_VIEWPORT_STRUCT	0x0742464C
#define MAIN_PACKET_SERIAL		0x057548F3
#define MAIN_FONT_SIZE			0x0773D130
#define MAIN_RESOLUTION			0x05750320
#define MAIN_RESOLUTION_X		0x006C4158
#define MAIN_RESOLUTION_Y		0x006C415C
#define MAIN_PARTY_MEMBER_COUNT	0x0788C768
#define MAIN_CURRENT_MAP		0x006B8D48
#define MAIN_HOOK_RECV			0x006A7574
#define MAIN_HOOK_SEND			0x006A7584
#define MAIN_ACTIVE_SOCKET		0x057506A0

#define STRUCT_DECRYPT			((void(__thiscall*)(void*,void*))0x004E02C0)((void*)0x057500B0,*(void**)0x07666A7C);
#define STRUCT_ENCRYPT			((void(__thiscall*)(void*,void*))0x0040D830)((void*)0x057500B0,*(void**)0x07666A7C);

#define ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x004DB720)
#define pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x0060C740)
#define pCursorX				*(int*)0x07D1715C
#define pCursorY				*(int*)0x07D17158
#define DrawInterfaceText		((void(*)(int,int,char*))0x0060FAC0)
#define pDrawText				((char*(__cdecl*)(int,int,char*,int,int,int))0x00548620)
#define pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x0060DC30)
#define pDrawBigText    		((void(*)(float,float,DWORD,float,float))0x0060DA80)
#define pDrawImage              ((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x0060DCF0)
#define pDrawMessage			((int(__cdecl*)(char*,int))0x00548AB0)
#define pLoadItemModel			((void(*)(int,char*,char*,int))0x005FACA0)
#define pLoadItemTexture		((void(*)(int,char*,int,int,int))0x005FA860)
#define pCheckWindow			((bool(__stdcall*)(int)) 0x00648BB0)
#define pViewportAddress		*(DWORD*)(0x07424644)
#define pPetMixIndex			*(BYTE*)(0x00711564)
#define pChaosMixIndex			*(DWORD*)(0x07D0E998)

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x005F8640)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x004E4610)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x0053DE20)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x005353B0))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x0050F3E0)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x00434E60)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x00509410)
#define pSettingMonster			((DWORD(*)(int,int))0x0050ABB0)
#define pSetCharacterScale		((void(*)(DWORD))0x005094D0)
#define pLoadWaveFile			((void(*)(int,char*,int,int))0x0041CF50)
#define pSetMonsterSound		((void(*)(int,int,int,int,int,int,int,int,int,int,int))0x005FFB00)

#define pGetTextLine(x)			((char*)(0x076A1DA4+(0x12C*x)))
#define pGetItemName(x)			((char*)(*(DWORD*)(0x0773D118)+0x50*x))

#define pMouseLButton			0x07D171A4
#define pMouseRButton			0x07D1718C

#define pSetTextColor			*(DWORD*)0x006B7DF0
#define pSetBGTextColor			*(DWORD*)0x006B7DF8
#define pLoadImageJPG			((int(*)(char*,int,GLint,GLint,int,int))0x0062C1E0)
#define pLoadImageTGA			((int(*)(char*,int,GLint,GLint,int,int))0x0062C670)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x0041D1A0)
#define pRenderTipText			((void(*)(int,int,char*))0x005487E0)
#define pCheckMouseIn			((BOOL(__cdecl*)(int,int,int,int,int))0x00454A00)
#define pRenderBitmapRotate     ((void(*)(int,float,float,float,float,float))0x0060DE00)
#define pSetPlayerStop			((void(*)(DWORD))0x004EA700)

#define pglViewport2			((void(*)(int,int,int,int))0x0060CEA0)
#define pgluPerspective2		((void(*)(float,float,float,float))0x0060C550)
#define pGetOpenGLMatrix		((void(*)(LPVOID))0x060C500)
#define pCameraMatrix			(LPVOID*)0x07D17020
#define pEnableDepthTest		((void(*)())0x0060C9E0)
#define pEnableDepthMask		((void(*)())0x0060CA20)
#define pRenderItem3D			((void(*)(float,float,float,float,int,int,int,int,int))0x005CFD10)
#define pBeginBitmap			((void(*)())0x0060DB40)
#define pCameraPosition			(GLfloat*)0x07D171B4
#define pVectorIRotate			((int(*)(int,int,int*,int))0x0060C610)

#define pFontHDC				*(HDC*)0x057504DC
#define pFontNormal				*(HFONT*)0x0575053C
#define pFontBold				*(HFONT*)0x05750540
#define pFontBig				*(HFONT*)0x05750544

#define	EnableLightMap			((void(*)())0x0060CE20)
#define	EnableAlphaBlend		((void(*)())0x0060CC20)
#define	EnableAlphaBlend2		((void(*)())0x0060CD20)
#define	EnableAlphaBlendMinus	((void(*)())0x0060CCA0)
#define	EnableAlphaTest			((void(*)(bool))0x0060CB90)
#define	DisableAlphaBlend		((void(*)())0x0060CB10)

#define pLockInterfaces			*(BYTE*)(0x0575491C) //99b 568C55C (buscar aMenuExitGame_)

#define ITEM_BASE_MODEL			515

#define GET_ITEM(x,y)			(((x)*512)+(y))
#define GET_ITEM_MODEL(x,y)		((((x)*512)+(y))+ITEM_BASE_MODEL)
#define GET_ITEM_OPT_LEVEL(x)	((x>>3)&15)
#define GET_ITEM_OPT_EXC(x)		((x)-(x&64))
#define GET_MAX_WORD_VALUE(x)	(((x)>65000)?65000:((WORD)(x)))

enum eWindowsType
{
	WINDOWS_NONE				= 0 << 0,
	WINDOWS_FRIEND				= 1 << 0,
	WINDOWS_MOVE_LIST			= 1 << 1,
	WINDOWS_PARTY				= 1 << 2,
	WINDOWS_QUEST				= 1 << 3,
	WINDOWS_GUILD				= 1 << 4,
	WINDOWS_TRADE				= 1 << 5,
	WINDOWS_WAREHOUSE			= 1 << 6,
	WINDOWS_UNKNOWN_1			= 1 << 7,
	WINDOWS_CHAOS_MIX			= 1 << 8,
	WINDOWS_COMMAND				= 1 << 9,
	WINDOWS_PET					= 1 << 10,
	WINDOWS_STORE				= 1 << 11,
	WINDOWS_DEVIL_SQUARE		= 1 << 12,
	WINDOWS_MOVING_SERVER		= 1 << 13,
	WINDOWS_BLOOD_CASTLE		= 1 << 14,
	WINDOWS_PET_TRAINER			= 1 << 15,
	WINDOWS_SHOP				= 1 << 16,
	WINDOWS_STOREOTHER			= 1 << 17,
	WINDOWS_GUILD_MASTER		= 1 << 18,
	WINDOWS_GUARDMAN_SIEGUE		= 1 << 19,
	WINDOWS_SENIOR_MIX			= 1 << 20,
	WINDOWS_GUARDMAN_LAND		= 1 << 21,
	WINDOWS_CATAPULT_INVADING	= 1 << 22,
	WINDOWS_CATAPULT_DEFENDING	= 1 << 23,
	WINDOWS_CASTLE_GATE_SWITCH  = 1 << 24,
	WINDOWS_CHARACTER			= 1 << 25,
	WINDOWS_INVENTORY			= 1 << 26,
};