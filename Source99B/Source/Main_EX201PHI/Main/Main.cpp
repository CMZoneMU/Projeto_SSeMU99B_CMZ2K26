#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "Camera.h"
#include "CCRC32.H"
#include "ChaosBox.h"
#include "Common.h"
#include "CustomItem.h"
#include "EventEntryLevel.h"
#include "Fog.h"
#include "Font.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
#include "Language.h"
#include "Lua.h"
#include "LuaLoader.h"
#include "Map.h"
#include "MiniMap.h"
#include "Monster.h"
#include "Offset.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "ServerList.h"
#include "Shop.h"
#include "TrayMode.h"
#include "Util.h"

HHOOK HookKB,HookMS;
HINSTANCE hins;
static DWORD ReloadScript = 0;

LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam) // OK
{
	if(nCode == HC_ACTION)
	{
		if(((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0 && GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			if(wParam == VK_PAUSE)
			{
				if((++ReloadScript) >= 10)
				{
					ReloadScript = 0;

					gLuaLoader.Load("Script\\Main.lua");

					pDrawMessage("Reload Scripts",1);
				}
			}

			if(gProtect.m_MainInfo.KeyCodeHealthBarSwitch != 0 && wParam == gProtect.m_MainInfo.KeyCodeHealthBarSwitch)
			{
				HealthBarToggle();
			}
			else if(gProtect.m_MainInfo.KeyCodeCamera3DSwitch != 0 && wParam == gProtect.m_MainInfo.KeyCodeCamera3DSwitch)
			{
				gCamera.Toggle();
			}
			else if(gProtect.m_MainInfo.KeyCodeCamera3DRestore != 0 && wParam == gProtect.m_MainInfo.KeyCodeCamera3DRestore)
			{
				gCamera.Restore();
			}
			else if(gProtect.m_MainInfo.KeyCodeTrayModeSwitch != 0 && wParam == gProtect.m_MainInfo.KeyCodeTrayModeSwitch)
			{
				gTrayMode.Toggle();
			}

			gLuaLoader.KeyboardEvent(wParam);
		}
	}

	return CallNextHookEx(HookKB,nCode,wParam,lParam);
}

LRESULT CALLBACK MouseProc(int nCode,WPARAM wParam,LPARAM lParam) // OK
{
	if(nCode == HC_ACTION)
	{
		MOUSEHOOKSTRUCTEX* HookStruct =(MOUSEHOOKSTRUCTEX*)lParam;

		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			switch(wParam)
			{
				case WM_MOUSEMOVE:
					gCamera.Move(HookStruct);
					break;
				case WM_MBUTTONDOWN:
					gCamera.SetIsMove(1);
					gCamera.SetCursorX(HookStruct->pt.x);
					gCamera.SetCursorY(HookStruct->pt.y);
					break;
				case WM_MBUTTONUP:
					gCamera.SetIsMove(0);
					break;
				case WM_MOUSEWHEEL:
					gCamera.Zoom(HookStruct);
					break;
			}
		}
	}

	return CallNextHookEx(HookMS,nCode,wParam,lParam);
}

SHORT WINAPI KeysProc(int nCode) // OK
{
	if(GetForegroundWindow() != *(HWND*)(MAIN_WINDOW))
	{
		return 0;
	}

	return GetAsyncKeyState(nCode);
}

HICON WINAPI IconProc(HINSTANCE hInstance,LPCSTR lpIconName) // OK
{
	FILE* file;

	if(fopen_s(&file,".\\main.ico","r") != 0)
	{
		gTrayMode.m_TrayIcon = (HICON)LoadImage(hins,MAKEINTRESOURCE(IDI_CLIENT),IMAGE_ICON,GetSystemMetrics(SM_CXICON),GetSystemMetrics(SM_CYICON),LR_DEFAULTCOLOR);
	}
	else
	{
		fclose(file);
		gTrayMode.m_TrayIcon = (HICON)LoadImage(hins,".\\main.ico",IMAGE_ICON,GetSystemMetrics(SM_CXICON),GetSystemMetrics(SM_CYICON),LR_LOADFROMFILE | LR_DEFAULTCOLOR);
	}

	return gTrayMode.m_TrayIcon;
}

void WINAPI ReduceConsumeProc() // OK
{
	while(true)
	{
		Sleep(5000);
		SetProcessWorkingSetSize(GetCurrentProcess(),0xFFFFFFFF,0xFFFFFFFF);
		SetThreadPriority(GetCurrentProcess(),THREAD_PRIORITY_LOWEST);
	}
}

extern "C" _declspec(dllexport) void EntryProc() // OK
{
	if(gProtect.ReadMainFile("ServerInfo.sse") != 0)
	{
		SetByte(0x0079F5BC,0xA0); // Accent
		SetByte(0x0046F21B,0xEB); // Ctrl Fix
		SetByte(0x0046F229,0x02); // Ctrl Fix
		SetByte(0x006AFCDC,0x7F); // Fix Enter Select Char
		SetByte(0x006D4056,0xEB); // Fix Ancient Harmony
		SetByte(0x00532875,0x0D); // Fix Effect +13
		SetByte(0x007A078C,(gProtect.m_MainInfo.ClientVersion[0]+1)); // Version
		SetByte(0x007A078D,(gProtect.m_MainInfo.ClientVersion[2]+2)); // Version
		SetByte(0x007A078E,(gProtect.m_MainInfo.ClientVersion[3]+3)); // Version
		SetByte(0x007A078F,(gProtect.m_MainInfo.ClientVersion[5]+4)); // Version
		SetByte(0x007A0790,(gProtect.m_MainInfo.ClientVersion[6]+5)); // Version
		SetWord(0x007B3568,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
		SetDword(0x004D405B,(DWORD)gProtect.m_MainInfo.WindowName);
		SetDword(0x006B3E34,(DWORD)gProtect.m_MainInfo.ScreenShotPath);
		SetDword(0x0078145C,(DWORD)&KeysProc);
		SetDword(0x00781500,(DWORD)&IconProc);

		MemorySet(0x00420E57,0x90,0x2B); // Remove MuError.log

		MemorySet(0x00515C52,0x90,0x3F); // Remove Reflect Effect

		MemorySet(0x0061697B,0x90,0x02); // Item Move Inventory -> Interface

		MemorySet(0x006169F6,0x90,0x02); // Item Move Interface -> Inventory

		MemoryCpy(0x0079F710,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddress

		MemoryCpy(0x007A0794,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

		SetCompleteHook(0xE8,0x005E9A87,&DrawNewHealthBar);

		SetCompleteHook(0xFF,0x004FF77D,&ProtocolCoreEx);

		gCustomEffect.Load(gProtect.m_MainInfo.CustomEffectInfo);

		gCustomFog.Load(gProtect.m_MainInfo.CustomFogInfo);

		gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

		gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

		gCustomMap.Load(gProtect.m_MainInfo.CustomMapInfo);

		gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsterInfo);

		gCustomMonsterSkin.Load(gProtect.m_MainInfo.CustomMonsterSkinInfo);

		gCustomTooltip.Load(gProtect.m_MainInfo.CustomTooltipInfo);

		gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

		gItemStack.Load(gProtect.m_MainInfo.ItemStackInfo);

		gItemValue.Load(gProtect.m_MainInfo.ItemValueInfo);

		gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

		gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");

		gLuaLoader.Load("Script\\Main.lua");

		InitChaosBox();

		InitCommon();

		InitEventEntryLevel();

		InitFog();

		InitFont();

		InitHackCheck();

		InitItem();

		InitBundle();

		InitJewel();

		InitLanguage();

		InitLua();

		InitWing();

		InitMap();

		InitMiniMap();

		InitMonster();

		InitPrintPlayer();

		InitResolution();

		InitReconnect();

		InitServerList();

		InitShop();

		gProtect.CheckLauncher();

		gProtect.CheckInstance();

		gProtect.CheckClientFile();

		gProtect.CheckPluginFile();

		HookKB = SetWindowsHookEx(WH_KEYBOARD,KeyboardProc,hins,GetCurrentThreadId());

		HookMS = SetWindowsHookEx(WH_MOUSE,MouseProc,hins,GetCurrentThreadId());

		CreateThread(0,0,(LPTHREAD_START_ROUTINE)ReduceConsumeProc,0,0,0);
		
		#if(DEBUG_CONSOLE == 1)

		if(GetPrivateProfileInt("Debug","Debug",0,".\\Config.ini") != 0)
		{
			if(AllocConsole() == 0)
			{
				ErrorMessageBox("Could not open AllocConsole()");
				return;
			}

			SetConsoleTitleA("SSeMU || Debugger");

			DeleteMenu(GetSystemMenu(GetConsoleWindow(),0),SC_CLOSE,MF_BYCOMMAND);
		}

		#endif
	}
	else
	{
		ErrorMessageBox("Could not load ServerInfo.sse!");
		ExitProcess(0);
	}
}

BOOL APIENTRY DllMain(HANDLE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			hins = (HINSTANCE)hModule;
			break;
	}

	return 1;
}