/**
 * @file GameLevelManager.h
 * 
 * @brief Definitions for the GameLevelManager functions
 * 
 * @author DePianoman
 */


#ifndef __GAME_LEVEL_MANAGER_H__
#define __GAME_LEVEL_MANAGER_H__

#include <cocos2d.h>
#include "../../Utils.h"

using namespace cocos2d;

class GameLevelManager : public CCNode {

    char pad_00EC[4]; //0x00EC
	CCDictionary *m_pUnknown; //0x00F0
	char pad_00F4[312]; //0x00F4

public:
    static GameLevelManager* sharedManager();

    int getIntForKey(const char* key);
};

#endif