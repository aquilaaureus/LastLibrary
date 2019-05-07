#include "GCLevelShell.h"

#ifndef _GCENDGAMELAYER_H_
	#include "GamerCamp/GameSpecific/Menus/GCEndGameLayer.h"
#endif

#ifndef _GCPAUSEGAMELAYER_H_
	#include "GamerCamp/GameSpecific/Menus/GCPauseGameLayer.h"
#endif

#ifndef _CHAPTERSELECTIONSCENE_H_
	#include "GamerCamp/GameSpecific/Menus/GCChapterSelectionScene.h"
#endif

#ifndef _GCGLOBALPLAYERDATA_H_
	#include "GamerCamp/GameSpecific/GlobalData/GCGlobalPlayerData.h"
#endif

#ifndef _LEVELDATA_H_
	#include "GamerCamp/GameSpecific/GlobalData/LevelData/GCLevelData.h"
#endif

#ifndef _EPILOGUESCENE_H_
#include "GamerCamp/GameSpecific/Menus/GCEpilogueScene.h"
#endif

#include "GamerCamp/GameSpecific/helper/CGCStringHelper.h"

USING_NS_CC;

///////////////////////////////////////////////////////////////////////////////
// Constructor
// CGCGlobalData reference part of the constructor currently does nothing 
// Shouldn't break other parts to code 
///////////////////////////////////////////////////////////////////////////////
CGCLevelShell::CGCLevelShell( std::vector<char*> vecBackgrounds, 
							  std::vector<std::string> vecFilePaths, 
							  std::vector<char*> vecBackgroundMusicFiles,
							  int currLevelIndex )
	: IGCGameLayer( GetGCTypeIDOf( CGCLevelShell ) )
{
	m_vecBackgrounds 				= vecBackgrounds;
	m_vecFilePaths 					= vecFilePaths;
	m_vecBackgroundMusicFilePaths 	= vecBackgroundMusicFiles;
	m_iCurrLevelIndex				= currLevelIndex;
	m_bGamePaused = false;
	m_bisGameOver = false;
	m_pcLoadedLevel = new CGCLevelBase( m_vecBackgrounds[m_iCurrLevelIndex], 
										m_vecFilePaths[m_iCurrLevelIndex], 
										m_vecBackgroundMusicFilePaths[m_iCurrLevelIndex] );
	//this->addChild( m_pcLoadedLevel );
}


//////////////////////////////////////////////////////////////////////////
// Destructor
//////////////////////////////////////////////////////////////////////////
CGCLevelShell::~CGCLevelShell()
{
	delete m_pcLoadedLevel;
// 	if (m_pcPauseLeveLayer)
// 	{
// 		delete m_pcPauseLeveLayer;
// 	}
}

//////////////////////////////////////////////////////////////////////////
// on create
//////////////////////////////////////////////////////////////////////////
//virtual
void CGCLevelShell::VOnCreate(void)
{
	IGCGameLayer::VOnCreate();
	m_pcLoadedLevel->init(); //this calls VOnCreate
	//m_pcLoadedLevel->autorelease();
	//m_pcLoadedLevel->VOnCreate();

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Add pause button
	const char* pBackButtonPath = "Loose/gui_pausebutton.png";
	ui::Button* pBackButton = ui::Button::create( pBackButtonPath );

	pBackButton->setPosition( Vec2( origin.x + (pBackButton->getContentSize().width * 0.5f),
							  origin.y + visibleSize.height - (pBackButton->getContentSize().height * 0.5f)  ) );

	pBackButton->addClickEventListener( CC_CALLBACK_1( CGCLevelShell::CB_OnPauseButtonClicked, this ) );
	this->addChild( pBackButton , 2 );

	//Right Movement Controller
	const char* pszPng_RightMovementController = "Loose/gui_controls_rightarrow.png";
	ui::Button*		pRightMovementController = ui::Button::create ( pszPng_RightMovementController );

	pRightMovementController->setPosition ( Vec2 ( origin.x + ( ( pRightMovementController->getContentSize ( ).width ) * 1.2f ) ,
											origin.y ) );

	pRightMovementController->setAnchorPoint ( Vec2 ( 0 , 0 ) );

	//add tag to distinguish the button 
	pRightMovementController->setActionTag ( ACTION_MOVE_RIGHT );
	pRightMovementController->addTouchEventListener ( CC_CALLBACK_2 ( CGCLevelShell::OnMovementControllerClicked , this ) );

	this->addChild ( pRightMovementController , 2 );

	//Left Movement Controller
	const char* pszPng_LefttMovementController = "Loose/gui_controls_leftarrow.png";
	ui::Button*		pLeftMovementController = ui::Button::create ( pszPng_LefttMovementController );

	pLeftMovementController->setPosition ( Vec2 ( origin.x + ( ( pLeftMovementController->getContentSize ( ).width ) * 0.2f ) ,
										   origin.y ) );


	pLeftMovementController->setAnchorPoint ( Vec2 ( 0 , 0 ) );

	//add tag to distinguish the button 
	pLeftMovementController->setActionTag ( ACTION_MOVE_LEFT );
	pLeftMovementController->addTouchEventListener ( CC_CALLBACK_2 ( CGCLevelShell::OnMovementControllerClicked , this ) );

	this->addChild ( pLeftMovementController , 2 );

	//Jump Controller
	const char* pszPng_JumpController = "Loose/gui_controls_jump.png";

	ui::Button*		pJumpController = ui::Button::create ( pszPng_JumpController );

	pJumpController->setPosition ( Vec2 ( origin.x + ( visibleSize.width - ( ( pJumpController->getContentSize ( ).width )  * 1.2f ) ) ,
		( origin.y ) ) );

	pJumpController->setAnchorPoint ( Vec2 ( 0 , 0 ) );

	//add tag to distinguish the button 
	pJumpController->setActionTag ( ACTION_JUMP );
	pJumpController->addTouchEventListener ( CC_CALLBACK_2 ( CGCLevelShell::OnJumpControllerClicked , this ) );

	this->addChild ( pJumpController , 2 );

	// create and initialize a label
	// Timer LAbel
	m_pTimerLabel = Label::createWithTTF ( "0s" , "fonts/bokka_solid_regular.ttf" , 72 );
	m_pTimerLabel->setColor ( ccc3 ( 255 , 0 , 0 ) );

	// Position label to top left of screen
	m_pTimerLabel->setPosition ( Vec2 ( origin.x + (   ( m_pTimerLabel->getContentSize ( ).width )  * 3.25f  ) ,
		( origin.y + ( visibleSize.height ) - ( m_pTimerLabel->getContentSize ( ).height * 1.0f ) ) ) );

	// add the label as a child to this layer
	//this->addChild ( m_pTimerLabel , 2 );

	//Add the actual level last
	this->addChild( m_pcLoadedLevel, 1 );

	LoadAllSoundsAndSfx ( );
}

void CGCLevelShell::OnMovementControllerClicked ( cocos2d::Ref *pSender , cocos2d::ui::Widget::TouchEventType eventType )
{
	m_pcLoadedLevel->HandleMovementControllerEvents ( pSender , eventType );
}

//////////////////////////////////////////////////////////////////////////////////////
//This function handles the jump or interact from on screen control
// Function returns 'void'
//////////////////////////////////////////////////////////////////////////////////////
void CGCLevelShell::OnJumpControllerClicked ( cocos2d::Ref *pSender , cocos2d::ui::Widget::TouchEventType eventType )
{
	m_pcLoadedLevel->HandleJumpOrInteract ( pSender , eventType );
}

void CGCLevelShell::CB_OnPauseButtonClicked( Ref* pSender )
{
	m_bGamePaused = true;
}

void CGCLevelShell::onEnter ( )
{
	//CGCLevelBase::onEnter ( );
	m_pcLoadedLevel->onEnter();
	IGCGameLayer::onEnter();
	//SetSelfAsActiveGameLayer();
}

//////////////////////////////////////////////////////////////////////////
// on update
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCLevelShell::VOnUpdate ( f32 fTimeStep )
{
	//update timer label
// 	std::string str = to_string ( m_pcLoadedLevel->getTimeInSecs() );
// 	str += "s";
// 	m_pTimerLabel->setString ( to_string ( str ) );

	//Check, if game is paused or over, reclaim control
	if (m_bGamePaused)
	{
		PauseGame(false);
	}
	else if(m_pcLoadedLevel->IsGameOver())
	{
		GameOver();
	}
	/*else
	{
		//CGCLevelBase::VOnUpdate( fTimeStep );
		m_pcLoadedLevel->VOnUpdate( fTimeStep );
	}*/
}

///////////////////////////////////////////////////////////////////////////////
// on destroy
///////////////////////////////////////////////////////////////////////////////
// virtual
void CGCLevelShell::VOnDestroy ( void )
{
	//CGCLevelBase::VOnDestroy ( );
	//m_pcLoadedLevel->VOnDestroy();
	//removeChild( m_pcLoadedLevel );
	IGCGameLayer::VOnDestroy();
}

void CGCLevelShell::VOnResourceAcquire( void )
{
	//Call NOTHING here. This doing something here was the cause of the double object placement.
//	m_pcLoadedLevel->VOnResourceAcquire();
}


void CGCLevelShell::PauseGame( bool didPlayerLoose )
{
	//Create Pause Menu
	m_pcPauseLeveLayer = new CGCPauseGameLayer ( this, didPlayerLoose );

	if ( m_pcPauseLeveLayer && m_pcPauseLeveLayer->init ( ) )
	{
		m_pcPauseLeveLayer->autorelease ( );
	}
	else
	{
		CCAssert ( false , "Failed to allocate IGCGameLayer, or IGCGameLayer->init() failed" );
	}

	Director::getInstance ( )->pause ( );

	this->addChild ( m_pcPauseLeveLayer, 3 );
}

void CGCLevelShell::ResumeGame( void )
{
	m_bGamePaused = false;
	Director::getInstance()->resume();
	this->removeChild( m_pcPauseLeveLayer );
}

void CGCLevelShell::GameOver( void )
{
	if(m_bisGameOver)
	{
		return;
	}
	m_bisGameOver = true; //Do not execute twice

	if (m_pcLoadedLevel->GetRemainingLives() <= 0  )
	{
		PauseGame ( true );
		return;
	}

	int stars = CalculateStars();
	//m_pcGCGlobalData->m_pcGCLevelData[m_iCurrLevelIndex].m_iLevelStarsEarned = stars;

	//Create Pause Menu
  	m_pcEndLeveLayer = new CGCEndGameLayer( this, m_iCurrLevelIndex, m_pcLoadedLevel->PagesCollected() );

	if (m_pcEndLeveLayer && m_pcEndLeveLayer->init())
	{
		m_pcEndLeveLayer->autorelease();
	}
	else
	{
		CCAssert( false, "Failed to allocate IGCGameLayer, or IGCGameLayer->init() failed" );
	}

	Director::getInstance()->pause();

	this->addChild( m_pcEndLeveLayer, 3 );
}

int CGCLevelShell::CalculateStars( void )
{
	if (m_pcLoadedLevel->GetRemainingLives() == 0)
	{
		return 0;
	}
	int num = 1;

	if (m_pcLoadedLevel->GetNumOfEnemiesKilled() == 0)
	{
		++num;
	}

	if (m_pcLoadedLevel->getTimeInSecs() < m_pcLoadedLevel->GetStarLimit())
	{
		++num;
	}

	return num;
}


void CGCLevelShell::LoadNextLevel( void )
{
	m_bGamePaused = false;
	Director::getInstance()->resume();

	if (++m_iCurrLevelIndex >= m_vecFilePaths.size())
	{
		//BackToMenu();
		Director::getInstance()->replaceScene( TransitionPageTurn::create( CGCGlobalPlayerData::s_fPageTransitionSpeed, CGCEpilogueScene::scene(), false ) );
	}
	else
	{
		this->removeChild( m_pcEndLeveLayer );
		
		this->removeChild( m_pcLoadedLevel );

		delete m_pcLoadedLevel;

		m_bGamePaused = false;
		m_bisGameOver = false;

		m_pcLoadedLevel = new CGCLevelBase( m_vecBackgrounds[m_iCurrLevelIndex],
			m_vecFilePaths[m_iCurrLevelIndex],
			m_vecBackgroundMusicFilePaths[m_iCurrLevelIndex] );

		m_pcLoadedLevel->init(); //this calls VOnCreate
								 //m_pcLoadedLevel->autorelease();
								 //m_pcLoadedLevel->VOnCreate();

		this->addChild( m_pcLoadedLevel, 1 );

// 		cocos2d::Scene* pLevelShellScene = cocos2d::Scene::create ( );
// 		CGCLevelShell* pShell = new CGCLevelShell ( m_vecBackgrounds , m_vecFilePaths , m_vecBackgroundMusicFilePaths , m_iCurrLevelIndex, m_pcGCGlobalData );
// 
// 		if ( pShell && pShell->init ( ) )
// 		{
// 			//stop playing existing background music
// 			CocosDenshion::SimpleAudioEngine::getInstance ( )->stopBackgroundMusic ( );
// 			pShell->autorelease ( );
// 		}
// 		else
// 		{
// 			CCAssert ( false , "Failed to allocate IGCGameLayer, or IGCGameLayer->init() failed" );
// 		}
// 		// add IGCGameLayer to the scene
// 		pLevelShellScene->addChild ( pShell , -1 );
// 		Director::getInstance ( )->replaceScene ( TransitionPageTurn::create ( 0.75f , pLevelShellScene , false ) );
	}
}

void CGCLevelShell::LoadAllSoundsAndSfx ( void )
{
	// load background sound
	m_pSharedAudioEngine = CocosDenshion::SimpleAudioEngine::getInstance ( );

	m_pSharedAudioEngine->preloadBackgroundMusic ( CGCGlobalPlayerData::s_pPageTransitionSoundPath );
}

void CGCLevelShell::PlaySoundEffect ( const char * sfxEffectFilePath )
{
	if ( CCUserDefault::sharedUserDefault ( )->getBoolForKey ( CGCGlobalPlayerData::s_pMusicPlayingKey , true ) )
	{
		m_pSharedAudioEngine->stopAllEffects ( );
		m_pSharedAudioEngine->playEffect ( sfxEffectFilePath , false , 1.0f , 1.0f );
	}
}

void CGCLevelShell::BackToMenu( void )
{
	m_bGamePaused = false;
	Director::getInstance()->resume();
	if (m_pcLoadedLevel->IsGameOver())
	{
		this->removeChild( m_pcEndLeveLayer );
	}
	else
	{
		this->removeChild( m_pcPauseLeveLayer );
	}
	CocosDenshion::SimpleAudioEngine::getInstance ( )->stopBackgroundMusic ( );
	cocos2d::Scene* pLevelShellScene = cocos2d::Scene::create();
	CGCChapterSelectionScene* pChSelect = new CGCChapterSelectionScene( 0 );

	if (pChSelect && pChSelect->init())
	{
		//stop playing existing background music
		PlaySoundEffect ( CGCGlobalPlayerData::s_pPageTransitionSoundPath );
		pChSelect->autorelease();
	}
	else
	{
		CCAssert( false, "Failed to allocate IGCGameLayer, or IGCGameLayer->init() failed" );
	}

	// add IGCGameLayer to the scene
	pLevelShellScene->addChild( pChSelect, -1 );

	Director::getInstance()->replaceScene( TransitionPageTurn::create( CGCGlobalPlayerData::s_fPageTransitionSpeed, pLevelShellScene, true ) );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Restarts the level from the beginning
// If m_pcLoadedLevel->IsGameOver() returns true
// EndGameLayer has to be removed as a child
// Otherwise the level has only been paused and so remove the PauseLevelLayer as a child
// Called by pressing the reset/restart button in either the pause or end game menus during a level
///////////////////////////////////////////////////////////////////////////////////////////////////////

void CGCLevelShell::ReloadLevel( void )
{
	
	Director::getInstance()->resume();

	//this is a safe function, so we can "remove" a child that it not there (it does nothing).
	this->removeChild( m_pcEndLeveLayer );
	this->removeChild( m_pcPauseLeveLayer );

	m_bisGameOver = false;
	m_bGamePaused = false;
	m_pcLoadedLevel->VOnReset();

/*
	cocos2d::Scene* pLevelShellScene = cocos2d::Scene::create();
	CGCLevelShell* pShell = new CGCLevelShell( m_vecBackgrounds, m_vecFilePaths, m_vecBackgroundMusicFilePaths, m_iCurrLevelIndex, m_pcGCGlobalData );

	if (pShell && pShell->init())
	{
		//stop playing existing background music
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
		pShell->autorelease();
	}
	else
	{
		CCAssert( false, "Failed to allocate IGCGameLayer, or IGCGameLayer->init() failed" );
	}

	// add IGCGameLayer to the scene
	pLevelShellScene->addChild( pShell, -1 );

	Director::getInstance()->replaceScene( TransitionPageTurn::create( 0.75f, pLevelShellScene, true ) );
*/

}

