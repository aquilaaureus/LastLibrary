#ifndef _LEVELBASE_H_
#define _LEVELBASE_H_

#include "ui/UIButton.h"

#ifndef _IGCGAMELAYER_H_
	#include "GamerCamp/GCCocosInterface/IGCGameLayer.h"
#endif // !_IGCGAMELAYER_H_

#ifndef _BASEEVENTLISTENER_H_
	#include "GamerCamp/GameSpecific/EventSystem/CIGCEventBaseListener.h"
#endif

#ifndef ACTION_MOVE_LEFT
#define ACTION_MOVE_LEFT (1)
#endif // !ACTION_MOVE_LEFT

#ifndef ACTION_MOVE_RIGHT
#define ACTION_MOVE_RIGHT (2)
#endif // !ACTION_MOVE_RIGHT

#ifndef ACTION_JUMP
#define ACTION_JUMP (3)
#endif //!ACTION_JUMP

#ifndef ACTION_INTERACT
#define ACTION_INTERACT (4)
#endif // !ACTION_INTERACT

#include <set>

#include "AppMacros.h"

#ifndef _SIMPLE_AUDIO_ENGINE_H_
	#include "SimpleAudioEngine.h"
#endif // !_SIMPLE_AUDIO_ENGINE_H_

//////////////////////////////////////////////////////////////////////////
// fwd decl
class CGCObjSprite;
class CGCObjPlayer;
class CGCObjPlatform;
class CGCObjGroupPlatform;
class CGCObjGroupRangedEnemyProjectile;
class CGCObjGroupRangedEnemy;
class CGCObjGroupPatrollingEnemy;
class CGCObjGroupMainCollectible;
class CGCObjGroupSecondCollectible;
class CGCObjGroupPatrolPost;
class CGCObjGroupPlatformPost;
class CGCObjGroupGates;
class CGCObjGroupSwitch;
class CGCObjGroupWall;
class CGCGoal;
class CGCObjSwitch;
class CGCObjSpikes;
class CGCObjGroupSpikes;
class CGCGlobalPlayerData;
class CGCEventBaseManager;
class CGCLevelLoader_Ogmo;

//this class will be responsible for rendering all the controls
//and common thing in any level
class CGCLevelBase
	: public IGCGameLayer
	, public b2ContactListener
	, public CIGCEventBaseListener
{
public:

	//BOOK THEMES
	//Used for creation of enemies and platforms. NOT USED FOR BACKGROUNDS. Each level sets up its own background.
	enum EThemes
	{
		ETheme_Fantasy = 0,
		ETheme_Horror
	};

	// protected constructor - can only be created by deriving from this class
	CGCLevelBase( const char* pszPlist_background, std::string strLevelPath , const char* pszBackgroundMusicPath );
	~CGCLevelBase();

	//////////////////////////////////////////////////////////////////////////
	// Player Actions 
	enum EPlayerActions
	{
		EPA_Left = 0,
		EPA_Right,
		EPA_Jump,
		EPA_Interact,

		// Cheap debug options - Will be removed - A.S-H
		EPA_ActivatePOne,
		EPA_ActivatePTwo,

		EPA_EMPTY // to distinguish between on screen keys and keyboard keys
	};
	// Player Actions 
	//////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////
	//Physics and contacts control

	virtual void BeginContact							( b2Contact* pB2Contact );
	virtual void EndContact								( b2Contact* pB2Contact );
	virtual void PreSolve								( b2Contact* pB2Contact, const b2Manifold* pOldManifold );
	virtual void PostSolve								( b2Contact* pB2Contact, const b2ContactImpulse* pImpulse );

	//Physics and contacts control
	/////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// IGCGameLayer interface

	virtual void	VOnCreate							( void );
	virtual void	onEnter								( void );
	virtual void	VOnReset							( void );
	virtual void	VOnUpdate							( f32 fTimeStep );
	virtual void	VOnDestroy							( void );

	// IGCGameLayer interface
	//////////////////////////////////////////////////////////////////////////

	void	InitializeLevel								( void );

	b2Vec2	GetPositionAsPixels							( float fSpacingX, float fSpacingY );

	void	AddOnScreenControls							( void );

	bool	IsGameOver									( void );

	// Check how many lives are remaining
	// This might be needed by the player object to set graphics (visual representation) of health/lives
	int		GetRemainingLives							( void );

	int getTimeInSecs									( );

	int PagesCollected									( );

	int GrimmsCollected									( );

	int GetNumOfEnemiesKilled							( );

	int GetStarLimit									( );

	virtual CIGCEventBaseListener::EListenError OnEvent	( CGCBaseEvent * ev ) override;

	void HandleMovementControllerEvents					( cocos2d::Ref * pSender , cocos2d::ui::Widget::TouchEventType eventType );

	void HandleJumpOrInteract							( cocos2d::Ref * pSender , cocos2d::ui::Widget::TouchEventType eventType );

private:
	EThemes		m_ETcurrTheme;
	bool		m_bLevelInitialsized;
	float		m_fTimeBetweenTeleports;
	int			m_iTotalLives;
	int			m_ipagesCollected;
	int			m_iGrimmsCollected;
	bool		m_bIsGameOver;				// Bool checking if the game has ended, for returning control to calling level. It is imperative that you DO NOT create another one of these.
	int			m_iNumOfLives;				// Number of remaining lives. If this is 0, the player lost the game and did not complete the level
	float32		m_fTimer;					// Time passed since level start, for star calculation
	int			m_iEnemiesKilled;			// Number of enemies killed, for star calculation
	bool		m_bSecondaryCollected;		// Bool, if the secondary collectible was collected (up to one per level)
	int			m_iStarTimeLimit;			// int, number of seconds after which you lose the third star
	const char* k_pszNarative;			// local storage for the narative;
	bool		m_bIsNarativeShowing;

	const char*											m_pszPlist_background;
	std::string											m_strLevelPath;
	const char*											m_pszBackgroundMusicPath;

	//Sound Engine reference poiner to play all sounds
	CocosDenshion::SimpleAudioEngine*					m_pSharedAudioEngine;

	//individual sound fx file paths
	const char* m_pszSoundProtagJumpFilePath			= "audio/sfx/sfx_protag_jump.wav";
	const char* m_pszSoundProtagDamageFilePath			= "audio/sfx/sfx_protag_damage.wav";
	const char* m_pszSoundProtagLandingFilePath			= "audio/sfx/sfx_protag_landing.wav";
	const char* m_pszSoundProtagDeathFilePath			= "audio/sfx/sfx_protag_death.wav";
	const char* m_pszSoundCollectiblePickUpFilePath		= "audio/sfx/sfx_collectible1.wav";
	const char* m_pszSoundMeeleDeathFilePath			= "audio/sfx/sfx_melee_death.wav";
	const char* m_pszSoundPlatformCollapseFilePath		= "audio/sfx/sfx_plat_collap.wav";
	const char* m_pszSoundPlatformTravellatorFilePath	= "audio/sfx/sfx_plat_travel.wav";
	const char* m_pszSoundVictoryFilePath				= "audio/sfx/sfx_ui_victory.wav";
	const char* m_pszSoundNarrativeFilePath				= "audio/sfx/sfx_ui_narrative.wav";


	/////////////////////////////////////////////////
	// Window Spacing & Grid Manipulation Variables
	/////////////////////////////////////////////////
	b2Vec2  m_v2BaseLevelVisibleSize;
	b2Vec2  m_v2BaseLevelVisibleSizeCentre;
	float   m_fBaseLevelVisibleSizeWidth;
	float   m_fBaseLevelVisibleSizeHeight;
	float   m_fBaseLevelOriginX;
	float   m_fBaseLevelOriginY;
	float   m_fBaseLevelGridSpacingX;
	float   m_fBaseLevelGridSpacingY;
	float	m_fBaseLevelSpacingValue;

	cocos2d::Label*										m_pNarativeLabel;			// Narative Label

	cocos2d::CCLayerColor*								m_pcBgLayer;				// Game Over Graying, as above
																		
	CGCLevelLoader_Ogmo*								m_pcLevelLoader;			// Level loader

	std::set<CGCObjPlatform*>							m_setpcSetOfPlatformsToSetUp;
	/////////////////////////////////////
	// Object Groups
	/////////////////////////////////////

	//platforms
	CGCObjGroupPlatform*								m_pcGCGroupPlatform;

	//Spikes
	CGCObjGroupSpikes*									m_pcGCGroupSpikes;

	//Main collectible
	CGCObjGroupMainCollectible*							m_pcGCGroupMainCollectible;

	// Second Collectible
	CGCObjGroupSecondCollectible*						m_pcGCGroupSecCollectible;

	//Ranged Enemy Projectiles
	CGCObjGroupRangedEnemyProjectile*					m_pcGCGroupProjectilesManager;

	//Ranged Enemies
	CGCObjGroupRangedEnemy*								m_pcGCGroupRangedEnemies;

	//Patrolling Enemies
	CGCObjGroupPatrollingEnemy*							m_pcGCGroupPatrollingEnemies;

	//Platform Posts
	CGCObjGroupPlatformPost*							m_pcGCGroupPlatformPosts;

	//Patrol Posts
	CGCObjGroupPatrolPost*								m_pcGCGroupPatrolPosts;

	//Gates
	CGCObjGroupGates*									m_pcGCGroupGates;

	//Switches
	CGCObjGroupSwitch*									m_pcGCGroupSwitches;
	
	//Walls
	CGCObjGroupWall*									m_pcGCGroupWalls;

	/////////////////////////////////////
	// Single Objects
	/////////////////////////////////////

	//CODE: We need to retrieve these from the object manager

	// Protag
	CGCObjPlayer*										m_pcGCOPlayer;

	//Goal
	CGCGoal*											m_pcGCOGoal;

	// background
	CGCObjSprite*										m_pcGCSprBackGround;

	CGCObjSwitch*										m_pcSwitch;

	// Power-up -- dropped for now
	//CGCObjPowerUp*						m_pcGCOPowerUp;

	//Ground
	b2Body*												m_pcGroundbox;

	// Debug Labels
	cocos2d::Label*										m_pDebugLabelOne;
	cocos2d::Label*										m_pDebugLabelTwo;
	cocos2d::Label*										m_pDebugLabelThree;
	cocos2d::Label*										m_pDebugLabelFour;
	cocos2d::Label*										m_pDebugLabelFive;
	cocos2d::Label*										m_pDebugLabelSix;
	cocos2d::Label*										m_pDebugLabelSeven;

	//Life counter. Pointers needed for Update.
	cocos2d::Sprite*									m_pLifeCounterSprite;
	cocos2d::Sprite*									m_pCollectableCounterSprite;

	//EVENT SYSTEM MANAGER
	CGCEventBaseManager*								m_pcEventManager;

	//Tier Switch Variables - Dropped for now
	//bool m_bInTier1;
	//unsigned long m_ulLastTierChangeTime;
	//bool m_bCanChangeTiers;

	//function that checks and returns if a player has been hit
	bool		GotHit									( void );

	void		HandleCollisions						( void );

	void		UpdateLifeCounter						( void );
	void		UpdateCollectableCounter				( void );

	void		LoadAllSoundsAndSfx						( void );
	void		PlaySoundEffect							( const char* sfxEffectFilePath );

	const char* GetNarative								( void ) const;
};

#endif // !_BASELEVEL_H_