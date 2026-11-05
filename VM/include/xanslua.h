#pragma once

#include "lstate.h"

typedef void (*xan_WriteStringReceiver)(lua_State* L, const char* s, size_t l);
static xan_WriteStringReceiver writeStringReceiver;
LUALIB_API void xan_setOutputHandler(xan_WriteStringReceiver mtd)
{
    writeStringReceiver = mtd;
}

LUALIB_API void xan_getLuauConfig(int* maxUserdataTags, int* maxLightUserdataTags, int* vectorComponentCount, int* isDoublePrecision, int* idSize)
{
    if (maxUserdataTags)
    {
        *maxUserdataTags = LUA_UTAG_LIMIT;
    }
    if (maxLightUserdataTags)
    {
        *maxLightUserdataTags = LUA_LUTAG_LIMIT;
    }
    if (vectorComponentCount)
    {
        *vectorComponentCount = LUA_VECTOR_SIZE;
    }
    if (isDoublePrecision)
    {
        *isDoublePrecision = LUA_VECTOR_DOUBLE == 1;
    }
    if (idSize)
    {
        *idSize = LUA_IDSIZE;
    }
}

LUALIB_API void xan_getFunctionName(lua_State* L, int idx, char* result, size_t length); // In lapi.cpp

LUALIB_API int xan_getLineNumber(lua_State* L, int level)
{
    lua_Debug ar;
    if (lua_getinfo(L, level, "l", &ar) && ar.currentline > 0)
    {
        return ar.currentline;
    }
    return -1;
}
