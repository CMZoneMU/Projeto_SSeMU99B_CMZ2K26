#pragma once

#define MAX_TEXTURE 2182
#define MAX_PLUS_TEXTURE 768
#define pTextureCount *(DWORD*)(0x07AFE7E0)

struct TEXTURE_INFO
{
	char* name[50];
};

void InitTexture();
void SetTexture();
void TexturePlayerLoad();
void TextureItemLoad();
DWORD CheckTexture(char* name,DWORD index);