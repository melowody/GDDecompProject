/**
 * @file GameSoundManager.h
 * 
 * @brief Definitions for the GameSoundManager functions
 * 
 * @author DePianoman
 */

#ifndef __GAME_SOUND_MANAGER_H__
#define __GAME_SOUND_MANAGER_H__

#include <cocos2d.h>
#include "../../Utils.h"

using namespace cocos2d;

/**
 * Game Sound Manager
 * ------------------
 * The class that controls the currently playing sounds for the game
 */
class GameSoundManager : public CCNode {
protected:
    CCDictionary *m_pUnknown; //0x00EC
	CCDictionary *m_pUnknown2; //0x00F0
	char pad_00F4[16]; //0x00F4
	int32_t m_nUnknown; //0x0104
	std::string m_sCurrSong; 

public:
    std::string getCurrSong();

    /**
     * Get the static shared GameSoundManager instance, and initialize it if it doesn't exist
     * 
     * @see GameSoundManager
     * @return The GameSoundManager instance
     */
    static GameSoundManager* sharedState() {
        return reinterpret_cast<GameSoundManager*(__stdcall*)(void)>(Utils::base + 0x24800)();
    }

    /**
     * Start playing background music if none playing
     * 
     * @param song The song file name to start playing
     * @param b1 Unknown bool
     * @param b2 Unknown bool
     */
    static void playBackgroundMusic(std::string song, bool b1, bool b2) {
        reinterpret_cast<void(__stdcall*)(std::string, bool, bool)>(Utils::base + 0x252B0)(song, b1, b2);
    }
};

#endif