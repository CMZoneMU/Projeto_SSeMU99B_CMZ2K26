#include "stdafx.h"
#include "Texture.h"
#include "Util.h"

TEXTURE_INFO TextureInfo[MAX_TEXTURE];

void InitTexture() // OK
{
	memset(&TextureInfo,0,sizeof(TextureInfo));

	SetDword(0x004A982B+2,MAX_TEXTURE);
	
	SetDword(0x006086EE+1,(DWORD)(&TextureInfo));
	
	SetDword(0x0053440D+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00534A36+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00534A45+3,(DWORD)(&TextureInfo));
	
	SetDword(0x005E000A+3,(DWORD)(&TextureInfo));
	
	SetDword(0x005E977D+3,(DWORD)(&TextureInfo));
	
	SetDword(0x005FA7E6+3,(DWORD)(&TextureInfo));
	
	SetDword(0x005FA841+3,(DWORD)(&TextureInfo));
	
	SetDword(0x005FA9B9+3,(DWORD)(&TextureInfo));
	
	SetDword(0x0062C4E3+3,(DWORD)(&TextureInfo));
	
	SetDword(0x0062C938+3,(DWORD)(&TextureInfo));
	
	SetDword(0x0062CADA+3,(DWORD)(&TextureInfo));
	
	SetDword(0x0062CB59+3,(DWORD)(&TextureInfo));
	
	SetDword(0x0044D907+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0044D9C8+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0044DA88+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00460BB6+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0046156E+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0053D282+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0053DF54+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x005484E2+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x005485F4+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00636CA0+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00636CBE+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00636CE7+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00636CFC+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x005E0003+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x005E9776+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00630A75+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00636D4C+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00636F6A+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x00636F9D+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0044D921+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0044D9B0+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0044DA72+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00460B9E+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0046142B+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00461558+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00461B04+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0053D28E+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0053DF5D+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00548401+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x005484CA+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x005485DE+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x005E90D7+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00636CAF+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00636CD2+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00636CF0+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00636D0B+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0053BACB+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00636D6F+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00636FE2+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00637017+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006598CD+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006599B2+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00659B2C+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00659B66+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00659B9F+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00659BE9+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x00659C25+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0044D9D4+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x00451F68+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x00451FF0+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004529A7+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004529FB+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x00460BC2+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004E5484+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004E54D1+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004E6068+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004E60B5+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004E7ACA+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x004E7B00+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0053D2A2+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0053DD92+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x005484EE+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0060D715+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0044D996+1,(DWORD)(&TextureInfo->Texture));
	
	SetDword(0x005484B3+1,(DWORD)(&TextureInfo->Texture));
	
	SetDword(0x0060C932+3,(DWORD)(&TextureInfo->Texture));
	
	SetDword(0x0060C98E+3,(DWORD)(&TextureInfo->Texture));
	
	SetDword(0x00637256+3,(DWORD)(&TextureInfo->Texture));

	SetDword(0x00460B0C+1,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x004631D8+1,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00463208+1,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0060EF86+1,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0044D95D+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0044D9AA+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x004603B8+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00460B98+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0046321C+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00548420+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x005484C4+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x005E90C3+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00534404+3,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0062CAD1+3,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0062CB50+3,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x005DFDF6+2,(DWORD)(&TextureInfo)+1936);
	
	SetDword(0x005E0373+2,(DWORD)(&TextureInfo)+1936);
	
	SetDword(0x005DFE04+2,(DWORD)(&TextureInfo)+1940);
	
	SetDword(0x005E0381+2,(DWORD)(&TextureInfo)+1940);
	
	SetDword(0x005DFF6F+3,(DWORD)(&TextureInfo)+1944);
	
	SetDword(0x005E042F+3,(DWORD)(&TextureInfo)+1944);
	
	SetDword(0x005DFF55+1,(DWORD)(&TextureInfo)+1948);
	
	SetDword(0x005E0418+1,(DWORD)(&TextureInfo)+1948);
	
	SetDword(0x005DFE14+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x005DFF66+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x005E0391+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x005E03C9+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x005E0429+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x005E8C0F+3,(DWORD)(&TextureInfo)+1960);
	
	SetDword(0x0059CD92+3,(DWORD)(&TextureInfo)+2000);
	
	SetDword(0x006044A9+1,(DWORD)(&TextureInfo)+3640);
	
	SetDword(0x006044B1+2,(DWORD)(&TextureInfo)+4200);
	
	SetDword(0x006044FD+2,(DWORD)(&TextureInfo)+4200);
	
	SetDword(0x00604550+2,(DWORD)(&TextureInfo)+5432);

	*(DWORD*)(0x07D16FE8) = 16000;

	MemorySet(0x005FA7B0,0x90,0x05);
}