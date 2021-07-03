/**
 * @file MenuLayer.cpp
 * 
 * @brief The code for the MenuLayer functions
 * 
 * @author DePianoman
 */

#include "../Headers/GD/geometryjump.h"
#include "Types/MenuLayer.h"
#include "init.h"
#include "../Headers/Utils.h"
#include "../Headers/hook_utils.hpp"

/**
 * Hook for the custom setup function in MenuLayer
 * 
 * @param self The MenuLayer instance
 * 
 * @return true if success, false if failure
 */
bool __fastcall customSetupHook(MenuLayer* self, void*) {

    CCLayer::init();

    // Unsure
    CCDirector* director = CCDirector::sharedDirector();
    CCTouchDispatcher* touchDisp = director->getTouchDispatcher();
    touchDisp->m_nUnknown = -500;

    // Fade in the menu music
    GameManager* GM = GameManager::sharedState();
    GameManager::fadeInMusic("menuLoop.mp3");

    // Set some unknown variables
    GM->m_bUnknown2 = true;
    GM->m_nUnknown = 0;
    GM->m_bUnknown4 = false;

    // Allow keyboard and keypad inputs
    self->setKeypadEnabled(true);
    self->setKeyboardEnabled(true);

    CCSize winSize = director->getWinSize();

    // Add the background game layer to the screen
    MenuGameLayer* mGL = MenuGameLayer::create();
    self->addChild(mGL);

    // Add the logo to the screen
    CCSprite* logoSprite = CCSprite::createWithSpriteFrameName("GJ_logo_001.png");
    self->addChild(logoSprite);

    // Set the position of the logo
    float screenTop = director->getScreenTop();
    logoSprite->setPosition(CCPoint(winSize.width/2.0f, screenTop-50.0f));

    CCMenu* buttonMenu = CCMenu::create();

    // Create the play button
    CCSprite* playSprite = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
    CCMenuItemSpriteExtra* playButton = CCMenuItemSpriteExtra::create(playSprite, self, menu_selector(MenuLayer::onPlay));

    // Add the play button to the button menu and set its position
    buttonMenu->addChild(playButton);
    self->addChild(buttonMenu);
    buttonMenu->setPosition(winSize.width/2.0f, winSize.height/2.0f + 10.0f);

    // Create the icon menu button
    CCSprite* garageSprite = CCSprite::createWithSpriteFrameName("GJ_garageBtn_001.png");
    CCMenuItemSpriteExtra* garageButton = CCMenuItemSpriteExtra::create(garageSprite, self, menu_selector(MenuLayer::onGarage));

    // Add the icon menu button to the button menu and set its position
    buttonMenu->addChild(garageButton);
    CCPoint garagePos = CCPoint(-110.0f, 0.0f);
    CCPoint buttonPos = playButton->getPosition() + garagePos;
    garageButton->setPosition(buttonPos);

    // If the user has never clicked the icon menu button before, add text that describes what the button does
    if (!GM->m_bClickedGarage) {
        CCSprite* charSelect = CCSprite::createWithSpriteFrameName("GJ_chrSel_001.png");
        self->addChild(charSelect);

        CCPoint charSelectPos = CCPoint(-50.0f, -50.0f);
        CCPoint garageWorldPos = buttonMenu->convertToWorldSpace(garagePos);
        charSelect->setPosition(garageWorldPos + charSelectPos);
    }

    // Create the levels button
    CCSprite* creatorSprite = CCSprite::createWithSpriteFrameName("GJ_creatorBtn_001.png");
    CCMenuItemSpriteExtra* creatorButton = CCMenuItemSpriteExtra::create(creatorSprite, self, menu_selector(MenuLayer::onCreator));

    // Add the levels button to the button menu and set its position
    buttonMenu->addChild(creatorButton);
    CCPoint creatorPos = CCPoint(110.0f, 0.0f);
    CCPoint creatorButtonPos = playButton->getPosition() + creatorPos;
    creatorButton->setPosition(creatorButtonPos);

    // If the user has never clicked the levels button before, add text that describes what the button does
    if (!GM->m_bClickedEditor) {
        CCSprite* levelEdit = CCSprite::createWithSpriteFrameName("GJ_lvlEdit_001.png");
        self->addChild(levelEdit);

        CCPoint charSelectPos = CCPoint(50.0f, -50.0f);
        CCPoint creatorWorldPos = buttonMenu->convertToWorldSpace(creatorPos);
        levelEdit->setPosition(creatorWorldPos + charSelectPos);
    }

    // Create the menu for the buttons on the bottom of the screen
    CCMenu* bottomMenu = CCMenu::create();
    self->addChild(bottomMenu);

    // Create and position the achievements button
    CCSprite* achSprite = CCSprite::createWithSpriteFrameName("GJ_achBtn_001.png");
    achSprite->setScale(1.0f);
    CCMenuItemSpriteExtra* achButton = CCMenuItemSpriteExtra::create(achSprite, self, menu_selector(MenuLayer::onAchievements));
    bottomMenu->addChild(achButton);

    // Create and position the options button
    CCSprite* optionsSprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
    optionsSprite->setScale(1.0f);
    CCMenuItemSpriteExtra* optionsButton = CCMenuItemSpriteExtra::create(optionsSprite, self, menu_selector(MenuLayer::onOptions));
    bottomMenu->addChild(optionsButton);

    // Create and position the stats button
    CCSprite* statsSprite = CCSprite::createWithSpriteFrameName("GJ_statsBtn_001.png");
    statsSprite->setScale(1.0f);
    CCMenuItemSpriteExtra* statsButton = CCMenuItemSpriteExtra::create(statsSprite, self, menu_selector(MenuLayer::onStats));
    bottomMenu->addChild(statsButton);

    // Create and position the newgrounds button
    CCSprite* ngSprite = CCSprite::createWithSpriteFrameName("GJ_ngBtn_001.png");
    ngSprite->setScale(1.0f);
    CCMenuItemSpriteExtra* ngButton = CCMenuItemSpriteExtra::create(ngSprite, self, menu_selector(MenuLayer::onNewgrounds));
    bottomMenu->addChild(ngButton);

    // Set the position of the bottom menu
    float bottomMenuPos = director->getScreenBottom() + 45.0f;
    bottomMenu->setPosition(CCPoint(winSize.width/2.0f, bottomMenuPos));
    bottomMenu->alignItemsHorizontallyWithPadding(5.0f);

    // Create the robtop button
    CCSprite* robtopSprite = CCSprite::createWithSpriteFrameName("robtoplogo_small.png");
    robtopSprite->setScale(.8f);
    CCMenuItemSpriteExtra* robtopButton = CCMenuItemSpriteExtra::create(robtopSprite, self, menu_selector(MenuLayer::onRobtop));
    robtopButton->setSizeMult(1.5f);

    // Create the menu for Robtop's socials and set its position
    CCMenu* socialMenu = CCMenu::create();
    socialMenu->addChild(robtopButton);
    self->addChild(socialMenu, 2);
    socialMenu->setPosition(director->getScreenLeft() + 50.0f, 24.0f);

    // Create the facebook button
    CCSprite* fbSprite = CCSprite::createWithSpriteFrameName("gj_fbIcon_001.png");
    fbSprite->setScale(.8f);
    CCMenuItemSpriteExtra* fbButton = CCMenuItemSpriteExtra::create(fbSprite, self, menu_selector(MenuLayer::onFacebook));
    fbButton->setSizeMult(1.5f);
    socialMenu->addChild(fbButton);

    // Create the twitter button
    CCSprite* twitterSprite = CCSprite::createWithSpriteFrameName("gj_twIcon_001.png");
    twitterSprite->setScale(.8f);
    CCMenuItemSpriteExtra* twitterButton = CCMenuItemSpriteExtra::create(twitterSprite, self, menu_selector(MenuLayer::onTwitter));
    twitterButton->setSizeMult(1.5f);
    socialMenu->addChild(twitterButton);

    // Create the youtube button
    CCSprite* ytSprite = CCSprite::createWithSpriteFrameName("gj_ytIcon_001.png");
    ytSprite->setScale(.8f);
    CCMenuItemSpriteExtra* ytButton = CCMenuItemSpriteExtra::create(ytSprite, self, menu_selector(MenuLayer::onYoutube));
    ytButton->setSizeMult(1.5f);
    socialMenu->addChild(ytButton);

    // Position all the social buttons correctly
    CCPoint socialButtonsPos = socialMenu->convertToNodeSpace(CCPoint(director->getScreenLeft() + 22.0f, 55.0f));
    fbButton->setPosition(socialButtonsPos);
    twitterButton->setPosition(socialButtonsPos + CCPoint(30.0f, 0.0f));
    ytButton->setPosition(socialButtonsPos + CCPoint(60.0f, 0.0f));

    // Create the more games button
    CCSprite* moreGamesSprite = CCSprite::createWithSpriteFrameName("GJ_moreGamesBtn_001.png");
    moreGamesSprite->setScale(0.9f);
    CCMenuItemSpriteExtra* moreGamesButton = CCMenuItemSpriteExtra::create(moreGamesSprite, self, menu_selector(MenuLayer::onMoreGames));

    // Create the menu for the other miscellaneous buttons and set its position
    CCMenu* otherButtons = CCMenu::create();
    otherButtons->addChild(moreGamesButton);
    self->addChild(otherButtons);
    otherButtons->setPosition(CCPoint(director->getScreenRight() - 43.0f, 45.0f));

    // Create and position the close button
    CCSprite* closeSprite = CCSprite::createWithSpriteFrameName("GJ_closeBtn_001.png");
    closeSprite->setScale(0.7f);
    CCMenuItemSpriteExtra* closeButton = CCMenuItemSpriteExtra::create(closeSprite, self, menu_selector(MenuLayer::onClose));
    otherButtons->addChild(closeButton);
    CCPoint closePos = otherButtons->convertToNodeSpace(CCPoint(18.0f, director->getScreenTop() - 18.0f));
    closeButton->setPosition(closePos);

    CCApplication* app = CCApplication::sharedApplication();

    // If the user is using a controller
    if (app->m_bUsingController) {

        // Create and position the start icon for the play button
        CCSprite* controllerStartSprite = CCSprite::createWithSpriteFrameName("controllerBtn_Start_001.png");
        self->addChild(controllerStartSprite);
        CCPoint playButtonPos = buttonMenu->convertToWorldSpace(playButton->getPosition());
        CCPoint playButtonInPos = self->convertToNodeSpace(playButtonPos);
        controllerStartSprite->setPosition(playButtonInPos + CCPoint(0.0f, -66.0f));

        // Create and position the Y icon for the levels button
        CCSprite* controllerYSprite = CCSprite::createWithSpriteFrameName("controllerBtn_Y_001.png");
        self->addChild(controllerYSprite);
        CCPoint creatorButtonWorldPos = buttonMenu->convertToWorldSpace(creatorButton->getPosition());
        CCPoint creatorButtonNodePos = self->convertToNodeSpace(creatorButtonWorldPos);
        controllerYSprite->setPosition(creatorButtonNodePos + CCPoint(0.0f, -45.0f));
        controllerYSprite->setScale(.8f);

        // Create and position the X icon for the icon menu button
        CCSprite* controllerXSprite = CCSprite::createWithSpriteFrameName("controllerBtn_X_001.png");
        self->addChild(controllerXSprite);
        CCPoint garageButtonWorldPos = buttonMenu->convertToWorldSpace(garageButton->getPosition());
        CCPoint garageButtonNodePos = self->convertToNodeSpace(garageButtonWorldPos);
        controllerXSprite->setPosition(garageButtonNodePos + CCPoint(0.0f, -45.0f));
        controllerXSprite->setScale(.8f);

        // Create and position the D-Pad Down icon for the options button
        CCSprite* controllerDownSprite = CCSprite::createWithSpriteFrameName("controllerBtn_DPad_Down_001.png");
        self->addChild(controllerDownSprite);
        CCPoint optionsButtonWorldPos = bottomMenu->convertToWorldSpace(optionsButton->getPosition());
        CCPoint optionsButtonNodePos = self->convertToNodeSpace(optionsButtonWorldPos);
        controllerDownSprite->setPosition(optionsButtonNodePos + CCPoint(0.0f, -34.0f));
        controllerDownSprite->setScale(.5f);

        // If variable 0028 (unknown) is false
        if (!GM->getGameVariable("0028")) {

            // Create and position the Left Joystick icon
            GJAccountManager* AM = GJAccountManager::sharedState();
            CCSprite* controllerLThumbSprite = CCSprite::createWithSpriteFrameName("controllerBtn_LThumb_001.png");
            self->addChild(controllerLThumbSprite);
            CCPoint controllerLSpritePos = CCPoint(director->getScreenLeft() + 25.0f, winSize.height/2.0f + 25.0f + (AM->m_nAccountID - AM->m_nNoAccountID != 0 ? 15.0f : 0.0f));
            controllerLThumbSprite->setPosition(controllerLSpritePos);

            // Create and position the A Icon
            CCSprite* controllerASprite = CCSprite::createWithSpriteFrameName("controllerBtn_A_001.png");
            self->addChild(controllerASprite);
            CCPoint controllerASpritePos = controllerLSpritePos + CCPoint(0.0f, -30.0f);
            controllerASprite->setPosition(controllerASpritePos);

            // Create and position the Mouse text next to the Left Joystick icon
            CCLabelBMFont* mouseLabel = CCLabelBMFont::create("Mouse", "goldFont.fnt");
            mouseLabel->setScale(0.5f);
            self->addChild(mouseLabel);
            mouseLabel->setAnchorPoint(CCPoint(0.0f, 0.6f));
            mouseLabel->setPosition(controllerLThumbSprite->getPosition() + CCPoint(16.0f, 1.0f));

            // Create and position the Click text next to the A icon
            CCLabelBMFont* clickLabel = CCLabelBMFont::create("Click", "goldFont.fnt");
            clickLabel->setScale(0.5f);
            self->addChild(clickLabel);
            clickLabel->setAnchorPoint(CCPoint(0.0f, 0.6f));
            clickLabel->setPosition(controllerASprite->getPosition() + CCPoint(16.0f, 1.0f));
        }

    }

    // Create and position the Profile button
    CCSprite* profileSprite = CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png");
    CCMenuItemSpriteExtra* profileButton = CCMenuItemSpriteExtra::create(profileSprite, self, menu_selector(MenuLayer::onMyProfile));
    buttonMenu->addChild(profileButton, 2);
    CCPoint buttonNodePos = buttonMenu->convertToNodeSpace(CCPoint(45.0f, 105.0f));
    profileButton->setPosition(buttonNodePos);
    self->m_uProfileButton = profileButton;

    // Create the username text and position above the profile button
    CCLabelBMFont* userNameLabel = CCLabelBMFont::create("TestAcc", "goldFont.fnt"); // CHANGE LABEL TO CURRENT NAME WHEN IMPLEMENTED
    self->m_uUsernameLabel = userNameLabel;
    self->addChild(userNameLabel, 2);
    userNameLabel->setPosition(CCPoint(47.0f, 141.0f));
    userNameLabel->limitLabelWidth(70.0f, .7f, 0.0f);

    // If the player has clicked the icon menu and not the profile button position the text explaining what the profile button does
    if (!GM->getGameVariable("0048") && GM->m_bClickedGarage) {
        CCSprite* profileText = CCSprite::createWithSpriteFrameName("GJ_viewProfileTxt_001.png");
        self->m_uProfileText = profileText;
        self->addChild(profileText, 2);
        profileText->setPosition(CCPoint(121.0f, 104.0f));
    }

    self->updateUserProfileButton();
    GM->m_pMenuLayer = self;

    // Create and position the daily chest button
    CCSprite* dailySprite = CCSprite::createWithSpriteFrameName("GJ_dailyRewardBtn_001.png");
    CCMenuItemSpriteExtra* dailyButton = CCMenuItemSpriteExtra::create(dailySprite, self, menu_selector(MenuLayer::onDaily));
    bottomMenu->addChild(dailyButton);
    CCPoint dailyPos = CCPoint(director->getScreenRight() - 40.0f, winSize.height/2.0f + 20.0f);
    CCPoint dailyNodePos = bottomMenu->convertToNodeSpace(dailyPos);
    dailyButton->setPosition(dailyNodePos);
    dailyButton->setSizeMult(1.5f);

    return true;
}

/**
 * Add the hook for MenuLayer::customSetup
 */
void MenuLayerHook::mem_init() {
    Hooks::addHook({ Utils::base + 0x1907b0, customSetupHook, &MenuLayerHook::customSetup });
}