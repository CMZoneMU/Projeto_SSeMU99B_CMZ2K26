#pragma	once

#define	MAIN_WINDOW				0x07FE06F4
#define	MAIN_CONNECTION_STATUS	0x07FE8E38
#define	MAIN_SCREEN_STATE		0x00853434
#define	MAIN_CHARACTER_STRUCT	0x079FAE60
#define	MAIN_VIEWPORT_STRUCT	0x079B9D48
#define	MAIN_PACKET_SERIAL		0x07FE8E33
#define	MAIN_FONT_SIZE			0x079FAE78
#define	MAIN_RESOLUTION			0x07FE0520
#define	MAIN_RESOLUTION_X		0x00852B98
#define	MAIN_RESOLUTION_Y		0x00852B9C
#define	MAIN_PARTY_MEMBER_COUNT	0x07B55338
#define	MAIN_CURRENT_MAP		0x0084253C
#define	MAIN_HOOK_RECV			0x008125E8
#define	MAIN_HOOK_SEND			0x008125F8
#define MAIN_ACTIVE_SOCKET		0x07FE4BC0

#define DrawInterface			((void(*)(DWORD,float,float,float,float))0x006E26E3)
#define DrawInterfaceText		((void(*)(char*,int,int,int,int,int,int,int))0x0070EF47)
#define	ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x0062C170)
#define	pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x005DEF20)
#define	pCursorX				*(int*)0x07FE0218
#define	pCursorY				*(int*)0x07FE0214
#define	pTextThis				((LPVOID(*)())0x0041D732)
#define	pDrawText				((int(__thiscall*)(LPVOID,int,int,char*,int,int,int*,int))0x0041D9F1)
#define	pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x005E093C)
#define	pDrawBigText			((void(*)(float,float,DWORD,float,float))0x005E0768)
#define	pDrawImage				((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x005E0C03)
#define	pDrawMessage			((int(__cdecl*)(char*,int))0x0050C9F0)
#define	pLoadItemModel			((void(*)(int,char*,char*,int))0x005C5873)
#define	pLoadItemTexture		((void(*)(int,char*,int,int,int))0x005C51C0)
#define pViewportAddress		*(DWORD*)(0x079B9D40)
#define pChaosMixIndex			((DWORD(__thiscall*)(DWORD*))0x006EC8C0)(&*(DWORD*)(0x008A4BF0))

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x005BD57B)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x004C6B8E)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x006A33B2)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x00685A69))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x0063CAB0)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x007894BD)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x004F6397)
#define pSettingMonster			((DWORD(*)(int,int))0x004F7C7F)
#define pSetCharacterScale		((void(*)(DWORD))0x004F64F0)

#define pGetTextLine(x)			(((char*(__thiscall*)(void*,int))0x004024D0)(((void(*)())0x0079F5190),x))

#define pMouseLButton			*(BYTE*)(0x07FE0260)
#define pMouseRButton			*(BYTE*)(0x07FE0248)

#define pWindowThis				((LPVOID(*)())0x00750101)
#define pCheckWindow			((bool(__thiscall*)(LPVOID,DWORD))0x0074E829)

#define pLoadWaveFile			((void(*)(int,char*,int,int))0x0063942D)
#define	pSetTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x0041D902)
#define	pSetBGTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x0041D964)
#define pLoadImage				((int(*)(char*,int,GLint,GLint,int,int))0x006A92BE)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x006397B5)
#define pRenderTipText			((void(*)(int,int,char*))0x0050C6F0)
#define pMouseOnZone			((int(__cdecl*)(int,int,int,int,int))0x00416836)
#define pRenderBitmapRotate		((void(*)(int,float,float,float,float,float))0x005E0DD8)
#define pSetPlayerStop			((void(*)(DWORD))0x004CE9B5)

#define pglViewport2			((void(*)(int,int,int,int))0x005DF763)
#define pgluPerspective2		((void(*)(float,float,float,float))0x005DECD2)
#define pGetOpenGLMatrix		((void(*)(LPVOID))0x005DEC67)
#define pCameraMatrix			(LPVOID*)0x07FE00DC
#define pEnableDepthTest		((void(*)())0x005DF1C9)
#define pEnableDepthMask		((void(*)())0x005DF20D)
#define pRenderItem3D			((void(*)(float,float,float,float,int,int,int,int,int))0x005939D0)
#define pBeginBitmap			((void(*)())0x005E0826)
#define pUpdateMousePosition	((void(*)())0x005DFA39)

#define pGetFontDC				((HDC(__thiscall*)(LPVOID)) 0x0041D860)
#define pFontNormal				*(HFONT*)0x07FE0704
#define pFontBold				*(HFONT*)0x07FE0708
#define pFontBig				*(HFONT*)0x07FE070C
#define pFontFixed				*(HFONT*)0x07FE0710

#define	EnableLightMap			((void(*)())0x005DF6D7)
#define	EnableAlphaBlend		((void(*)())0x005DF41B)
#define	EnableAlphaBlend2		((void(*)())0x005DF530)
#define	EnableAlphaBlendMinus	((void(*)())0x005DF4A4)
#define	EnableAlphaTest			((void(*)(bool))0x005DF380)
#define	DisableAlphaBlend		((void(*)())0x005DF301)