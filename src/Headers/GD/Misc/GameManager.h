/**
 * @file GameManager.h
 * 
 * @brief Definitions for the GameManager functions
 * 
 * @author DePianoman
 */


#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include <cocos2d.h>
#include "../../Utils.h"
#include "../Layers/PlayLayer.h"
#include "../Layers/MenuLayer.h"
#include "GManager.h"

/**
 * Game Manager
 * ------------
 * Stores a majority of the information used in the game, such as current states, player data, etc.
 */
class GameManager : public GManager
{
public:
	bool m_bSwitchModes; //0x0108
	bool m_bToFullscreen; //0x0109
	bool m_bReloading; //0x010A
	uint16_t m_shUnknown; //0x010B
	char pad_010D[3]; //0x010D
	CCDictionary *m_pValueKeeper; //0x0110
	CCDictionary *m_pUnlockValueKeeper; //0x0114
	CCDictionary *m_pCustomObjectDict; //0x0118
	char pad_011C[4]; //0x011C
	double m_dUnknown; //0x0120
	char pad_0128[8]; //0x0128
	bool m_bUnknown6; //0x0130
	char pad_0131[7]; //0x0131
	double m_dUnknown2; //0x0138
	int32_t m_nUnknown2; //0x0140
	int32_t m_nUnknown3; //0x0144
	bool m_bLoaded; //0x0148
	bool m_bUnknown; //0x0149
	char pad_014A[2]; //0x014A
	std::string m_sUnknown; //0x014C
	CCLayer *m_pPlayLayer; //0x0164
	CCLayer *m_pUnknown3; //0x0168
	CCLayer *m_pUnknown4; //0x016C
	CCLayer *m_pMenuLayer; //0x0170
	bool m_bUnknown2; //0x0174
	char pad_0175[3]; //0x0175
	int32_t m_nUnknown4; //0x0178
	int32_t m_nUnknown5; //0x017C
	std::string m_sPlayerUDID; //0x0180
	std::string m_sPlayerName; //0x0198
	bool m_bCommentsEnabled; //0x01B0
	char pad_01B1[3]; //0x01B1
	int32_t m_nPlayerUserIDRand1; //0x01B4
	uint32_t m_nPlayerUserIDRand2; //0x01B8
	int32_t m_nPlayerUserID; //0x01BC
	float m_fBackgroundMusicVolume; //0x01C0
	float m_fEffectsVolume; //0x01C4
	int32_t m_nTimeOffset; //0x01C8
	int32_t m_nUnknown6; //0x01CC
	double m_dUnknown3; //0x01D0
	bool m_bUnknown7; //0x01D8
	bool m_bUnknown8; //0x01D9
	bool m_bUnknown9; //0x01DA
	char pad_01DB[1]; //0x01DB
	int32_t m_nUnknown; //0x01DC
	int32_t m_nUnknown7; //0x01E0
	int32_t m_nUnknown8; //0x01E4
	uint32_t m_nPlayerFrameRand1; //0x01E8
	uint32_t m_nPlayerFrameRand2; //0x01EC
	uint32_t m_nPlayerFrame; //0x01F0
	uint32_t m_nPlayerShipRand1; //0x01F4
	uint32_t m_nPlayerShipRand2; //0x01F8
	uint32_t m_nPlayerShip; //0x01FC
	uint32_t m_nPlayerBallRand1; //0x0200
	uint32_t m_nPlayerBallRand2; //0x0204
	uint32_t m_nPlayerBall; //0x0208
	uint32_t m_nPlayerBirdRand1; //0x020C
	uint32_t m_nPlayerBirdRand2; //0x0210
	uint32_t m_nPlayerBird; //0x0214
	uint32_t m_nPlayerDartRand1; //0x0218
	uint32_t m_nPlayerDartRand2; //0x021C
	uint32_t m_nPlayerDart; //0x0220
	uint32_t m_nPlayerRobotRand1; //0x0224
	uint32_t m_nPlayerRobotRand2; //0x0228
	uint32_t m_nPlayerRobot; //0x022C
	uint32_t m_nPlayerSpiderRand1; //0x0230
	uint32_t m_nPlayerSpiderRand2; //0x0234
	uint32_t m_nPlayerSpider; //0x0238
	uint32_t m_nPlayerColorRand1; //0x023C
	uint32_t m_nPlayerColorRand2; //0x0240
	uint32_t m_nPlayerColor; //0x0244
	uint32_t m_nPlayerColor2Rand1; //0x0248
	uint32_t m_nPlayerColor2Rand2; //0x024C
	uint32_t m_nPlayerColor2; //0x0250
	uint32_t m_nPlayerStreakRand1; //0x0254
	uint32_t m_nPlayerStreakRand2; //0x0258
	uint32_t m_nPlayerStreak; //0x025C
	uint32_t m_nPlayerDeathEffectRand1; //0x0260
	uint32_t m_nPlayerDeathEffectRand2; //0x0264
	uint32_t m_nPlayerDeathEffect; //0x0268
	float m_fUnknown9; //0x026C
	float m_fUnknown10; //0x0270
	int32_t m_nSecretNumberRand1; //0x0274
	int32_t m_nSecretNumberRand2; //0x0278
	bool m_bPlayerGlow; //0x027C
	char pad_027D[3]; //0x027D
	uint32_t m_nPlayerIconType; //0x0280
	bool m_bUnknown3; //0x0284
	bool m_bShowSongMarkers; //0x0285
	bool m_bShowBPMMarkers; //0x0286
	bool m_bRecordGameplay; //0x0287
	bool m_bShowProgressBar; //0x0288
	bool m_bPerformanceMode; //0x0289
	bool m_bClickedGarage; //0x028A
	bool m_bClickedEditor; //0x028B
	bool m_bClickedName; //0x028C
	bool m_bClickedPractice; //0x028D
	bool m_bShowedEditorPractice; //0x028E
	bool m_bShowedRateDiffDialog; //0x028F
	bool m_bShowedRateStarDialog; //0x0290
	bool m_bShowedLowDetailDialog; //0x0291
	char pad_0292[2]; //0x0292
	int32_t m_nUnknown11; //0x0294
	int32_t m_nUnknown12; //0x0298
	char pad_029C[4]; //0x029C
	int32_t m_nUnknown13; //0x02A0
	int32_t m_nUnknown14; //0x02A4
	int32_t m_nUnknown15; //0x02A8
	int32_t m_nUnknown16; //0x02AC
	int32_t m_nUnknown17; //0x02B0
	int32_t m_nUnknown18; //0x02B4
	int32_t m_nUnknown19; //0x02B8
	int32_t m_nUnknown20; //0x02BC
	int32_t m_nUnknown21; //0x02C0
	uint32_t m_nBootups; //0x02C4
	bool m_bHasRatedGame; //0x02C8
	bool m_bUnknown10; //0x02C9
	bool m_bUnknown11; //0x02CA
	bool m_bUnknown12; //0x02CB
	bool m_bGameCenterEnabled; //0x02CC
	bool m_bSmoothFix; //0x02CD
	char pad_02CE[2]; //0x02CE
	int32_t m_nUnknown22; //0x02D0
	int32_t m_nUnknown23; //0x02D4
	int32_t m_nUnknown24; //0x02D8
	bool m_bUnknown13; //0x02DC
	char pad_02DD[3]; //0x02DD
	uint32_t m_nResolution; //0x02E0
	TextureQuality m_eQuality; //0x02E4
	bool m_bUnknown4; //0x02E8
	char pad_02E9[3]; //0x02E9
	int32_t m_nUnknown25; //0x02EC
	bool m_bUnknown14; //0x02F0
	char pad_02F1[3]; //0x02F1
	int32_t m_nUnknown26; //0x02F4
	int32_t m_nUnknown27; //0x02F8
	int32_t m_nUnknown28; //0x02FC
	int32_t m_nUnknown29; //0x0300
	char pad_0304[4]; //0x0304

	static GameManager* sharedState();

	GameManager() {
		this->m_sFileName = "";
		this->m_sUnknown = "";
		this->m_sPlayerUDID = "";
		this->m_sPlayerName = "";
		this->m_fBackgroundMusicVolume = 1.0f;
		this->m_fEffectsVolume = 1.0f;
		this->m_nUnknown14 = 10;
		this->m_nUnknown26 = 1;
	}

	virtual bool init();

	/**
	 * Unknown
	 * 
	 * @return unknown
	 */
	virtual bool unknown() {
		return reinterpret_cast<bool(__thiscall*)(GameManager*)>(Utils::base + 0x28F60)(this);
	}

	static void fadeInMusic(const char* name);

	/**
	 * Gets a boolean given a variable name
	 * 
	 * @return The value of the given variable
	 */
	bool getGameVariable(const char* name) {
		return reinterpret_cast<bool(__thiscall*)(GameManager*, const char*)>(Utils::base + 0xC9D30)(this, name);
	}
};

#endif