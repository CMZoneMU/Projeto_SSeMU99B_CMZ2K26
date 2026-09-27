#pragma	once

#define	MAIN_WINDOW				0x05792778
#define	MAIN_CONNECTION_STATUS	0x05796B50
#define	MAIN_SCREEN_STATE		0x00708760
#define	MAIN_CHARACTER_STRUCT	0x076C1D90
#define	MAIN_VIEWPORT_STRUCT	0x07469838
#define	MAIN_PACKET_SERIAL		0x05796B4B
#define	MAIN_FONT_SIZE			0x077DDFF8
#define	MAIN_RESOLUTION			0x05792568
#define	MAIN_RESOLUTION_X		0x007086F8
#define	MAIN_RESOLUTION_Y		0x007086FC
#define	MAIN_PARTY_MEMBER_COUNT	0x0793F560
#define	MAIN_CURRENT_MAP		0x006FB604
#define	MAIN_HOOK_RECV			0x006E8588
#define	MAIN_HOOK_SEND			0x006E8598
#define MAIN_ACTIVE_SOCKET		0x057928F8

#define STRUCT_DECRYPT			((void(__thiscall*)(void*,void*))0x00505030)((void*)0x057922F8,*(void**)0x076C1D94);
#define STRUCT_ENCRYPT			((void(__thiscall*)(void*,void*))0x00410410)((void*)0x057922F8,*(void**)0x076C1D94);

#define	ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x004FFE40)
#define	pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x00657250)
#define	pCursorX				*(int*)0x07DCB074
#define	pCursorY				*(int*)0x07DCB070
#define DrawInterfaceText		((void(*)(int,int,char*))0x0065A370)
#define	pDrawText				((char*(__cdecl*)(int,int,char*,int,int,int))0x0057A770)
#define	pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x00658780)
#define	pDrawBigText			((void(*)(float,float,DWORD,float,float))0x006585D0)
#define	pDrawImage				((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x00658840)
#define	pDrawMessage			((int(__cdecl*)(char*,int))0x0057AC00)
#define	pLoadItemModel			((void(*)(int,char*,char*,int))0x00642C00)
#define	pLoadItemTexture		((void(*)(int,char*,int,int,int))0x006427C0)
#define pCheckWindow			((bool(__stdcall*)(int)) 0x00694DD0)
#define pViewportAddress		*(DWORD*)(0x07469834)
#define pPetMixIndex			*(BYTE*)(0x007537A4)
#define pChaosMixIndex			*(DWORD*)(0x07DC1878)

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x0063F080)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x005097D0)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x0056F430)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x00564580))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x00538E60)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x00450A40)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x00531C90)
#define pSettingMonster			((DWORD(*)(int,int))0x005334F0)
#define pSetCharacterScale		((void(*)(DWORD))0x00531D60)

#define pGetTextLine(x)			((char*)(0x076FD0BC+(0x12C*x)))

#define pMouseLButton			*(BYTE*)(0x07DCB0BC)
#define pMouseRButton			*(BYTE*)(0x07DCB0A4)

#define pLoadWaveFile			((void(*)(int,char*,int,int))0x00420950)
#define pSetTextColor			*(DWORD*)0x006FA5F4
#define pSetBGTextColor			*(DWORD*)0x006FA5FC
#define pLoadImageJPG			((int(*)(char*,int,GLint,GLint,int,int))0x00673790)
#define pLoadImageTGA			((int(*)(char*,int,GLint,GLint,int,int))0x00673C20)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x00420BA0)
#define pRenderTipText			((void(*)(int,int,char*))0x0057A930)
#define pCheckMouseIn			((int(__cdecl*)(int,int,int,int,int))0x004724A0)
#define pRenderBitmapRotate		((void(*)(int,float,float,float,float,float))0x006589A0)
#define pSetPlayerStop			((void(*)(DWORD))0x0050FBD0)

#define pglViewport2			((void(*)(int,int,int,int))0x006579B0)
#define pgluPerspective2		((void(*)(float,float,float,float))0x00657060)
#define pGetOpenGLMatrix		((void(*)(LPVOID))0x00657010)
#define pCameraMatrix			(LPVOID*)0x07DCAF38
#define pEnableDepthTest		((void(*)())0x006574F0)
#define pEnableDepthMask		((void(*)())0x00657530)
#define pRenderItem3D			((void(*)(float,float,float,float,int,int,int,int,int))0x00611100)
#define pBeginBitmap			((void(*)())0x00658690)
#define pCameraPosition			(GLfloat*)0x07DCB0CC
#define pVectorIRotate			((int(*)(int,int,int*,int))0x00657120)

#define pFontHDC				*(HDC*)0x05792724
#define pFontNormal				*(HFONT*)0x05792788
#define pFontBold				*(HFONT*)0x0579278C
#define pFontBig				*(HFONT*)0x05792790
#define pFontFixed				*(HFONT*)0x05792794

#define	EnableLightMap			((void(*)())0x00657930)
#define	EnableAlphaBlend		((void(*)())0x00657730)
#define	EnableAlphaBlend2		((void(*)())0x00657830)
#define	EnableAlphaBlendMinus	((void(*)())0x006577B0)
#define	EnableAlphaTest			((void(*)(bool))0x006576A0)
#define	DisableAlphaBlend		((void(*)())0x00657620)

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
};