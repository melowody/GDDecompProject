/**
 * @file RateDemonLayer.h
 * 
 * @brief Definitions for the RateDemonLayer functions
 * 
 * @author DePianoman
 */

#ifndef __RATE_DEMON_LAYER_H__
#define __RATE_DEMON_LAYER_H__

#include <cocos2d.h>
#include "../Sprites/CCMenuItemSpriteExtra.h"
#include "FLAlertLayer.hpp"

using namespace cocos2d;

/**
 * Rate Demon Layer
 * ----------------
 * The layer that comes up to rate a level a demon difficulty
 */
class RateDemonLayer : public FLAlertLayer
{
public:
	char pad_01CC[12]; //0x01CC
	CCMenuItemSpriteExtra* m_pCancelButton;
	CCArray* m_pDemonFaces;
	char pad_01E0[4];
	void* m_pUnknown; //0x01E4
	int m_nUnknown;
	bool m_bIsMod; //0x01EC
	char pad_01ED[7]; //0x01ED
	CCLayer* m_pLevelSearchLayer;

	/**
     * Triggered when any of the demon difficulties are clicked
     * 
     * @param pSender The button that triggered this function
     */
	void selectRating(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x214700)(this, pSender);
    }

	/**
     * Triggered when the Close Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onClose(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x214A10)(this, pSender);
    }

	/**
     * Triggered when the OK Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
	void onRate(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x214840)(this, pSender);
    }
}; 

#endif