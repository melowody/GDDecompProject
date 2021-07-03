/**
 * @file hook_utils.hpp
 * 
 * @brief Definitions for the functions used for hooking
 * 
 * @author matcool
 */

#ifndef __HOOK_UTILS_HPP__
#define __HOOK_UTILS_HPP__

#include "includes.h"

/**
 * Hook
 * ----
 * A hook to an address
 */
struct Hook {
    uintptr_t address;
    // maybe change to std::function
    void* hook;
    void* detour;
};

/**
 * Hooks
 * -----
 * A class for all the current hooks
 */
namespace Hooks {
    inline std::vector<Hook> hooks;
    void init();
    void addHook(Hook hook);
    void unload();
};

#endif