#pragma once

#define MAIN_WINDOW				0x00E8C578
#define MAIN_CONNECTION_STATUS	0x08793704
#define MAIN_SCREEN_STATE		0x00E609E8
#define MAIN_CHARACTER_STRUCT	0x08128AC8
#define MAIN_VIEWPORT_STRUCT	0x07BC4F04
#define MAIN_PACKET_SERIAL		0x08793700
#define MAIN_HELPER_STRUCT		0x00E8CB7C
#define MAIN_FONT_SIZE			0x081C0380
#define MAIN_RESOLUTION			0x00E8C240
#define MAIN_RESOLUTION_X		0x00E61E58
#define MAIN_RESOLUTION_Y		0x00E61E5C
#define MAIN_PARTY_MEMBER_COUNT	0x081F6B6C
#define MAIN_CURRENT_MAP		0x00E61E18
#define MAIN_ACTIVE_SOCKET		0x08793750

#define ProtocolCore			((BOOL(*)(DWORD,BYTE*,DWORD,DWORD))0x00663B20)
#define pGetPosFromAngle		((void(__cdecl*)(float*,int*,int*))0x00635B00)
#define pCursorX				*(int*)0x0879340C
#define pCursorY				*(int*)0x08793410
#define pTextThis				((LPVOID(*)())0x0041FE10)
#define pDrawText				((int(__thiscall*)(LPVOID,int,int,char*,int,int,int*,int))0x00420150)
#define pDrawBarForm			((void(__cdecl*)(float,float,float,float,float,int))0x006378A0)
#define pDrawToolTip			((int(__cdecl*)(int,int,LPCSTR))0x00597220)
#define pDrawImage 				((void(*)(DWORD,float,float,float,float,float,float,float,float,int,int,GLfloat))0x00637C60)
#define pDrawMessage			((int(__cdecl*)(LPCSTR,int))0x00597630)
#define pLoadItemModel			((void(*)(int,char*,char*,int))0x00614D10)
#define pLoadItemTexture		((void(*)(int,char*,int,int,int))0x00614710)
#define DrawInterface			((void(*)(DWORD,float,float,float,float))0x00790B50)
#define DrawInterfaceText		((void(*)(char*,int,int,int,int,int,int,int))0x007D04D0)
#define pGloveAssoc				((int(__thiscall*)(DWORD,DWORD,DWORD,DWORD))0x0050D810)
#define pGloveCount				((void*(__thiscall*)(DWORD))0x00512D50)(Address+0x5C)
#define pGloveSetInfo			((DWORD(__thiscall*)(DWORD,void*,DWORD))0x00513C60)
#define pGloveSaveInfo			((char*(__thiscall*)(DWORD*,DWORD,DWORD))0x005135F0)
#define pGloveRefresh			((void(*)())0x00512D60)
#define pChaosMixIndex			((DWORD(__thiscall*)(DWORD*))0x0079DEA0)(&*(DWORD*)(0x00EBB848))

#define pRenderPartObjectEffect	((void(*)(DWORD,int,float*,float,int,int,int,int,int))0x00609E70)
#define pTransformPosition      ((int(__thiscall*)(DWORD,DWORD,float*,float*,bool))0x00545030)
#define pCreateSprite	        ((int(*)(int,float*,float,float*,DWORD,float,int))0x00771310)
#define pCreateParticle			((int(__cdecl*)(DWORD,float*,DWORD,float*,DWORD,float,DWORD))(0x0074CD30))
#define pCreateEffect			((void(__cdecl*)(int,float*,DWORD,float*,int,DWORD,short,BYTE,float,BYTE,float*))0x006D9070)

#define pCreateMonster			((DWORD(*)(int,int,int,int))0x00901460)
#define pCreateCharacter		((DWORD(*)(int,int,int,int,float))0x0057EEC0)
#define pSettingMonster			((DWORD(*)(int,int))0x00580BB0)
#define pSetCharacterScale		((void(*)(DWORD))0x0057F020)

#define pGetTextLine(x)			(((char*(__thiscall*)(void*,int))0x00402320)(((void(*)())0x008128ADC),x))

#define pMouseLButton			*(BYTE*)(0x08793386)
#define pMouseRButton			*(BYTE*)(0x08793383)

#define pWindowThis				((LPVOID(*)())0x00861110)
#define pCheckWindow			((bool(__thiscall*)(LPVOID,DWORD))0x0085EC20)

#define pLoadWaveFile			((void(*)(int,char*,int,int))0x006D6800)
#define	pSetTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x00420040)
#define	pSetBGTextColor			((void(__thiscall*)(LPVOID,BYTE,BYTE,BYTE,BYTE))0x004200B0)
#define pLoadImage				((int(*)(char*,int,GLint,GLint,int,int))0x00772330)
#define pPlayBuffer				((int(__cdecl*)(int,int,int))0x006D6C20)
#define pRenderTipText			((void(*)(int,int,char*))0x00597220)
#define pMouseOnZone			((int(__cdecl*)(int,int,int,int,int))0x00417C80)
#define pRenderBitmapRotate		((void(*)(int,float,float,float,float,float,float,float,float,float))0x00637E80)
#define pSetPlayerStop			((void(*)(DWORD))0x0054EA80)

#define pglViewport2			((void(*)(int,int,int,int))0x006363D0)
#define pgluPerspective2		((void(*)(float,float,float,float))0x006358A0)
#define pGetOpenGLMatrix		((void(*)(LPVOID))0x00635830)
#define pCameraMatrix			(LPVOID*)0x087933A0
#define pEnableDepthTest		((void(*)())0x00635DE0)
#define pEnableDepthMask		((void(*)())0x00635E40)
#define pRenderItem3D			((void(*)(float,float,float,float,int,int,int,int,int))0x005CF310)
#define pBeginBitmap			((void(*)())0x00637770)
#define pUpdateMousePosition	((void(*)())0x00636720)

#define pGetFontDC				((HDC(__thiscall*)(LPVOID)) 0x0041FF80)
#define pFontNormal				*(HFONT*)0x00E8C588
#define pFontBold				*(HFONT*)0x00E8C58C
#define pFontBig				*(HFONT*)0x00E8C590
#define pFontFixed				*(HFONT*)0x00E8C594

#define	EnableLightMap			((void(*)())0x00636340)
#define	EnableAlphaBlend		((void(*)())0x00636070)
#define	EnableAlphaBlend2		((void(*)())0x00636190)
#define	EnableAlphaBlendMinus	((void(*)())0x00636100)
#define	EnableAlphaTest			((void(*)(bool))0x00635FD0)
#define	DisableAlphaBlend		((void(*)())0x00635F50)