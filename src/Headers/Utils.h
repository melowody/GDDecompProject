/**
 * @file Utils.h
 * 
 * @brief Definitions for general use functions and macros throughout the project
 * 
 * @author DePianoman, camden314
 */

#ifndef __UTILS_H__
#define __UTILS_H__

#include <cocos2d.h>

/**
 * A macro to add a getter for an item at an offset
 * 
 * @param __TYPE__ The type of the member
 * @param __GETTER__ The name of the getter
 * @param __OFFSET__ The offset of the member
 */
#define CLASS_PARAM(__TYPE__, __GETTER__, __OFFSET__) \
    inline __TYPE__& _##__GETTER__() { \
        return *((__TYPE__*)((long)this + __OFFSET__)); \
    } // Thanks camden for this code

using namespace cocos2d;

/**
 * Utils
 * -----
 * General purpose utils to help throughout code
 */
class Utils {
public:
	static size_t base;

	static CCSprite* createSprite(unsigned char data[]);
	static CCSprite* createSprite(unsigned char data[], const char* img);
};

#endif