/**
 * @file FMODAudioEngine.cpp
 * 
 * @brief The code for the FMODAudioEngine functions
 * 
 * @author DePianoman
 */


#include "FMODAudioEngine.h"

/**
 * Get the static shared FMODAudioEngine instance, and initialize it if it doesn't exist
 * 
 * @see FMODAudioEngine
 * @return The FMODAudioEngine instance
 */
FMODAudioEngine* FMODAudioEngine::sharedEngine() {
    FMODAudioEngine** sharedEngine = reinterpret_cast<FMODAudioEngine**>(Utils::base + 0x3222A8);
    if (!*sharedEngine) {
        *sharedEngine = new FMODAudioEngine();
        (*sharedEngine)->init();
    }
    return *sharedEngine; 
}