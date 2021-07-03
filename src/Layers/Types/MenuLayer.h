/**
 * @file MenuLayer.h
 * 
 * @brief Definitions for the MenuLayer functions
 * 
 * @author DePianoman
 */

#ifndef __MENU_LAYER_HOOK_H__
#define __MENU_LAYER_HOOK_H__

#include "../../Headers/GD/Layers/MenuLayer.h"

/**
 * Menu Layer Hook
 * ---------------
 * The hook for MenuLayer
 */
namespace MenuLayerHook {
    inline bool(__thiscall* customSetup)(MenuLayer* self);

    void mem_init();
}

#endif