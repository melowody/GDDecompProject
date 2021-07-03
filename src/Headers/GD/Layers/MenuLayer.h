/**
 * @file MenuLayer.h
 * 
 * @brief Definitions for the MenuLayer functions
 * 
 * @author DePianoman
 */

#ifndef __MENU_LAYER_H__
#define __MENU_LAYER_H__

#include <cocos2d.h>
#include "FLAlertLayer.hpp"
#include "../Sprites/CCMenuItemSpriteExtra.h"

using namespace cocos2d;

/**
 * Menu Layer
 * ----------
 * The main menu for the game
 */
class MenuLayer : public CCLayer
{
public:
	char pad_011C[12]; //0x011C
    CCSprite *m_uProfileText;
	CCLabelBMFont* m_uUsernameLabel;
    CCMenuItemSpriteExtra* m_uProfileButton;
	char pad_0134[40]; //0x0134
	
	inline bool(__thiscall init)(MenuLayer* self);
    inline bool(__thiscall customSetup)(MenuLayer* self);

    /**
     * Triggered when the Daily Chest button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onDaily(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x1916E0)(this, pSender);
    }

    /**
     * Updates the user's profile button
     * 
     * @param pSender The button that triggered this function
     */
    void updateUserProfileButton() {
        return reinterpret_cast<void(__thiscall*)(CCObject*)>(Utils::base + 0x191700)(this);
    }

    /**
     * Triggered when the Profile Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onMyProfile(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191870)(this, pSender);
    }

    /**
     * Triggered when the Robtop Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onRobtop(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191940)(this, pSender);
    }

    /**
     * Triggered when Robtop's Facebook Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onFacebook(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191960)(this, pSender);
    }

    /**
     * Triggered when Robtop's Twitter Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onTwitter(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191980)(this, pSender);
    }

    /**
     * Triggered when Robtop's Youtube Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onYoutube(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x1919A0)(this, pSender);
    }

    /**
     * Triggered when the More Games Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onMoreGames(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x1919C0)(this, pSender);
    }

    /**
     * Triggered when the Achievements Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onAchievements(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191AF0)(this, pSender);
    }

    /**
     * Triggered when the Play Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
	void onPlay(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191B50)(this, pSender);
    }

    /**
     * Triggered when the Options Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onOptions(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191C30)(this, pSender);
    }

    /**
     * Triggered when the Statistics Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onStats(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191CA0)(this, pSender);
    }

    /**
     * Triggered when the Levels Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onCreator(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191CD0)(this, pSender);
    }

    /**
     * Triggered when the Icon Editor Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
	void onGarage(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191DC0)(this, pSender);
    }

    /**
     * Triggered when the Newgrounds Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onNewgrounds(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191E90)(this, pSender);
    }

    /**
     * Triggered when the Close Button is clicked
     * 
     * @param pSender The button that triggered this function
     */
    void onClose(CCObject* pSender) {
        return reinterpret_cast<void(__thiscall*)(CCObject*, CCObject*)>(Utils::base + 0x191FA0)(this, pSender);
    }
};

#endif