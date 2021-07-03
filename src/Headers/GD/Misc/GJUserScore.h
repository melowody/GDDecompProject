/**
 * @file GJUserScore.h
 * 
 * @brief Definitions for the GJUserScore functions
 * 
 * @author DePianoman
 */

#ifndef __GJ_USER_SCORE_H__
#define __GJ_USER_SCORE_H__

#include "cocos2d.h"

using namespace cocos2d;

/**
 * GJ User Score
 * -------------
 * An instance of the player's current stats
 */
class GJUserScore
{
public:
	char pad_0004[232]; //0x0004
	std::string m_sUsername; //0x00EC
	char pad_0104[32]; //0x0104
	int m_nAccountID; //0x0124
	int m_nStars; //0x0128
	int m_nDiamonds; //0x012C
	int m_nDemons; //0x0130
	char pad_0134[4]; //0x0134
	int m_nCreatorPoints; //0x0138
	int m_nCoins; //0x013C
	int m_nUserCoins; //0x0140
	char pad_0144[4]; //0x0144
	int m_nPColor1; //0x0148
	int m_nPColor2; //0x014C
	char pad_0150[20]; //0x0150
	std::string m_sYoutubeURL; //0x0164
	std::string m_sTwitterURL; //0x017C
	std::string m_sTwitchURL; //0x0194
	int m_nCubeID; //0x01AC
	int m_nShipID; //0x01B0
	int m_nBallID; //0x01B4
	int m_nUFOID; //0x01B8
	int m_nWaveID; //0x01BC
	int m_nRobotID; //0x01C0
	int m_nSpiderID; //0x01C4
	char pad_01C8[16]; //0x01C8
	int m_nRank; //0x01D8
	char pad_01DC[16]; //0x01DC
};

#endif