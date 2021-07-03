/**
 * @file hook_utils.cpp
 * 
 * @brief The code for the Hook Utils functions
 * 
 * @author matcool
 */

#include "hook_utils.hpp"
#include "../Layers/init.h"

/**
 * Initialize all the hooks
 */
void Hooks::init() {
    MH_Initialize();
    Layers::init();
    MH_EnableHook(MH_ALL_HOOKS);
}

/**
 * Adds a hook to the list of current hooks
 * 
 * @param hook The hook to add
 */
void Hooks::addHook(Hook hook) {
    auto target = reinterpret_cast<void*>(hook.address);
    MH_CreateHook(target, hook.hook, reinterpret_cast<void**>(hook.detour));
    MH_EnableHook(target);
    hooks.push_back(hook);
}

/**
 * Unload all the hooks
 */
void Hooks::unload() {
    MH_Uninitialize();
}