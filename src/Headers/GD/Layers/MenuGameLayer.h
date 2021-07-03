/**
 * @file MenuGameLayer.h
 * 
 * @brief Definitions for the MenuGameLayer functions
 * 
 * @author DePianoman
 */

#ifndef __MENU_GAME_LAYER_H__
#define __MENU_GAME_LAYER_H__

#include <cocos2d.h>
#include "../../Utils.h"
#include "../Sprites/PlayerObject.h"

using namespace cocos2d;

/**
 * Menu Game Layer
 * ---------------
 * The game layer that appears on the menu screen.
 * 
 * The player cannot play this Game Layer but they can interact with it (destroying players)
 */
class MenuGameLayer : public CCLayer {
protected:
    char pad_100[0x1C]; // 0x100
    bool m_bUnknown; // 0x11C
    int m_nUnknown1; // 0x120
    CCPoint m_pUnknown; // 0x124
    PlayerObject* m_pPlayerObject; // 0x12C
    int m_nUnknown3; // 0x130
    void* m_pGroundLayer; // 0x134
    float m_fUnknown; // 0x138

public:
    MenuGameLayer() {
        this->m_pUnknown = CCPoint();
    }

    ~MenuGameLayer() {
        reinterpret_cast<void(__thiscall*)(MenuGameLayer*)>(Utils::base + 0x18E670)(this);
    }

    static MenuGameLayer* create();

    /**
     * Initializes the MenuGameLayer
     * 
     * @return true if successful, false if not
     */
    virtual bool init() {
        return reinterpret_cast<bool(__thiscall*)(MenuGameLayer*)>(Utils::base + 0x18E770)(this);
    }

    /**
     * Updates the visuals for the MenuGameLayer
     */
    virtual void update(float delta) {
        return reinterpret_cast<void(__thiscall*)(MenuGameLayer*, float)>(Utils::base + 0x18F190)(this, delta);
    }

    /**
     * Destroys the player currently on the MenuGameLayer
     */
    void destroyPlayer() {
        reinterpret_cast<void(__thiscall*)(MenuGameLayer*)>(Utils::base + 0x190100)(this);
    }

    /**
     * Registers the MenuGameLayer to receive touch inputs
     */
    virtual void registerWithTouchDispatcher() {
        return reinterpret_cast<void(__thiscall*)(MenuGameLayer*)>(Utils::base + 0x4DBE0)(this);
    }

    /**
     * @link CCTouchDelegate#ccTouchBegan
     */
    virtual bool ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent) {
        return reinterpret_cast<bool(__thiscall*)(MenuGameLayer*, CCTouch*, CCEvent*)>(Utils::base + 0x1903A0)(this, pTouch, pEvent);
    };

    /**
     * @link CCTouchDelegate#ccTouchMoved
     */
    virtual void ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent) {
        return;
    }

    /**
     * @link CCTouchDelegate#ccTouchEnded
     */
    virtual void ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent) {
        return;
    }

    /**
     * @link CCTouchDelegate#ccTouchCancelled
     */
    virtual void ccTouchCancelled(CCTouch* pTouch, CCEvent* pEvent) {
        return;
    }
};

#endif