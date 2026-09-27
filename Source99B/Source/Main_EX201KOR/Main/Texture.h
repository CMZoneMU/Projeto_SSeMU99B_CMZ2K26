#pragma once

#define MAX_TEXTURE 19574

struct TEXTURE_INFO
{
	char Name[32];
	float Width;
	float Height;
	DWORD Component;
	GLuint Texture;
	DWORD Ref;
	BYTE* Buffer;
};

void InitTexture();