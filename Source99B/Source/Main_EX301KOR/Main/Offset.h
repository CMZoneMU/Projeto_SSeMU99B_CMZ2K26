#pragma	once

#define	MAIN_WINDOW				0x07AFEE84
#define	MAIN_CONNECTION_STATUS	0x07B06BD0
#define	MAIN_SCREEN_STATE		0x0077EBAC
#define	MAIN_CHARACTER_STRUCT	0x074D2C58
#define	MAIN_VIEWPORT_STRUCT	0x074D2B2C
#define	MAIN_PACKET_SERIAL		0x07B06BCB
#define	MAIN_FONT_SIZE			0x07513340
#define	MAIN_RESOLUTION			0x07AFEC78
#define	MAIN_RESOLUTION_X		0x0077E350
#define	MAIN_RESOLUTION_Y		0x0077E354
#define	MAIN_PARTY_MEMBER_COUNT	0x07672E50
#define	MAIN_CURRENT_MAP		0x0077038C
#define	MAIN_HOOK_RECV			0x007565D4
#define	MAIN_HOOK_SEND			0x007565E4
#define MAIN_ACTIVE_SOCKET		0x07B02978

#define STRUCT_DECRYPT			((void(__thiscall*)(void*,void*))0x0040B3C0)((void*)0x07AFEA08,*(void**)0X074D2C5C);
#define STRUCT_ENCRYPT			((void(__thiscall*)(void*,void*))0x0040B460)((void*)0x07AFEA08,*(void**)0X074D2C5C);

#define	ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x0069C3C0)
#define	pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x00641E33)
#define	pCursorX				*(int*)0x07AFE950
#define	pCursorY				*(int*)0x07AFE94C
#define	pTextThis				((LPVOID(*)())0x0041FD65)
#define	pDrawText				((int(__thiscall*)(LPVOID,int,int,const char*,int,int,int*,int))0x00420024)
#define	pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x006437A7)
#define	pDrawBigText			((void(*)(float,float,DWORD,float,float))0x006435D6)
#define	pDrawImage				((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x006438B4)
#define	pDrawMessage			((int(__cdecl*)(char*,int))0x0053E1B0)
#define	pLoadItemModel			((void(*)(int,char*,char*,int))0x0062B803)
#define	pLoadItemTexture		((void(*)(int,char*,int,int,int))0x0062B387)
#define pCheckWindow			((bool(__stdcall*)(int))0x0045E06F)
#define pViewportAddress		*(DWORD*)(0x074D2B28)
#define pPetMixIndex			*(BYTE*)(0x007C7184)
#define pChaosMixIndex			((DWORD(__thiscall*)(DWORD))0x004EC12D)(0x88*((DWORD(__thiscall*)(DWORD*))0x004ED5D8)(&*(DWORD*)(0x007C5D20))+0x007C5D24)

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x0062392F)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x005020D9)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x006EE878)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x006DA9C1))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x006A7FB0)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x004DB1D6)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x0052B5BE)
#define pSettingMonster			((DWORD(*)(int,int))0x0052D70D)
#define pSetCharacterScale		((void(*)(DWORD))0x0052B72C)

#define pGetTextLine(x)			(((char*(__thiscall*)(void*,int))0x00402260)(((void(*)())0x00750DF88),x))

#define pMouseLButton			*(BYTE*)(0x07AFE998)
#define pMouseRButton			*(BYTE*)(0x07AFE980)

#define pLoadWaveFile			((void(*)(int,char*,int,int))0x006A4C2D)
#define	pSetTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x0041FF35)
#define	pSetBGTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x0041FF97)
#define pLoadImageJPG			((int(*)(char*,int,GLint,GLint,int,int))0x006F9D4F)
#define pLoadImageTGA			((int(*)(char*,int,GLint,GLint,int,int))0x006FA244)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x006A4FB5)
#define pRenderTipText			((void(*)(int,int,char*))0x0053DEB0)
#define pMouseOnZone			((int(__cdecl*)(int,int,int,int,int))0x00416686)
#define pRenderBitmapRotate		((void(*)(int,float,float,float,float,float))0x00643A89)
#define pSetPlayerStop			((void(*)(DWORD))0x00509D09)

#define pglViewport2			((void(*)(int,int,int,int))0x006425DF)
#define pgluPerspective2		((void(*)(float,float,float,float))0x00641BE5)
#define pGetOpenGLMatrix		((void(*)(LPVOID))0x00641B7A)
#define pCameraMatrix			(LPVOID*)0x07AFE814
#define pEnableDepthTest		((void(*)())0x006420D1)
#define pEnableDepthMask		((void(*)())0x00642115)
#define pRenderItem3D			((void(*)(float,float,float,float,int,int,int,int,int))0x005E8790)
#define pBeginBitmap			((void(*)())0x00643691)
#define pUpdateMousePosition	((void(*)())0x006428B5)

#define pGetFontDC				((HDC(__thiscall*)(LPVOID)) 0x0041FE93)
#define pFontNormal				*(HFONT*)0x07AFEE94
#define pFontBold				*(HFONT*)0x07AFEE98
#define pFontBig				*(HFONT*)0x07AFEE9C
#define pFontFixed				*(HFONT*)0x07AFEEA0

#define	EnableLightMap			((void(*)())0x00642553)
#define	EnableAlphaBlend		((void(*)())0x00642323) // pGLSwitchBlend
#define	EnableAlphaBlend2		((void(*)())0x00642438)
#define	EnableAlphaBlendMinus	((void(*)())0x006423AC)
#define	EnableAlphaTest			((void(*)(bool))0x00642288) //pSetBlend
#define	DisableAlphaBlend		((void(*)())0x00642209) // pGLSwitch

#define ITEM_BASE_MODEL			649

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
};