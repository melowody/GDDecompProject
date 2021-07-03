/**
 * @file GameSoundManager.cpp
 * 
 * @brief The code for the GameSoundManager functions
 * 
 * @author DePianoman
 */


#include "GameSoundManager.h"

/**
 * Gets the currently playing song
 * 
 * @return The name of the currently playing song
 */
std::string GameSoundManager::getCurrSong() {
    std::string outString;
    outString.assign(this->m_sCurrSong, 0, -1);
    return outString;
}