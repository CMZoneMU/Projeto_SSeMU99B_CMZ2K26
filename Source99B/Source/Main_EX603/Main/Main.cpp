#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "Camera.h"
#include "CCRC32.H"
#include "ChaosBox.h"
#include "ChatWindow.h"
#include "Common.h"
#include "CustomItem.h"
#include "CustomItemBow.h"
#include "CustomItemGlove.h"
#include "CustomJewel.h"
#include "CustomMonster.h"
#include "CustomWing.h"
#include "EventEntryLevel.h"
#include "Fog.h"
#include "Font.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
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
		SetByte(0x00E61144,0xA0); // Accent
		SetByte(0x004D1E69,0xEB); // Crack (mu.exe)
		SetByte(0x004D228D,0xE9); // Crack (GameGuard)
		SetByte(0x004D228E,0x8B); // Crack (GameGuard)
		SetByte(0x004D228F,0x00); // Crack (GameGuard)
		SetByte(0x004D2290,0x00); // Crack (GameGuard)
		SetByte(0x004D2291,0x00); // Crack (GameGuard)
		SetByte(0x004D559C,0xEB); // Crack (ResourceGuard)
		SetByte(0x00633F7A,0xEB); // Crack (ResourceGuard)
		SetByte(0x00634403,0xEB); // Crack (ResourceGuard)
		SetByte(0x0063E6C4,0xEB); // Crack (ResourceGuard)
		SetByte(0x004D2246,0xEB); // Crack (ResourceGuard)
		SetByte(0x00501163,0xEB); // Crack (ResourceGuard)
		SetByte(0x0040AF0A,0x00); // Crack (ResourceGuard)
		SetByte(0x0040B4BC,0x50); // Login Screen
		SetByte(0x0040B4C5,0x50); // Login Screen
		SetByte(0x0040B4CF,0x18); // Login Screen
		SetByte(0x0040AF0A,0x00); // Login Screen
		SetByte(0x0040AFD5,0xEB); // Login Screen
		SetByte(0x005C8F86,0x00); // Lucky Move To Vault
		SetByte(0x005C8DAC,0x00); // Lucky Move To Trade
		SetByte(0x00777FD6,0x70); // Item Text Limit
		SetByte(0x00777FD7,0x17); // Item Text Limit
		SetByte(0x004EBEC7,0x3C); // Item Text Limit
		SetByte(0x005C4004,0x3C); // Item Text Limit
		SetByte(0x007E40BB,0x3C); // Item Text Limit
		SetByte(0x0081B546,0x3C); // Item Text Limit
		SetByte(0x0081B58D,0x3C); // Item Text Limit
		SetByte(0x0086E284,0x3C); // Item Text Limit
		SetByte(0x0086E44C,0x3C); // Item Text Limit
		SetByte(0x0086E573,0x3C); // Item Text Limit
		SetByte(0x0086F8FC,0x3C); // Item Text Limit
		SetByte(0x007DA373,0xB7); // Item Type Limit
		SetByte(0x007E1C44,0xB7); // Item Type Limit
		SetByte(0x0052100D,0xEB); // Ctrl Fix
		SetByte(0x0052101B,0x02); // Ctrl Fix
		SetByte(0x009543C4,0x00); // Move Vulcanus
		SetByte(0x0064CBD1,((gProtect.m_MainInfo.HelperActiveAlert == 0) ? 0xEB : 0x75)); // Helper Message Box
		SetByte(0x0064CBD0,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
		SetByte(0x0095CEEF,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
		SetByte(0x0095CF14,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
		SetByte(0x00E61F68,(gProtect.m_MainInfo.ClientVersion[0] + 1)); // Version
		SetByte(0x00E61F69,(gProtect.m_MainInfo.ClientVersion[2] + 2)); // Version
		SetByte(0x00E61F6A,(gProtect.m_MainInfo.ClientVersion[3] + 3)); // Version
		SetByte(0x00E61F6B,(gProtect.m_MainInfo.ClientVersion[5] + 4)); // Version
		SetByte(0x00E61F6C,(gProtect.m_MainInfo.ClientVersion[6] + 5)); // Version
		SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
		SetDword(0x004D0E09,(DWORD)gProtect.m_MainInfo.WindowName);
		SetDword(0x004D9F55,(DWORD)gProtect.m_MainInfo.ScreenShotPath);
		SetDword(0x00D226C8,(DWORD)KeysProc);
		SetDword(0x00D2265C,(DWORD)IconProc);

		MemorySet(0x00D20170,0x90,0x1B); // Remove MuError.log

		MemorySet(0x005528B6,0x90,0x3F); // Remove Reflect Effect

		MemorySet(0x0063E908,0x90,0x14); // C1:F3:04

		MemorySet(0x0064452A,0x90,0x0D); // Fix Dark horse look around

		MemorySet(0x00792B7F,0x90,0x05); // Crywolf Gatekeeper

		MemoryCpy(0x00E611B2,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddress

		MemoryCpy(0x00E61F70,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

		SetCompleteHook(0xE8,0x005B96E8,&DrawNewHealthBar);

		SetCompleteHook(0xFF,0x0065FD79,&ProtocolCoreEx);

		LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN1),(DWORD)&NewAddressData1);

		LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN2),(DWORD)&NewAddressData2);

		LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN3),(DWORD)&NewAddressData3);

		gCustomEffect.Load(gProtect.m_MainInfo.CustomEffectInfo);

		gCustomFog.Load(gProtect.m_MainInfo.CustomFogInfo);

		gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

		gCustomItemBow.Load(gProtect.m_MainInfo.CustomItemBowInfo);

		gCustomItemGlove.Load(gProtect.m_MainInfo.CustomItemGloveInfo);

		gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

		gCustomMap.Load(gProtect.m_MainInfo.CustomMapInfo);

		gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsterInfo);

		gCustomMonsterSkin.Load(gProtect.m_MainInfo.CustomMonsterSkinInfo);

		gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

		gItemStack.Load(gProtect.m_MainInfo.ItemStackInfo);

		gItemValue.Load(gProtect.m_MainInfo.ItemValueInfo);

		gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

		gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");

		gLuaLoader.Load("Script\\Main.lua");

		InitChaosBox();

		InitChatWindow();

		InitCommon();

		InitEventEntryLevel();

		InitFog();

		InitFont();

		InitHackCheck();

		InitItem();

		InitItemBow();

		InitItemGlove();

		InitJewel();

		InitLua();

		InitMap();

		//InitMiniMap();

		InitMonster();

		InitPrintPlayer();

		InitReconnect();

		InitResolution();

		InitShop();

		InitWing();

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