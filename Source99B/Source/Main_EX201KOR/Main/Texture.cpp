#include "stdafx.h"
#include "Texture.h"
#include "Util.h"

TEXTURE_INFO TextureInfo[MAX_TEXTURE];

void InitTexture() // OK
{
	memset(&TextureInfo,0,sizeof(TextureInfo));

	SetDword(0x004C7791+2,MAX_TEXTURE);

	SetDword(0x006526AE+1,(DWORD)(&TextureInfo));
	
	SetDword(0x005635DD+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00563C06+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00563C15+3,(DWORD)(&TextureInfo));
	
	SetDword(0x006224BA+3,(DWORD)(&TextureInfo));
	
	SetDword(0x0062C27D+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00642566+3,(DWORD)(&TextureInfo));
	
	SetDword(0x006425C1+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00642916+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00673A93+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00673EE8+3,(DWORD)(&TextureInfo));
	
	SetDword(0x0067408A+3,(DWORD)(&TextureInfo));
	
	SetDword(0x00674109+3,(DWORD)(&TextureInfo));

	SetDword(0x0046AAA7+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0046AB68+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0046AC2A+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0047E7D6+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0047F190+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0056E754+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0056F564+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0057A622+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0057A736+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0067F930+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0067F94E+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0067F977+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0067F98C+2,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x006224B3+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0062C276+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x006784C5+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0067F9DC+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0067FBFA+3,(DWORD)(&TextureInfo->Width));
	
	SetDword(0x0067FC2D+3,(DWORD)(&TextureInfo->Width));

	SetDword(0x0046AAC1+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0046AB50+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0046AC14+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0047E7BE+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0047F04B+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0047F17A+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0047F724+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0056E760+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0056F56D+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0057A541+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0057A60A+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0057A720+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0062B997+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0067F93F+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0067F962+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0067F980+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0067F99B+2,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0056C6D4+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0067F9FF+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0067FC72+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x0067FCA7+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A61CD+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A62B2+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A6431+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A64D1+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A650B+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A6544+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A6591+3,(DWORD)(&TextureInfo->Height));
	
	SetDword(0x006A65D0+3,(DWORD)(&TextureInfo->Height));

	SetDword(0x0046AB74+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0046F1EE+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0046F276+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0046FC2D+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0046FC81+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0047E7E2+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0050A697+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0050A6E4+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0050B2EA+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0050B337+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0050CDFB+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0050CE31+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0056E775+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0056F372+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x0057A62E+3,(DWORD)(&TextureInfo->Component));
	
	SetDword(0x00658225+3,(DWORD)(&TextureInfo->Component));

	SetDword(0x0046AB36+1,(DWORD)(&TextureInfo->Texture));
	
	SetDword(0x0057A5F3+1,(DWORD)(&TextureInfo->Texture));
	
	SetDword(0x00657442+3,(DWORD)(&TextureInfo->Texture));
	
	SetDword(0x0065749E+3,(DWORD)(&TextureInfo->Texture));

	SetDword(0x0047E72C+1,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00480DF8+1,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00480E28+1,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0046AAFD+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0046AB4A+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0047DFD8+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0047E7B8+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00480E3C+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0057A560+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0057A604+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x0062B983+2,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x005635D4+3,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00674081+3,(DWORD)(&TextureInfo->Buffer));
	
	SetDword(0x00674100+3,(DWORD)(&TextureInfo->Buffer));

	SetDword(0x006222A6+2,(DWORD)(&TextureInfo)+1936);
	
	SetDword(0x00622825+2,(DWORD)(&TextureInfo)+1936);

	SetDword(0x006222B4+2,(DWORD)(&TextureInfo)+1940);
	
	SetDword(0x00622833+2,(DWORD)(&TextureInfo)+1940);

	SetDword(0x0062241F+3,(DWORD)(&TextureInfo)+1944);
	
	SetDword(0x006228E1+3,(DWORD)(&TextureInfo)+1944);

	SetDword(0x00622405+1,(DWORD)(&TextureInfo)+1948);
	
	SetDword(0x006228CA+1,(DWORD)(&TextureInfo)+1948);

	SetDword(0x006222C4+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x00622416+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x00622843+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x0062287B+2,(DWORD)(&TextureInfo)+1956);
	
	SetDword(0x006228DB+2,(DWORD)(&TextureInfo)+1956);

	SetDword(0x0062B4CF+3,(DWORD)(&TextureInfo)+1960);

	SetDword(0x005D84EB+3,(DWORD)(&TextureInfo)+2000);

	SetDword(0x0064D41C+2,(DWORD)(&TextureInfo)+3640);

	SetDword(0x0064D424+2,(DWORD)(&TextureInfo)+4200);
	
	SetDword(0x0064D470+2,(DWORD)(&TextureInfo)+4200);

	SetDword(0x0064D4C3+2,(DWORD)(&TextureInfo)+5432);

	*(DWORD*)(0x07DCAF00) = 16000;

	MemorySet(0x00642530,0x90,0x05);
}