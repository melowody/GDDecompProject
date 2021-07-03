/**
 * @file GameManager.cpp
 * 
 * @brief The code for the GameManager functions
 * 
 * @author DePianoman
 */


#include "GameManager.h"
#include "GameSoundManager.h"
#include "FMODAudioEngine.h"

/*bool init() {
    this->m_sFileName.assign("CCGameManager.dat", 11);
    this->m_shUnknown = 0;
    this->m_bUnknown = false;
    this->m_dUnknown = 0;
    this->m_dUnknown2 = 0;
}*/

/**
 * Fades out the current music if playing any and fades in the music from the given file name
 * 
 * @param name The name of the music file
 */
void GameManager::fadeInMusic(char const* name) {

    // Get the passed song name
    std::string songString;
    songString.assign(name, strlen(name));

    // Get the currently playing song name
    GameSoundManager* GSM = GameSoundManager::sharedState();
    std::string currSong = GSM->getCurrSong();

    // If the passed song is not empty and is not the currently playing song, then fade from the current song to the given song
    if (currSong != songString && name != "") {
        GameSoundManager::playBackgroundMusic(songString, true, true);
        FMODAudioEngine* FMAE = FMODAudioEngine::sharedEngine();
        FMAE->m_pChannelControl->setVolume(0);
        FMAE->m_fFadeInDuration = 1.0f;
        FMAE->m_bFading = true;
        FMAE->m_bFadeIn = true;
        FMAE->m_pChannelControl->setPaused(false);
    }
}

/**
 * Get the static shared GameManager instance, and initialize it if it doesn't exist
 * 
 * @see GameManager
 * @return The GameManager instance
 */
GameManager* GameManager::sharedState() {
    GameManager** sharedManager = reinterpret_cast<GameManager**>(Utils::base + 0x3222D0);
    if (!*sharedManager) {
        *sharedManager = new GameManager();
        (*sharedManager)->init();
    }
    return *sharedManager; 
}

/**
 * Initializes the current GameManager instance
 * 
 * @return true if success, false if failure
 */
bool GameManager::init() {
    this->m_sFileName.assign("CCGameManager.dat", 11);
    this->m_shUnknown = 0;
    this->m_bUnknown = 0;
    this->m_dUnknown = 0;
    this->m_dUnknown2 = 0;
    this->unknown();
    float randNum = (float)rand();
    randNum = randNum / 32767.0f * 1000000.0f;
    float subNum = (float)(this->m_nPlayerUserIDRand1 - this->m_nPlayerUserIDRand2);
    subNum = floor(subNum / 10000.0f);
    float randNum2 = (float)rand();
    randNum2 = randNum2 / 32767.0f * 1000.0f;
    this->m_fUnknown10 = randNum2;
    this->m_fUnknown9 = randNum2 + subNum;
    return true;
}