/**
 * @file FMODAudioEngine.h
 * 
 * @brief Definitions for the FMODAudioEngine functions
 * 
 * @author DePianoman, matcool
 */


#ifndef __FMOD_AUDIO_ENGINE_H__
#define __FMOD_AUDIO_ENGINE_H__

#include <cocos2d.h>
#include "../../Utils.h"
#include "fmod_include.h"

using namespace cocos2d;

/**
 * FMOD Audio Engine
 * -----------------
 * The main class that controls the audio for the game.
 */
class FMODAudioEngine : public CCNode
{
public:
	CCDictionary *m_pUnknown; //0x00EC
	std::string m_sCurrSong; //0x00F0
	float m_fMusicVolume; //0x0108
	float m_fEffectsVolume; //0x010C
	float m_fPulse1; //0x0110
	float m_fPulse2; //0x0114
	float m_fPulse3; //0x0118
	int32_t m_nPulseCounter; //0x011C
	bool m_bMetering; //0x0120
	bool m_bFading; //0x0121
	bool m_bFadeIn; //0x0122
	char pad_0123[1]; //0x0123
	float m_fFadeInDuration; //0x0124
	FMOD::System* m_pSystem; //0x0128
	FMOD::ChannelGroup* m_pChannelGroup; //0x012C
	bool *m_bPaused; //0x0130
	FMOD::ChannelControl* m_pChannelControl; //0x0134
	void* m_pMeteringInfo; //0x0138
	int32_t m_eLastResult; //0x013C
	char pad_0140[8]; //0x0140
	int32_t m_nMusicOffset; //0x0148

	static FMODAudioEngine* sharedEngine();
}; 

#endif