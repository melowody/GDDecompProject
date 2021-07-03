/**
 * @file GameToolbox.h
 * 
 * @brief Definitions for the GameToolbox functions
 * 
 * @author DePianoman
 */

#ifndef __GAME_TOOLBOX_H__
#define __GAME_TOOLBOX_H__

#include <cocos2d.h>
#include "../../Utils.h"

using namespace cocos2d;

/**
 * Game Toolbox
 * ------------
 * General purpose class with miscellaneous functions that are useful as to not repeat code
 */
class GameToolbox {
public:

    /**
     * Aligns the items of a CCArray Horizontally by a certain width
     * 
     * @param arr The array of items to position
     * @param width The width between the items
     * @param separate Whether or not to separate the items from the beginning of each item or inbetween each item
     * @param base The base point to align to
     */
    static void alignItemsHorisontally(CCArray* arr, float width, bool separate, CCPoint base) {
        auto alignItemsHorisontallyAddr = Utils::base + 0x25B20;

        __asm {
            movss xmm1, width
            mov dl, separate
            mov ecx, arr
            push base.y
            push base.x
            call alignItemsHorisontallyAddr
            add esp, 0x8
        }
    }
};

#endif