/**
 * @file GJAccountManager.h
 * 
 * @brief Definitions for the GJAccountManager functions
 * 
 * @author DePianoman
 */

#ifndef __GJ_ACCOUNT_MANAGER_H__
#define __GJ_ACCOUNT_MANAGER_H__

#include <cocos2d.h>

using namespace cocos2d;

/**
 * GJ Account Manager
 * ------------------
 * Stores the user data, including username, password, etc.
 */
class GJAccountManager : public CCNode {
public:
	CCDictionary *m_uUnknown; //0x00EC
	std::string m_sPassword; //0x00F0
	std::string m_sUsername; //0x0108
	int m_nAccountID; //0x0120
    int m_nNoAccountID;
	char pad_0124[28]; //0x0124

	/**
     * Get the static shared GJAccountManager instance, and initialize it if it doesn't exist
     * 
     * @see GJAccountManager
     * @return The GJAccountManager instance
     */
    static GJAccountManager* sharedState() {
        return reinterpret_cast<GJAccountManager*(__stdcall*)(void)>(Utils::base + 0x107D50)();
    }

};

#endif