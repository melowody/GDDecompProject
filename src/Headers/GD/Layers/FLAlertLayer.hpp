/**
 * @file FLAlertLayer.hpp
 * 
 * @brief Definitions for the FLAlertLayer functions
 * 
 * @author HJFod, cos8o, poweredbypie
 */

#pragma once

#include <cocos2d.h>
#include "../../Utils.h"

// Code by HJFod
// thanks pie <3 & cos8o too! - HJFod

class FLAlertLayer;

class FLAlertLayerProtocol {
public:
	virtual void FLAlert_Clicked(FLAlertLayer*, bool btn2) {};
};

class CCMenuItemSpriteExtraGD;
class ScrollingLayer;

#pragma runtime_checks("s", off)
class FLAlertLayer : public cocos2d::CCLayerColor {
public:
	cocos2d::CCMenu* m_pButtonMenu;
	int m_controlConnected;
	cocos2d::CCObject* m_alertProtocol;
	cocos2d::CCScene* m_scene;
	bool m_reverseKeyBack;
	ccColor3B m_color;
	cocos2d::CCLayer* m_mainLayer;
	int m_nZOrder;
	bool m_noElasticity;
	ccColor3B m_color2;
	CCMenuItemSpriteExtraGD* m_button1;
	CCMenuItemSpriteExtraGD* m_button2;
	ScrollingLayer* m_scrollingLayer;
	int m_joystickConnected;
	bool m_containsBorder;
	bool m_noAction;

	//CCNode vtable
	virtual void onEnter() {
		return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
			Utils::base + 0x23750
			)(this);
	}
	virtual void registerWithTouchDispatcher() {
		return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
			Utils::base + 0x236F0
			)(this);
	}

	//CCTouchDelegate vtable
	virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
		return reinterpret_cast<bool(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
			Utils::base + 0x233C0
			)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
	}
	virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
		return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
			Utils::base + 0x23510
			)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
	}
	virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
		return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
			Utils::base + 0x23450
			)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
	}
	virtual void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent) {
		return reinterpret_cast<void(__thiscall*)(char*, cocos2d::CCTouch*, cocos2d::CCEvent*)>(
			Utils::base + 0x234C0
			)(reinterpret_cast<char*>(this) + 0xEC, pTouch, pEvent);
	}

	//CCKeyboardDelegate vtable
	virtual void keyDown(cocos2d::enumKeyCodes key) {
		return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::enumKeyCodes)>(
			Utils::base + 0x23250
			)(this, key);
	}

	//CCKeypadDelegate vtable
	virtual void keyBackClicked() {
		return reinterpret_cast<void(__thiscall*)(char*)>(
			Utils::base + 0x232C0
			)(reinterpret_cast<char*>(this) + 0xF4);
	}

	//vtable
	virtual void show() {
		return reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
			Utils::base + 0x23560
			)(this);
	}
	FLAlertLayer() {
		reinterpret_cast<void(__thiscall*)(FLAlertLayer*)>(
			Utils::base + 0x224B0
			)(this);
	}

	void onBtn1(cocos2d::CCObject* btn) {
		return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::CCObject*)>(
			Utils::base + 0x23340
			)(this, btn);
	}
	void onBtn2(cocos2d::CCObject* btn) {
		return reinterpret_cast<void(__thiscall*)(FLAlertLayer*, cocos2d::CCObject*)>(
			Utils::base + 0x23380
			)(this, btn);
	}

	static FLAlertLayer* create(
		FLAlertLayerProtocol* target,
		const char* title,
		const char* btn1,
		const char* btn2,
		std::string caption
	) {
		//static_assert(sizeof(std::string) == 24, "std::string in debug mode does not work correctly with FLAlertLayer!");

		auto pRet = reinterpret_cast<FLAlertLayer * (__fastcall*)(FLAlertLayerProtocol*, const char*,
			const char*, const char*, std::string)>(
				Utils::base + 0x22680
				)(target, title, btn1, btn2, caption);

		//clean stack.
		__asm add esp, 0x20
		return pRet;
	}

	static FLAlertLayer* create(
		FLAlertLayerProtocol* target,
		const char* title,
		const char* btn1,
		const char* btn2,
		float width,
		std::string caption
	) {
		//static_assert(sizeof(std::string) == 24, "std::string in debug mode does not work correctly with FLAlertLayer!");
		auto pRet = reinterpret_cast<FLAlertLayer * (__fastcall*)(FLAlertLayerProtocol*, const char*,
			const char*, const char*, float, std::string)>(
				Utils::base + 0x22730
				)(target, title, btn1, btn2, width, caption);

		__asm add esp, 0x24
		return pRet;
	}

	static FLAlertLayer* create(
		FLAlertLayerProtocol* target,
		const char* title,
		const char* btn1,
		const char* btn2,
		float layerh,
		intptr_t l1,
		intptr_t l2,
		std::string caption
	) {
		auto pRet = reinterpret_cast<FLAlertLayer * (__fastcall*)(
			FLAlertLayerProtocol*,
			const char*,
			const char*,
			const char*,
			float,
			intptr_t,
			intptr_t,
			std::string
			)>
			(Utils::base + 0x227E0)
			(target, title, btn1, btn2, layerh, l1, l2, caption);

		//clean stack
		__asm add esp, 0x2C

		return pRet;
	}
};
#pragma runtime_checks("s", restore)