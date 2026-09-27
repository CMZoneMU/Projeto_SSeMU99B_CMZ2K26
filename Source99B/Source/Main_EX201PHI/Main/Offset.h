#pragma	once

#define	MAIN_WINDOW				0x0583FA28
#define	MAIN_CONNECTION_STATUS	0x05843E2C
#define	MAIN_SCREEN_STATE		0x007B356C
#define	MAIN_CHARACTER_STRUCT	0x077706B0
#define	MAIN_VIEWPORT_STRUCT	0x07516BA0
#define	MAIN_PACKET_SERIAL		0x05843E28
#define	MAIN_FONT_SIZE			0x0788C938
#define	MAIN_RESOLUTION			0x0583F7F0
#define	MAIN_RESOLUTION_X		0x007B34C0
#define	MAIN_RESOLUTION_Y		0x007B34C4
#define	MAIN_PARTY_MEMBER_COUNT	0x079F2610
#define	MAIN_CURRENT_MAP		0x007A2CD4
#define	MAIN_HOOK_RECV			0x007815BC
#define	MAIN_HOOK_SEND			0x007815CC
#define MAIN_ACTIVE_SOCKET		0x0583FBB0
#define CASH_RESOLUTION_X       0x007198C7
#define CASH_RESOLUTION_Y       0x007198D1

#define STRUCT_DECRYPT			((void(__thiscall*)(void*,void*))0x0040BA70)((void*)0x0583F580,*(void**)0x077706B4);
#define STRUCT_ENCRYPT			((void(__thiscall*)(void*,void*))0x0040BB10)((void*)0x0583F580,*(void**)0x077706B4);

#define	ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x004FF880)
#define	pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x00699704)
#define	pCursorX				*(int*)0x07E7E2FC
#define	pCursorY				*(int*)0x07E7E2F8
#define DrawInterfaceText		((void(*)(int,int,char*))0x0069D7A0)
#define	pDrawText				((char*(__cdecl*)(int,int,char*,int,int,int))0x0058CE80)
#define	pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x0069AFE4)
#define	pDrawBigText			((void(*)(float,float,DWORD,float,float))0x0069AE29)
#define	pDrawImage				((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x0069B0C7)
#define	pDrawMessage			((int(__cdecl*)(char*,int))0x0058D330)
#define	pLoadItemModel			((void(*)(int,char*,char*,int))0x0067F1C3)
#define	pLoadItemTexture		((void(*)(int,char*,int,int,int))0x0067ED47)
#define pCheckWindow			((bool(__stdcall*)(int)) 0x006D6D93)
#define pViewportAddress		*(DWORD*)(0x07516B8C)
#define pPetMixIndex			*(BYTE*)(0x008007AC)
#define pChaosMixIndex			*(DWORD*)(0x07E749B0)

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x00678AD2)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x0050ADE9)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x005808B8)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x0056FD81))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x0053A7D0)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x0044FAA6)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x00531BFB)
#define pSettingMonster			((DWORD(*)(int,int))0x00533E57)
#define pSetCharacterScale		((void(*)(DWORD))0x00531D69)

#define pGetTextLine(x)			((char*)(0x077AB9DC+(0x12C*x)))

#define pMouseLButton			*(BYTE*)(0x07E7E354)
#define pMouseRButton			*(BYTE*)(0x07E7E32C)

#define pLoadWaveFile			((void(*)(int,char*,int,int))0x0041FC9D)
#define pSetTextColor			*(DWORD*)0x007A184C
#define pSetBGTextColor			*(DWORD*)0x007A1854
#define pLoadImageJPG			((int(*)(char*,int,GLint,GLint,int,int))0x006B781B)
#define pLoadImageTGA			((int(*)(char*,int,GLint,GLint,int,int))0x006B7D6C)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x00420025)
#define pRenderTipText			((void(*)(int,int,char*))0x0058D040)
#define pCheckMouseIn			((int(__cdecl*)(int,int,int,int,int))0x00475204)
#define pRenderBitmapRotate		((void(*)(int,float,float,float,float,float))0x0069B29C)
#define pSetPlayerStop			((void(*)(DWORD))0x00512AD2)

#define pglViewport2			((void(*)(int,int,int,int))0x00699EB0)
#define pgluPerspective2		((void(*)(float,float,float,float))0x006994A5)
#define pGetOpenGLMatrix		((void(*)(LPVOID))0x0069943A)
#define pCameraMatrix			(LPVOID*)0x07E7E1C0
#define pEnableDepthTest		((void(*)())0x006999A2)
#define pEnableDepthMask		((void(*)())0x006999E6)
#define pRenderItem3D			((void(*)(float,float,float,float,int,int,int,int,int))0x00639A40)
#define pBeginBitmap			((void(*)())0x0069AEE4)
#define pCameraPosition			(GLfloat*)0x07E7E364
#define pVectorIRotate			((int(*)(int,int,int*,int))0x006995A8)

#define pFontHDC				*(HDC*)0x0583F9D0
#define pFontNormal				*(HFONT*)0x0583FA38
#define pFontBold				*(HFONT*)0x0583FA3C
#define pFontBig				*(HFONT*)0x0583FA40
#define pFontFixed				*(HFONT*)0x0583FA44

#define	EnableLightMap			((void(*)())0x00699E24)
#define	EnableAlphaBlend		((void(*)())0x00699BF4)
#define	EnableAlphaBlend2		((void(*)())0x00699D09)
#define	EnableAlphaBlendMinus	((void(*)())0x00699C7D)
#define	EnableAlphaTest			((void(*)(bool))0x00699B59)
#define	DisableAlphaBlend		((void(*)())0x00699ADA)

#define ITEM_BASE_MODEL			582

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
	WINDOWS_REFINERY			= 1 << 27,
	WINDOWS_KANTURU_GATE		= 1 << 28,
	WINDOWS_UNKNOWN_2			= 1 << 29,
	WINDOWS_CHAOS_CARD			= 1 << 30,
};