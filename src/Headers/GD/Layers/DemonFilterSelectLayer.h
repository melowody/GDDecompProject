/**
 * @file DemonFilterSelectLayer.h
 * 
 * @brief Definitions for the DemonFilterSelectLayer functions
 * 
 * @author DePianoman
 */

#ifndef __DEMON_FILTER_SELECT_LAYER_H__
#define __DEMON_FILTER_SELECT_LAYER_H__

#include "cocos2d.h"
#include "FLAlertLayer.hpp"
#include "LevelSearchLayer.h"

using namespace cocos2d;

/**
 * The Demon Filter Select Layer
 * -----------------------------
 * Window that pops up to select a certain demon difficulty
 * 
 * Filters by that difficulty so the player only sees levels of that difficulty when searching
 */
class DemonFilterSelectLayer : public FLAlertLayer
{
public:
	CCArray *demonFaces; //0x01CC
	char pad_01D0[4]; //0x01D0
    unsigned int selectedTag; //0x01D4
	LevelSearchLayer *parent; //0x01D8

    /**
    * Select a rating from the Demon Filter Layer
    * 
    * @param pSender The CCObject that triggered this function
    */
    void selectRating(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x185150)(this, pSender);
    }

    /**
    * Closes the Demon Filter Layer
    * 
    * @param pSender The CCObject that triggered this function
    */
    void onClose(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x1851E0)(this, pSender);
    }
}; 

#endif