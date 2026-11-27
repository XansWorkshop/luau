#pragma once

#include "lstate.h"

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

void xan_getFunctionName(lua_State* L, int idx, char* result, signed int length); // In lapi.cpp
