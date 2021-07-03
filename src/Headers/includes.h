/**
 * @file includes.h
 * 
 * @brief Includes for use all over the project
 * 
 * @author DePianoman
 */

#ifndef __INCLUDES_H__
#define __INCLUDES_H__

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
// shut up cocos
#pragma warning(push, 0)
#include <cocos2d.h>
USING_NS_CC;
#pragma warning(pop)
#include "MinHook.h"

#endif