#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "Camera.h"
#include "CCRC32.H"
#include "ChaosBox.h"
#include "Common.h"
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
#include "Texture.h"
#include "TrayMode.h"
#include "Util.h"

HHOOK HookKB,HookMS;
HINSTANCE hins;
static DWORD ReloadScript = 0;

LRESULT CALLBACK KeyboardProc(int nCode,WPARAM wParam,LPARAM lParam) // OK
{
	if(nCode == HC_ACTION)
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

		if(((DWORD)lParam & (1 << 30)) != 0 && ((DWORD)lParam & (1 << 31)) != 0 && GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
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

LONG WINAPI RefreshWindow(DEVMODEA* lpDevMode,DWORD dwFlags) // OK
{
	if(CheckWindowMode() != 0)
	{
		return DISP_CHANGE_SUCCESSFUL;
	}
	
	return ChangeDisplaySettingsA(lpDevMode,dwFlags);
}

HWND WINAPI CreateWindowProc(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam) // OK
{
	if(CheckWindowMode() != 0 && strcmp(lpClassName,"MU") == 0) // OK
	{
		dwExStyle = 0;
		lpWindowName = gProtect.m_MainInfo.WindowName;
		dwStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_BORDER | WS_CLIPCHILDREN;
		X = (GetSystemMetrics(SM_CXSCREEN)-nWidth) / 2;
		Y = (GetSystemMetrics(SM_CYSCREEN)-nHeight) / 2;
		nHeight += 30;
	}

	return CreateWindowExA(dwExStyle,lpClassName,gProtect.m_MainInfo.WindowName,dwStyle,X,Y,nWidth,nHeight,hWndParent,hMenu,hInstance,lpParam);
}

extern "C" _declspec(dllexport) void EntryProc() // OK
{
	if(gProtect.ReadMainFile("ServerInfo.sse") != 0)
	{
		SetByte(0x006B6654,0xA0); // Accent
		SetByte(0x004B4305,0xEB); // Crack (mu.exe)
		SetByte(0x004B47FE,0x75); // config.ini read error
		SetByte(0x004B4856,0xE9); // Crack (GameGuard)
		SetByte(0x004B4857,0xA6); // Crack (GameGuard)
		SetByte(0x004B4858,0x00); // Crack (GameGuard)
		SetByte(0x004B485B,0x90); // Crack (GameGuard)
		SetByte(0x004BEA9F,0xEB); // Crack (ResourceGuard)
		SetByte(0x004519F8,0x02); // Ctrl Fix
		SetByte(0x00509F1B,0x0D); // Fix Effect +13
		SetByte(0x006B7248,(gProtect.m_MainInfo.ClientVersion[0]+1)); // Version
		SetByte(0x006B7249,(gProtect.m_MainInfo.ClientVersion[2]+2)); // Version
		SetByte(0x006B724A,(gProtect.m_MainInfo.ClientVersion[3]+3)); // Version
		SetByte(0x006B724B,(gProtect.m_MainInfo.ClientVersion[5]+4)); // Version
		SetByte(0x006B724C,(gProtect.m_MainInfo.ClientVersion[6]+5)); // Version
		SetWord(0x006C41BC,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
		SetDword(0x00628B89,(DWORD)gProtect.m_MainInfo.ScreenShotPath);
		SetDword(0x006A74FC,(DWORD)&KeysProc);
		SetDword(0x006A74D0,(DWORD)&IconProc);
		SetDword(0x006A74AC,(DWORD)&RefreshWindow);
		SetDword(0x006A74F8,(DWORD)&CreateWindowProc);

		MemorySet(0x0041DBB0,0x90,0x1D); // Remove MuError.log

		MemorySet(0x004BBAB3,0x90,0x05); // Fix Reconnect Crash

		MemorySet(0x004CBC66,0x90,0x06); // Fix Move Cursor

		MemorySet(0x004ECAA0,0x90,0x1E); // Remove Reflect Effect

		MemorySet(0x005B7996,0x90,0x02); // Item Move Inventory -> Interface

		MemorySet(0x005B7A0F,0x90,0x02); // Item Move Interface -> Inventory

		MemorySet(0x0062594A,0x90,0x05); // Remove Text Select Screen 1
		
		MemorySet(0x00625996,0x90,0x05); // Remove Text Select Screen 2
		
		MemorySet(0x006259E2,0x90,0x05); // Remove Text Select Screen 3

		MemorySet(0x004B61D6,0x90,0x23B0); // Minimize Crash

		MemoryCpy(0x006B6694,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddress

		MemoryCpy(0x006B7250,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

		SetCompleteHook(0xE8,0x00596CEA,&DrawNewHealthBar);

		SetCompleteHook(0xFF,0x004DB63D,&ProtocolCoreEx);

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

		InitLua();

		InitLanguage();

		InitWing();

		InitMap();

		InitMiniMap();

		InitMonster();

		InitPrintPlayer();

		InitResolution();

		InitReconnect();

		InitServerList();

		InitShop();

		InitTexture();

		gTrayMode.Init();

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