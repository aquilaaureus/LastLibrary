#ifndef _LEVELSHELL_H_
#define _LEVELSHELL_H_

#ifndef _LEVELBASE_H_
#include "GamerCamp/GameSpecific/Levels/GCLevelBase.h"
#endif

#include <string.h>

#ifndef _SIMPLE_AUDIO_ENGINE_H_
#include "SimpleAudioEngine.h"
#endif // !_SIMPLE_AUDIO_ENGINE_H_

class CGCLevelData;
class CGCPauseGameLayer;
class CGCEndGameLayer;

class CGCLevelShell
	: public IGCGameLayer
{
private:
	CGCLevelBase*						m_pcLoadedLevel;
	std::vector<char*>					m_vecBackgrounds;
	std::vector<std::string>			m_vecFilePaths;
	std::vector<char*>					m_vecBackgroundMusicFilePaths;
	int									m_iCurrLevelIndex;
	bool								m_bGamePaused;
	bool								m_bisGameOver;
	CGCPauseGameLayer*					m_pcPauseLeveLayer;
	CGCEndGameLayer*					m_pcEndLeveLayer;

	//Sound Engine reference poiner to play all sounds
	CocosDenshion::SimpleAudioEngine*					m_pSharedAudioEngine;


	// Timer label
	cocos2d::Label*						m_pTimerLabel;

	void OnMovementControllerClicked	( cocos2d::Ref * pSender , cocos2d::ui::Widget::TouchEventType eventType );

	void OnJumpControllerClicked		( cocos2d::Ref * pSender , cocos2d::ui::Widget::TouchEventType eventType );

	void		LoadAllSoundsAndSfx ( void );
	void		PlaySoundEffect ( const char* sfxEffectFilePath );

public:
	CGCLevelShell( std::vector<char*> vecBackgrounds,	
				   std::vector<std::string> vecFilePaths, 
				   std::vector<char*> vecBackgroundMusicFiles ,
				   int currLevelIndex );
	~CGCLevelShell( );

	//////////////////////////////////////////////////////////////////////////
	// IGCGameLayer interface

	virtual	void VOnCreate				( void );
	void CB_OnPauseButtonClicked		( Ref * pSender );
	virtual void onEnter				( void );
	virtual void VOnUpdate				( f32 fTimeStep );
	virtual	void VOnDestroy				( void );
	virtual void VOnResourceAcquire( void ) override;

	// IGCGameLayer interface
	//////////////////////////////////////////////////////////////////////////

	void PauseGame						( bool didPlayerLoose );
	void ResumeGame						( void );
	void GameOver						( void );
	int CalculateStars					( void );
	void LoadNextLevel					( void );
	void BackToMenu						( void );
	void ReloadLevel					( void );
};

#endif // _LEVELONE_H_
