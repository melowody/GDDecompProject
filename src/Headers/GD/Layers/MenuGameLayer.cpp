/**
 * @file MenuGameLayer.cpp
 * 
 * @brief The code for the MenuGameLayer functions
 * 
 * @author DePianoman
 */

#include "MenuGameLayer.h"

/**
 * Creates a MenuGameLayer
 * 
 * @return A pointer to the created MenuGameLayer instance
 */
MenuGameLayer* MenuGameLayer::create() {
    MenuGameLayer* ret = new MenuGameLayer();
    if (ret) {
        if (ret->init()) {
            ret->autorelease();
            return ret;
        }

        delete ret;
    }

    return nullptr;
} 

/**
 * The function that's called when the MenuGameLayer is clicked on
 * 
 * @param touch The CCTouch that was triggered
 * @param event Unused
 * 
 * @return Unknown
 */
bool MenuGameLayer::ccTouchBegan(CCTouch* touch, CCEvent* event) {

    // UNFINISHED

    CCPoint loc = touch->getLocation();
    CCPoint nodeLoc = this->convertToNodeSpace(loc);
    if (nodeLoc.x > 50.0f) {
        float dist = ccpDistance(this->m_pPlayerObject->getPosition(), nodeLoc);
        if (dist < 30.0f) {
            
            this->destroyPlayer();
        }
    }
    return;
}