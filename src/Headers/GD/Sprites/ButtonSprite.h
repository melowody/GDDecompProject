/**
 * @file ButtonSprite.h
 * 
 * @brief Definitions for the ButtonSprite functions
 * 
 * @author DePianoman
 */

#ifndef __BUTTON_SPRITE_H__
#define __BUTTON_SPRITE_H__

#include <cocos2d.h>
#include <cocos-ext.h>

using namespace cocos2d;

/**
 * Button Sprite
 * -------------
 * A button sprite
 */
class ButtonSprite : public CCSprite
{
public:
	uint32_t N00001481; //0x01E4
	char pad_01E8[8]; //0x01E8
	float N00001484; //0x01F0
	char pad_01F4[8]; //0x01F4
	CCLabelBMFont* buttonTextLabel; //0x01FC
	char pad_0200[8]; //0x0200
	cocos2d::extension::CCScale9Sprite* backSprite; //0x0208
	char pad_020C[4]; //0x020C
	float N0000148C; //0x0210
	char pad_0214[8]; //0x0214
	std::string buttonText; //0x021C

	/**
	 * Initializes the Button Sprite
	 * 
	 * @param text The text on the button
	 * @param num1 Unknown
	 * @param num2 Unknown
	 * @param scale The scale of the button
	 * @param bool1 Unknown
	 * @param font The name of the font to use on the button
	 * @param bg The name of the bg file to use
	 * @param float1 Unknown
	 */
	bool __thiscall init(const char* text, int num1, int num2, float scale, bool bool1, const char* font, const char* bg, float float1) {
		return reinterpret_cast<bool(__thiscall*)(ButtonSprite*, const char*, int, int, float, bool, const char*, const char*, float)>(Utils::base + 0x138A0)(this, text, num1, num2, scale, bool1, font, bg, float1);
	} 
}; 

#endif