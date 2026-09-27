#include "stdafx.h"
#include "Font.h"
#include "Offset.h"
#include "Util.h"

int FontSize;

DWORD FontCharSet;

char FontName[100];

int ReadFontFile(char* path) // OK
{	
	FontSize = GetPrivateProfileInt("FontInfo","FontSize",13,path);
	
	FontCharSet = GetPrivateProfileInt("FontInfo","FontCharSet",1,path);
	
	GetPrivateProfileString("FontInfo","FontName","Tahoma",FontName,sizeof(FontName),path);

	return GetPrivateProfileInt("FontInfo","ChangeFontSwitch",0,path);
}

void InitFont() // OK
{
	if(ReadFontFile(".\\Config.ini") != 0)
	{
		SetCompleteHook(0xE8,0x0062974D,&FontNormal);
		
		SetCompleteHook(0xE8,0x006297A5,&FontBool);
		
		SetCompleteHook(0xE8,0x00629800,&FontBig);
		
		SetCompleteHook(0xE8,0x00629858,&FontFixed);
		
		SetByte(0x00629752,0x90);
		
		SetByte(0x006297AA,0x90);
		
		SetByte(0x00629805,0x90);
		
		SetByte(0x0062985D,0x90);
	}
}

void ReloadFont() // OK
{
	*(HFONT*)0x011C3E8C = FontNormal();

	*(HFONT*)0x011C3E90 = FontBool();

	*(HFONT*)0x011C3E94 = FontBig();

	*(HFONT*)0x011C3E98 = FontFixed();

	*(DWORD*)MAIN_FONT_SIZE = FontSize;

	//((int(__cdecl*)(char*,int,int,int,int,int))0x00787BE2)("Interface\\FontInput.tga",0x7532,0x2600,0x2900,1,0);
	//((int(__cdecl*)(char*,int,int,int,int,int))0x00787BE2)("Interface\\FontTest.tga",0x7533,0x2600,0x2900,1,0);
	//((int(__cdecl*)(char*,int,int,int,int,int))0x00787BE2)("Interface\\Hit.tga",0x7BFF,0x2600,0x2900,1,0);
}

HFONT FontNormal() // OK
{
	return CreateFont(FontSize,0,0,0,FW_NORMAL,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}

HFONT FontBool() // OK
{
	return CreateFont(FontSize,0,0,0,FW_BOLD,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}

HFONT FontBig() // OK
{
	return CreateFont(FontSize*2,0,0,0,FW_BOLD,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}

HFONT FontFixed() // OK
{
	return CreateFont(FontSize,0,0,0,FW_NORMAL,0,0,0,FontCharSet,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,NONANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,FontName);
}