/**
 * @file GameLevelManager.cpp
 * 
 * @brief The code for the GameLevelManager functions
 * 
 * @author DePianoman
 */


#include "GameLevelManager.h"

/**
 * Get the static shared GameLevelManager instance, and initialize it if it doesn't exist
 * 
 * @see GameLevelManager
 * @return The GameLevelManager instance
 */
GameLevelManager* GameLevelManager::sharedManager() {
    GameLevelManager** sharedManager = reinterpret_cast<GameLevelManager**>(Utils::base + 0x3222C8);
    if (!*sharedManager) {
        *sharedManager = new GameLevelManager();
        (*sharedManager)->init();
    }
    return *sharedManager; 
}

/**
 * Gets the integer value associated with a key in the GameLevelManager
 * 
 * @param key The key
 * 
 * @return The integer associated with the given key
 */
int GameLevelManager::getIntForKey(const char* key) {

    // Get the value from the key and return it
    std::string keyStr;
    keyStr.assign(key, 0, strlen(key));
    const CCString* valueStr = this->m_pUnknown->valueForKey(keyStr);
    return valueStr->intValue();

}