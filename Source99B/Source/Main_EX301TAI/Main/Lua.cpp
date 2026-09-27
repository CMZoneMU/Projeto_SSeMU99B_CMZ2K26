#include "stdafx.h"
#include "Lua.h"
#include "LuaLoader.h"
#include "Offset.h"
#include "Util.h"

static int sentinel_ = 0;

int LockCharacterAction = 0;

void InitLua() // OK
{
	#if(LUA_SCRIPT == 1)

	SetCompleteHook(0xE8,0x006B20A9,&LuaOnStartMain);

	SetCompleteHook(0xE8,0x006CD0D0,&LuaOnTimerThread);

	SetCompleteHook(0xE8,0x006CDCBD,&LuaOnTimerThread);

	SetCompleteHook(0xE8,0x006CFC6C,&LuaOnTimerThread);

	SetCompleteHook(0xE8,0x006CF446,&LuaLockActions);

	#endif
}

void LuaOnStartMain() // OK
{
	#if(LUA_SCRIPT == 1)

	gLuaLoader.MainLoader();

	((void(*)())0x006ADA8E)();

	#endif
}

void LuaOnTimerThread() // OK
{
	#if(LUA_SCRIPT == 1)

	gLuaLoader.MainProcThread();

	((void(*)())0x00605580)();

	#endif
}

void LuaLockActions() // OK
{
	#if(LUA_SCRIPT == 1)

	if(LockCharacterAction != 0)
	{
		return;
	}

	((void(*)())0x005F10E0)();

	#endif
}

#if(LUA_SCRIPT == 1)

void LuaFunction(lua_State* L) // OK
{
	lua_register(L,"Console",LuaConsole);

	lua_register(L,"glColor3f",LuaColor3f);
	lua_register(L,"glColor4f",LuaColor4f);

	lua_register(L,"EnableAlphaBlend",LuaEnableAlphaBlend);
	lua_register(L,"EnableAlphaBlend2",LuaEnableAlphaBlend2);
	lua_register(L,"EnableAlphaBlendMinus",LuaEnableAlphaBlendMinus);
	lua_register(L,"EnableAlphaTest",LuaEnableAlphaTest);
	lua_register(L,"EnableLightMap",LuaEnableLightMap);
	lua_register(L,"DisableAlphaBlend",LuaDisableAlphaBlend);
	
	lua_register(L,"RenderText",LuaRenderText);
	lua_register(L,"RenderTipText",LuaRenderTipText);

	lua_register(L,"SetBackColor",LuaSetBackColor);
	lua_register(L,"SetFontType",LuaSetFontType);
	lua_register(L,"SetTextColor",LuaSetTextColor);

	lua_register(L,"RenderColor",LuaRenderColor);
	lua_register(L,"RenderItem3D",LuaRenderItem3D);
	lua_register(L,"RenderMessage",LuaRenderMessage);

	lua_register(L,"RenderBitmap",LuaRenderBitmap);
	lua_register(L,"RenderBitmapRotate",LuaRenderBitRotation);
	lua_register(L,"LoadBitmapJPG",LuaLoadImageJPG);
	lua_register(L,"LoadBitmapTGA",LuaLoadImageTGA);

	lua_register(L,"LoadSound",LuaLoadSound);
	lua_register(L,"PlaySound", LuaPlaySound);

	lua_register(L,"MousePosX",LuaMousePosX);
	lua_register(L,"MousePosY",LuaMousePosY);
	lua_register(L,"MouseLButton",LuaMouseLButton);
	lua_register(L,"MouseRButton",LuaMouseRButton);
	lua_register(L,"CheckMouseIn",LuaCheckMouseIn);

	lua_register(L,"GetMainScene",LuaGetMainScene);
	lua_register(L,"GetMainResolution",LuaGetMainResolution);
	lua_register(L,"GetCharacterMap",LuaGetObjectMap);
	lua_register(L,"CheckWindowOpen",LuaGetWindowState);
	lua_register(L,"CharacterLockAction",LuaCharacterLockAction);
}

int LuaRequire(lua_State* L)
{
	char buff[256];

	wsprintf(buff,"Script\\%s.lua",luaL_checklstring(L,1,0));

	lua_settop(L,1);
	lua_getfield(L,LUA_REGISTRYINDEX,"_LOADED");
	lua_getfield(L,2,buff);

	if(lua_toboolean(L,-1))
	{
		if(lua_touserdata(L,-1) == ((void*)&sentinel_))
		{
			Console(1,"[ScriptLoader] Error in Lua-file. %s",lua_tostring(L,-1));
			return 0;
		}
	}

	if(luaL_loadfile(L,buff))
	{
		Console(1,"[ScriptLoader] Could not load '%s'. %s",buff,lua_tostring(L,-1));
		return 0;
	}

	lua_pushlightuserdata(L,((void*)&sentinel_));
	lua_setfield(L,2,buff);
	lua_pushstring(L,buff);
	
	lua_call(L,1,1);

	if(lua_type(L,-1))
	{
		lua_setfield(L,2,buff);
	}

	lua_getfield(L,2,buff);

	if(lua_touserdata(L,-1) == ((void*)&sentinel_))
	{
		lua_pushboolean(L,1);
		lua_pushvalue(L,-1);
		lua_setfield(L,2,buff);
	}

	return 1;
}

int LuaConsole(lua_State* L) // OK
{
	if(lua_gettop(L) != 2)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,2);
	}

	int aValue = lua_tointeger(L,1);

	const char* aString = lua_tostring(L,2);

	Console(aValue,"%s",aString);

	return 1;
}

int LuaColor3f(lua_State* L) // OK
{
	if(lua_gettop(L) != 3)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,3);
	}

	float aValue = (float)lua_tonumber(L,1);

	float bValue = (float)lua_tonumber(L,2);

	float cValue = (float)lua_tonumber(L,3);

	glColor3f(aValue,bValue,cValue);

	return 1;
}

int LuaColor4f(lua_State* L) // OK
{
	if(lua_gettop(L) != 4)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,4);
	}

	float aValue = (float)lua_tonumber(L,1);

	float bValue = (float)lua_tonumber(L,2);

	float cValue = (float)lua_tonumber(L,3);

	float dValue = (float)lua_tonumber(L,4);

	glColor4f(aValue,bValue,cValue,dValue);

	return 1;
}

int LuaEnableAlphaBlend(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L, LUA_SCRIPT_CODE_ERROR0);
	}

	EnableAlphaBlend();

	return 1;
}

int LuaEnableAlphaBlend2(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L, LUA_SCRIPT_CODE_ERROR0);
	}

	EnableAlphaBlend2();

	return 1;
}

int LuaEnableAlphaBlendMinus(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L, LUA_SCRIPT_CODE_ERROR0);
	}

	EnableAlphaBlendMinus();

	return 1;
}

int LuaEnableAlphaTest(lua_State* L) // OK
{
	if(lua_gettop(L) != 1)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,1);
	}

	int aValue = lua_tointeger(L,1);

	EnableAlphaTest(((aValue!=0)?true:false));

	return 1;
}

int LuaEnableLightMap(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L, LUA_SCRIPT_CODE_ERROR0);
	}

	EnableLightMap();

	return 1;
}

int LuaDisableAlphaBlend(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L, LUA_SCRIPT_CODE_ERROR0);
	}

	DisableAlphaBlend();

	return 1;
}

int LuaRenderText(lua_State* L) // OK
{
	if(lua_gettop(L) != 3)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,3);
	}

	int aValue = lua_tointeger(L,1);

	int bValue = lua_tointeger(L,2);

	const char* cValue = lua_tostring(L,3);

	HDC hdc = GetDC(*(HWND*)(MAIN_WINDOW));

	SIZE sz;

	GetTextExtentPoint(hdc,cValue,strlen(cValue),&sz);

	pDrawText((aValue - (640 * sz.cx / (DWORD)MAIN_RESOLUTION_X >> 1)),bValue,(char*)cValue,0,0,0);

	return 1;
}

int LuaRenderTipText(lua_State* L) // OK
{
	if(lua_gettop(L) != 3)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,3);
	}

	int aValue = lua_tointeger(L,1);

	int bValue = lua_tointeger(L,2);

	const char* cValue = lua_tostring(L,3);

	pRenderTipText(aValue,bValue,(char*)cValue);

	return 1;
}

int LuaSetBackColor(lua_State* L) // OK
{
	if(lua_gettop(L) != 4)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,4);
	}

	int aValue = lua_tointeger(L,1);

	int bValue = lua_tointeger(L,2);

	int cValue = lua_tointeger(L,3);

	int dValue = lua_tointeger(L,4);

	pSetBGTextColor = ((dValue<<24)+(cValue<<16)+(bValue<<8)+aValue);

	return 1;
}

int LuaSetFontType(lua_State* L) // OK
{
	if(lua_gettop(L) != 1)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,1);
	}

	int aValue = lua_tointeger(L,1);

	switch (aValue)
	{
		case 0:
			SelectObject(pFontHDC,pFontNormal);
			break;
		case 1:
			SelectObject(pFontHDC,pFontBold);
			break;
		case 2:
			SelectObject(pFontHDC,pFontBig);
			break;
		case 3:
			SelectObject(pFontHDC,pFontFixed);
			break;
	}

	return 1;
}

int LuaSetTextColor(lua_State* L) // OK
{
	if(lua_gettop(L) != 4)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,4);
	}

	int aValue = lua_tointeger(L,1);

	int bValue = lua_tointeger(L,2);

	int cValue = lua_tointeger(L,3);

	int dValue = lua_tointeger(L,4);

	pSetTextColor = ((dValue<<24)+(cValue<<16)+(bValue<<8)+aValue);

	return 1;
}

int LuaRenderColor(lua_State* L) // OK
{
	if(lua_gettop(L) != 4)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,4);
	}

	float aValue = (float)lua_tonumber(L,1);

	float bValue = (float)lua_tonumber(L,2);

	float cValue = (float)lua_tonumber(L,3);

	float dValue = (float)lua_tonumber(L,4);

	pDrawBarForm(aValue,bValue,cValue,dValue,0,0);

	return 1;
}

int LuaRenderItem3D(lua_State* L) // OK
{
	if(lua_gettop(L) != 9)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,9);
	}

	float aValue = (float)lua_tonumber(L,1);

	float bValue = (float)lua_tonumber(L,2);

	float cValue = (float)lua_tonumber(L,3);

	float dValue = (float)lua_tonumber(L,4);

	int eValue = lua_tointeger(L,5);

	int fValue = lua_tointeger(L,6);

	int gValue = lua_tointeger(L,7);

	int hValue = lua_tointeger(L,8);

	int iValue = lua_tointeger(L,9);

	glPopMatrix();
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
 
	pglViewport2(0,0,*(DWORD*)MAIN_RESOLUTION_X,*(DWORD*)MAIN_RESOLUTION_Y);
	pgluPerspective2(1.f,(float)(*(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y),20.f,2000.f);
 
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

	pGetOpenGLMatrix(pCameraMatrix);
	pEnableDepthTest();
	pEnableDepthMask();

	pRenderItem3D(aValue,bValue,cValue,dValue,eValue,fValue<<3,gValue,hValue,iValue);

	glLoadIdentity();

	int vPos = 0;
	GLfloat* CameraPosition = pCameraPosition;

	glTranslatef(-CameraPosition[0],-CameraPosition[1],-CameraPosition[2]);

	pGetOpenGLMatrix(pCameraMatrix);

	pVectorIRotate(100,100,&vPos,1);

	glPopMatrix();
	glPopMatrix();

	pBeginBitmap();

	glColor3f(1,1,1);

	EnableAlphaTest(true);

	return 1;
}

int LuaRenderMessage(lua_State* L) // OK
{
	if(lua_gettop(L) != 2)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,2);
	}

	const char* aValue = lua_tostring(L,1);

	int bValue = lua_tointeger(L,2);

	pDrawMessage((char*)aValue,bValue);

	return 1;
}

int LuaRenderBitmap(lua_State* L) // OK
{
	if(lua_gettop(L) != 11)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,11);
	}

	int aValue = lua_tointeger(L,1);

	float bValue = (float)lua_tonumber(L,2);

	float cValue = (float)lua_tonumber(L,3);

	float dValue = (float)lua_tonumber(L,4);

	float eValue = (float)lua_tonumber(L,5);

	float fValue = (float)lua_tonumber(L,6);

	float gValue = (float)lua_tonumber(L,7);

	float hValue = (float)lua_tonumber(L,8);

	float iValue = (float)lua_tonumber(L,9);

	int jValue = lua_tointeger(L,10);

	int kValue = lua_tointeger(L,11);

	pDrawImage(aValue,bValue,cValue,dValue,eValue,fValue,gValue,hValue,iValue,jValue,kValue,0.0);

	return 1;
}

int LuaRenderBitRotation(lua_State* L) // OK
{
	if(lua_gettop(L) != 6)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,6);
	}

	int aValue = lua_tointeger(L,1);

	float bValue = (float)lua_tonumber(L,2);

	float cValue = (float)lua_tonumber(L,3);

	float dValue = (float)lua_tonumber(L,4);

	float eValue = (float)lua_tonumber(L,5);

	float fValue = (float)lua_tonumber(L,6);

	pRenderBitmapRotate(aValue,bValue,cValue,dValue,eValue,fValue);

	return 1;
}

int LuaLoadImageJPG(lua_State* L) // OK
{
	if(lua_gettop(L) != 2)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,2);
	}

	const char* aValue = lua_tostring(L,1);

	int bValue = lua_tointeger(L,2);

	pLoadImageJPG((char*)aValue,bValue,GL_NEAREST,GL_CLAMP,0,1);

	return 1;
}

int LuaLoadImageTGA(lua_State* L) // OK
{
	if(lua_gettop(L) != 2)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,2);
	}

	const char* aValue = lua_tostring(L,1);

	int bValue = lua_tointeger(L,2);

	pLoadImageTGA((char*)aValue,bValue,GL_NEAREST,GL_CLAMP,0,1);

	return 1;
}

int LuaLoadSound(lua_State* L) // OK
{
	if(lua_gettop(L) != 2)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,2);
	}

	int aValue = lua_tointeger(L,1);

	const char* bValue = lua_tostring(L,2);

	pLoadWaveFile(aValue,(char*)bValue ,2,1);

	return 1;
}

int LuaPlaySound(lua_State* L) // OK
{
	if(lua_gettop(L) != 2)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,2);
	}

	int aValue = lua_tointeger(L,1);
	
	int bValue = lua_tointeger(L,2);

	pPlayBuffer(aValue,0,bValue);

	return 1;
}

int LuaMousePosX(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR0);
	}

	lua_pushinteger(L,pCursorX);

	return 1;
}

int LuaMousePosY(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR0);
	}

	lua_pushinteger(L,pCursorY);

	return 1;
}

int LuaMouseLButton(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR0);
	}

	lua_pushinteger(L,pMouseLButton);

	return 1;
}

int LuaMouseRButton(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR0);
	}

	lua_pushinteger(L,pMouseRButton);

	return 1;
}

int LuaCheckMouseIn(lua_State* L) // OK
{
	if(lua_gettop(L) != 4)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,4);
	}

	int aValue = lua_tointeger(L,1);

	int bValue = lua_tointeger(L,2);

	int cValue = lua_tointeger(L,3);

	int dValue = lua_tointeger(L,4);

	lua_pushinteger(L,pMouseOnZone(aValue,bValue,cValue,dValue,1));

	return 1;
}

int LuaGetMainResolution(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR0);
	}

	lua_pushinteger(L,*(DWORD*)(MAIN_RESOLUTION));

	return 1;
}

int LuaGetMainScene(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR0);
	}

	lua_pushinteger(L,*(DWORD*)(MAIN_SCREEN_STATE));

	return 1;
}

int LuaGetObjectMap(lua_State* L) // OK
{
	if(lua_gettop(L) != 0)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR0);
	}

	lua_pushinteger(L,*(DWORD*)(MAIN_CURRENT_MAP));

	return 1;
}

int LuaGetWindowState(lua_State* L) // OK
{
	if(lua_gettop(L) != 1)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,1);
	}

	int aValue = lua_tointeger(L,1);

	if(pCheckWindow(aValue) != 0)
	{
		lua_pushinteger(L,1);
	}
	else
	{
		lua_pushinteger(L,0);
	}

	return 1;
}

int LuaCharacterLockAction(lua_State* L) // OK
{
	if(lua_gettop(L) != 1)
	{
		return luaL_error(L,LUA_SCRIPT_CODE_ERROR1,1);
	}

	int aValue = lua_tointeger(L,1);

	if(aValue == 1)
	{
		*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+952) = 0;

		pSetPlayerStop(*(DWORD*)(MAIN_VIEWPORT_STRUCT));
	}

	LockCharacterAction = aValue;

	return 1;
}

#endif