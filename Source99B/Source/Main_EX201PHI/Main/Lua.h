#pragma once

#define LUA_SCRIPT_CODE_ERROR0 "[No argument's allowed]"
#define LUA_SCRIPT_CODE_ERROR1 "[%d argument's expected]"
#define LUA_SCRIPT_CODE_ERROR2 "[Minimum %d argument's expected]"

void InitLua();
void LuaOnStartMain();
void LuaOnTimerThread();
void LuaLockActions();
#if(LUA_SCRIPT == 1)
void LuaFunction(lua_State* L);
int LuaRequire(lua_State* L);
int LuaConsole(lua_State* L);
int LuaColor3f(lua_State* L);
int LuaColor4f(lua_State* L);
int LuaEnableAlphaBlend(lua_State* L);
int LuaEnableAlphaBlend2(lua_State* L);
int LuaEnableAlphaBlendMinus(lua_State* L);
int LuaEnableAlphaTest(lua_State* L);
int LuaEnableLightMap(lua_State* L);
int LuaDisableAlphaBlend(lua_State* L);
int LuaRenderText(lua_State* L);
int LuaRenderTipText(lua_State* L);
int LuaSetBackColor(lua_State* L);
int LuaSetFontType(lua_State* L);
int LuaSetTextColor(lua_State* L);
int LuaRenderColor(lua_State* L);
int LuaRenderItem3D(lua_State* L);
int LuaRenderMessage(lua_State* L);
int LuaRenderBitmap(lua_State* L);
int LuaRenderBitRotation(lua_State* L);
int LuaLoadImageJPG(lua_State* L);
int LuaLoadImageTGA(lua_State* L);
int LuaLoadSound(lua_State* L);
int LuaPlaySound(lua_State* L);
int LuaMousePosX(lua_State* L);
int LuaMousePosY(lua_State* L);
int LuaMouseLButton(lua_State* L);
int LuaMouseRButton(lua_State* L);
int LuaCheckMouseIn(lua_State* L);
int LuaGetMainResolution(lua_State* L);
int LuaGetMainScene(lua_State* L);
int LuaGetObjectMap(lua_State* L);
int LuaGetWindowState(lua_State* L);
int LuaCharacterLockAction(lua_State* L);
#endif