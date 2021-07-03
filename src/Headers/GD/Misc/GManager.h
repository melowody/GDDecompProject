/**
 * @file GManager.h
 * 
 * @brief Definitions for the GManager functions (stolen from gd.h)
 * 
 * @author poweredbypie
 */

#ifndef __G_MANAGER_H__
#define __G_MANAGER_H__

#include <cocos2d.h>

using namespace cocos2d;

/**
 * GManager
 * --------
 * The base for the GameManager class
 */
class GManager : public CCNode {
protected:
    std::string m_sFileName; //0x00EC
	bool m_bSetup; //0x0104
	bool m_bSaved; //0x0105

	friend class GameManager;
}; // size 0x108

#endif