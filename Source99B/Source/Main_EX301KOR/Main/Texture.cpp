#include "StdAfx.h"
#include "Texture.h"
#include "Util.h"

DWORD dwTexRef0x0[21];
DWORD dwTexRef0x20[13];
DWORD dwTexRef0x24[14];
DWORD dwTexRef0x28[13];
DWORD dwTexRef0x2E;
DWORD dwTexRef0x6C4[2];
DWORD dwTexRef0x6C8[2];
DWORD dwTexRef0x6CC[2];
DWORD dwTexRef0x6CD[2];
DWORD dwTexRef0x6D2[4];
DWORD dwTexRef0x6FE;

DWORD TextureCount;
int TextureType;
int TextureOverFlow;

TEXTURE_INFO lpTextures[MAX_TEXTURE+MAX_PLUS_TEXTURE];

void InitTexture() // OK
{
	SetTexture();

	SetCompleteHook(0xE8,0x0062B3E3,&CheckTexture);

	SetCompleteHook(0xE8,0x0063E905,&TexturePlayerLoad);

	SetCompleteHook(0xE8,0x0063E92F,&TextureItemLoad);

	memset(lpTextures,0,sizeof(lpTextures));

	TextureCount = MAX_TEXTURE;

	for(int n=0;n < 21;n++)
	{
		SetDword(dwTexRef0x0[n],(DWORD)lpTextures);
	}

	for(int n=0;n < 13;n++)
	{
		SetDword(dwTexRef0x20[n],(DWORD)lpTextures+0x20);
	}

	for(int n=0;n < 14;n++)
	{
		SetDword(dwTexRef0x24[n],(DWORD)lpTextures+0x24);
	}

	for(int n=0;n < 13;n++)
	{
		SetDword(dwTexRef0x28[n],(DWORD)lpTextures+0x28);
	}

	SetDword(dwTexRef0x2E,(DWORD)lpTextures+0x2E);

	for(int n=0;n < 2;n++)
	{
		SetDword(dwTexRef0x6C4[n], (DWORD)lpTextures+0x6C4);
	}

	for(int n=0;n < 2;n++)
	{
		SetDword(dwTexRef0x6C8[n], (DWORD)lpTextures+0x6C8);
	}

	for(int n=0;n < 2;n++)
	{
		SetDword(dwTexRef0x6CC[n], (DWORD)lpTextures+0x6CC);
	}

	for(int n=0;n < 2;n++)
	{
		SetDword(dwTexRef0x6CD[n], (DWORD)lpTextures+0x6CD);
	}

	for(int n=0;n < 4;n++)
	{
		SetDword(dwTexRef0x6D2[n], (DWORD)lpTextures+0x6D2);
	}

	SetDword(dwTexRef0x6FE,(DWORD)lpTextures+0x6FE);
}

#pragma optimize("t", on)

void SetTexture() // OK
{
	__asm
	{
		//******************************************
		Mov dwTexRef0x0[4*0],0x004203BC+3;
		Mov dwTexRef0x0[4*1],0x0042048D+3;
		Mov dwTexRef0x0[4*2],0x00421AF6+3;
		Mov dwTexRef0x0[4*3],0x00421DA4+3;
		Mov dwTexRef0x0[4*4],0x005FA38D+3;
		Mov dwTexRef0x0[4*5],0x00606967+1;
		Mov dwTexRef0x0[4*6],0x00607A8D+2;
		Mov dwTexRef0x0[4*7],0x0062B242+2;
		Mov dwTexRef0x0[4*8],0x0062B25F+1;
		Mov dwTexRef0x0[4*9],0x0062B32C+2;
		Mov dwTexRef0x0[4*10],0x0062B4DF+1;
		Mov dwTexRef0x0[4*11],0x006366DA+1;
		Mov dwTexRef0x0[4*12],0x00642025+2;
		Mov dwTexRef0x0[4*13],0x00642087+1;
		Mov dwTexRef0x0[4*14],0x0064C350+1;
		Mov dwTexRef0x0[4*15],0x006F28D3+1;
		Mov dwTexRef0x0[4*16],0x006F3193+1;
		Mov dwTexRef0x0[4*17],0x006F31A1+2;
		Mov dwTexRef0x0[4*18],0x006F9E06+1;
		Mov dwTexRef0x0[4*19],0x006FA2FB+1;
		Mov dwTexRef0x0[4*20],0x006FA832+1;
		//******************************************
		Mov dwTexRef0x20[4*0],0x004074EB+2;
		Mov dwTexRef0x20[4*1],0x00414D88+2;
		Mov dwTexRef0x20[4*2],0x00414DBE+2;
		Mov dwTexRef0x20[4*3],0x00414E00+2;
		Mov dwTexRef0x20[4*4],0x00414E42+2;
		Mov dwTexRef0x20[4*5],0x00414ECF+2;
		Mov dwTexRef0x20[4*6],0x00415296+2;
		Mov dwTexRef0x20[4*7],0x004152EC+2;
		Mov dwTexRef0x20[4*8],0x005FA386+3;
		Mov dwTexRef0x20[4*9],0x006ED616+2;
		Mov dwTexRef0x20[4*10],0x006EE1D9+2;
		Mov dwTexRef0x20[4*11],0x006EE329+2;
		Mov dwTexRef0x20[4*12],0x006EEA3A+2;
		//******************************************
		Mov dwTexRef0x24[4*0],0x00414DA3+2;
		Mov dwTexRef0x24[4*1],0x00414DDF+2;
		Mov dwTexRef0x24[4*2],0x00414E21+2;
		Mov dwTexRef0x24[4*3],0x00414E5D+2;
		Mov dwTexRef0x24[4*4],0x00414EFA+2;
		Mov dwTexRef0x24[4*5],0x00415358+2;
		Mov dwTexRef0x24[4*6],0x004153AE+2;
		Mov dwTexRef0x24[4*7],0x0048C08B+2;
		Mov dwTexRef0x24[4*8],0x00606F24+2;
		Mov dwTexRef0x24[4*9],0x006E9FFA+2;
		Mov dwTexRef0x24[4*10],0x006ED62E+2;
		Mov dwTexRef0x24[4*11],0x006EE1F7+2;
		Mov dwTexRef0x24[4*12],0x006EE347+2;
		Mov dwTexRef0x24[4*13],0x006EEA50+2;
		//******************************************
		Mov dwTexRef0x28[4*0],0x004F915B+3;
		Mov dwTexRef0x28[4*1],0x004F9228+3;
		Mov dwTexRef0x28[4*2],0x004FA3A3+3;
		Mov dwTexRef0x28[4*3],0x004FA445+3;
		Mov dwTexRef0x28[4*4],0x00503B6E+3;
		Mov dwTexRef0x28[4*5],0x00503BB4+3;
		Mov dwTexRef0x28[4*6],0x00504CBD+3;
		Mov dwTexRef0x28[4*7],0x00504D03+3;
		Mov dwTexRef0x28[4*8],0x00506361+3;
		Mov dwTexRef0x28[4*9],0x00506391+3;
		Mov dwTexRef0x28[4*10],0x006430D8+3;
		Mov dwTexRef0x28[4*11],0x006ED643+3;
		Mov dwTexRef0x28[4*12],0x006F42B9+3;
		//******************************************
		Mov dwTexRef0x2E,0x00606F11+2;
		//******************************************
		Mov dwTexRef0x6C4[4*0],0x005FA173+2;
		Mov dwTexRef0x6C4[4*1],0x005FA71C+2;
		//******************************************
		Mov dwTexRef0x6C8[4*0],0x005FA182+2;
		Mov dwTexRef0x6C8[4*1],0x005FA72A+2;
		//******************************************
		Mov dwTexRef0x6CC[4*0],0x005FA2F3+3;
		Mov dwTexRef0x6CC[4*1],0x005FA7CF+3;
		//******************************************
		Mov dwTexRef0x6CD[4*0],0x005FA2DC+1;
		Mov dwTexRef0x6CD[4*1],0x005FA7B8+1;
		//******************************************
		Mov dwTexRef0x6D2[4*0],0x005FA193+2;
		Mov dwTexRef0x6D2[4*1],0x005FA2ED+2;
		Mov dwTexRef0x6D2[4*2],0x005FA73B+2;
		Mov dwTexRef0x6D2[4*3],0x005FA7C9+2;
		//******************************************
		Mov dwTexRef0x6FE,0x005A3832+3;
	}
}

#pragma optimize("t", off)

void TexturePlayerLoad() // OK
{
	pTextureCount = 302;

	TextureType = 1;

	((void(*)())0x0062CC43)();

	if(TextureOverFlow)
	{
		TextureOverFlow = 0;

		TextureCount = pTextureCount;
	}

	TextureType = 0;
}

void TextureItemLoad() // OK
{
	pTextureCount = 757;

	TextureType = 2;

	((void(*)())0x0062EAEB)();

	if(TextureOverFlow)
	{
		TextureOverFlow = 0;

		TextureCount = pTextureCount;
	}

	TextureType = 0;
}

DWORD CheckTexture(char* name,DWORD index) // OK
{
	if(TextureOverFlow == 0)
	{
		if(TextureType == 1)
		{
			if(pTextureCount >= 742)
			{
				TextureOverFlow = 1;
			}
		}
		else if(TextureType == 2)
		{
			if(pTextureCount >= 1107)
			{
				TextureOverFlow = 1;
			}
		}
	}

	if(TextureOverFlow == 1)
	{
		pTextureCount = TextureCount;

		TextureOverFlow = 2;
	}

	return ((DWORD(*)(char*,DWORD))0x0062B207)(name,index);
}