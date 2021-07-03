/**
 * @file PlayLayer.h
 * 
 * @brief Definitions for the PlayLayer functions
 * 
 * @author DePianoman
 */

#ifndef __PLAY_LAYER_H__
#define __PLAY_LAYER_H__

#include <cocos2d.h>
#include "GJBaseGameLayer.h"

/**
 * Play Layer
 * ----------
 * The layer that shows when you're playing the game
 */
class PlayLayer : public GJBaseGameLayer {
public:

    /**
     * Updates the graphics for the play layer
     */
    void updateVisibility() {
        reinterpret_cast<void(__thiscall*)(PlayLayer*)>(Utils::base + 0x205460)(this);
    }
};

#endif