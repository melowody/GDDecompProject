/**
 * @file LevelSearchLayer.h
 * 
 * @brief Definitions for the LevelSearchLayer functions
 * 
 * @author DePianoman
 */

#ifndef __LEVEL_SEARCH_LAYER_H__
#define __LEVEL_SEARCH_LAYER_H__

#include <cocos2d.h>

using namespace cocos2d;

/**
 * Level Search Layer
 * ------------------
 * The layer that pops up when you click the Search button
 * 
 * Allows a player to enter filters in order to search for a level they want to play
 */
class LevelSearchLayer : public CCLayer
{
public:
	char pad_011C[8]; //0x011C
	
	bool init();
}; 

#endif