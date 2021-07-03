/**
 * @file dllmain.cpp
 * 
 * @brief The entry point for the injected DLL (will be changed to a cocos2d-x application on finish)
 * 
 * @author matcool
 */
#include "Headers/Utils.h"
#include "Headers/hook_utils.hpp"
#include "MinHook.h"
#include <cocos2d.h>

size_t Utils::base = reinterpret_cast<size_t>(GetModuleHandle(0));

DWORD WINAPI my_thread(void* hModule) {

    /*
    // Create a terminal to output to for debugging
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONIN$", "r", stdin);
    freopen_s(&fp, "CONOUT$", "w", stderr);*/

    Hooks::init();

    return 0;
}  

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0x1000, my_thread, hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

