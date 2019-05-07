#include "GamerCamp/GameSpecific/Levels/GCLevelBase.h"

//Event System
#ifndef _BASEEVENTMANAGER_H_
	#include "GamerCamp/GameSpecific/EventSystem/CGCEventBaseManager.h"  
#endif // !_BASEEVENTMANAGER_H_
#ifndef _BASEEVENT_H_
	#include "GamerCamp/GameSpecific/EventSystem/CGCBaseEvent.h"  
#endif // !_BASEEVENT_H_
#ifndef _BASEEVENTLISTENER_H_
	#include "GamerCamp/GameSpecific/EventSystem/CIGCEventBaseListener.h"  
#endif // !_BASEEVENTLISTENER_H_

//Groups
#ifndef _GCOBJECTGROUPPLATFORM_H_
	#include "GamerCamp/GameSpecific/Base/Platforms/GCObjGroupPlatform.h"  
#endif // !_GCOBJECTGROUPPLATFORM_H_
#ifndef _GCOBJECTGROUPSPIKES_H_
	#include "GamerCamp/GameSpecific/Base/Hazard/GCObjGroupSpikes.h"
#endif // !_GCOBJECTGROUPSPIKES_H_
#ifndef _GCOBJECTGROUPRANGEDENEMY_H_
	#include "GamerCamp/GameSpecific/Base/RangedEnemy/GCObjGroupRangedEnemy.h"  
#endif // !_GCOBJECTGROUPRANGEDENEMY_H_
#ifndef _GCOBJECTGROUPPATROLLINGENEMY_H_
	#include "GamerCamp/GameSpecific/Base/MeleeEnemy/GCObjGroupPatrollingEnemy.h"  
#endif // !_GCOBJECTGROUPPATROLLINGENEMY_H_
#ifndef _GCOBJGROUPRANGEDENEMYPROJECTILE_H_
	#include "GamerCamp/GameSpecific/Base/Projectile/GCObjGroupRangedEnemyProjectile.h"  
#endif // !_GCOBJGROUPRANGEDENEMYPROJECTILE_H_
#ifndef _GCOBJECTGROUPITEM_H_
	#include "GamerCamp/GameSpecific/CollectibleMain/GCObjGroupMainCollectible.h"  
#endif // !_GCOBJECTGROUPITEM_H_
#ifndef _GCOBJECTGROUPSECONDCOLLECTIBLE_H_
	#include "GamerCamp/GameSpecific/CollectibleGrimm/GCObjGroupSecondCollectible.h"  
#endif // !_GCOBJECTGROUPSECONDCOLLECTIBLE_H_
#ifndef _GCOBJECTGROUPPATROLPOST_H_
	#include "GamerCamp/GameSpecific/Base/PatrolPost/GCObjGroupPatrolPost.h"  
#endif // !_GCOBJECTGROUPPATROLPOST_H_
#ifndef _GCOBJECTGROUPPLATFORMPOST_H_
	#include "GamerCamp/GameSpecific/Base/PlatformPost/GCObjGroupPlatformPost.h"  
#endif // !_GCOBJECTGROUPPLATFORMPOST_H_
#ifndef _GCOBJECTGROUPGATES_H_
	#include "GamerCamp/GameSpecific/Base/Gate/GCObjGroupGates.h"
#endif
#ifndef _GCOBJECTGROUPSWITCHES_H_
	#include "GamerCamp/GameSpecific/Base/Switch/GCObjGroupSwitch.h"
#endif
#ifndef _GCOBJECTGROUPWALL_H_
	#include "GamerCamp/GameSpecific/Base/Walls/GCObjGroupWall.h"
#endif

//Non Inherited Base
#ifndef _GCOBJPLATFORMPOST_H_
	#include "GamerCamp/GameSpecific/Base/PlatformPost/GCObjPlatformPost.h"  
#endif // !_GCOBJPLATFORMPOST_H_
#ifndef _GCOBJPATROLPOST_H_
	#include "GamerCamp/GameSpecific/Base/PatrolPost/GCObjPatrolPost.h"  
#endif // !_GCOBJPATROLPOST_H_
#ifndef _GCOBJFLOOR_H_
	#include "GamerCamp/GameSpecific/Base/Floor/GCObjFloor.h"
#endif

//fantasy
#ifndef _GCOBJFANTASYPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Fantasy/Platforms/Static/GCObjFantasyPlatform.h" 
#endif // !_GCOBJFANTASYPLATFORMS_H_
#ifndef _GCOBJFANTASYCOLLAPSINGPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Fantasy/Platforms/Collapsible/GCObjFantasyCollapsingPlatform.h"
#endif // !_GCOBJFANTASYCOLLAPSINGPLATFORMS_H_
#ifndef _GCOBJFANTASYCATAPULTPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Fantasy/Platforms/Catapult/GCObjFantasyCatapultPlatform.h"  
#endif // !_GCOBJFANTASYCATAPULTPLATFORMS_H_
#ifndef _GCOBJFANTASYTRAVELLATORPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Fantasy/Platforms/Travellator/GCObjFantasyTravellatorPlatform.h"  
#endif // !_GCOBJFANTASYTRAVELLATORPLATFORMS_H_
#ifndef _GCOBJFANTASYMOVINGPLATFORM_H_
	#include "GamerCamp/GameSpecific/Fantasy/Platforms/Moving/GCObjFantasyMovingPlatform.h"  
#endif // !_GCOBJFANTASYMOVINGPLATFORM_H_
#ifndef _GCOBJFANTASYSPIKES_H_
	#include "GamerCamp/GameSpecific/Fantasy/Hazard/GCObjFantasySpikes.h"  
#endif // !_GCOBJFANTASYSPIKES_H_
#ifndef _GCOBJFANTASYRANGED_H_
	#include "GamerCamp/GameSpecific/Fantasy/RangedEnemy/GCObjFantasyRanged.h"  
#endif // !_GCOBJFANTASYRANGED_H_
#ifndef _GCOBJFANTASYMEELE_H_
	#include "GamerCamp/GameSpecific/Fantasy/MeleeEnemy/GCObjFantasyMelee.h"  
#endif // !_GCOBJFANTASYMEELE_H_
#ifndef _GCOBJFANTASYGATE_H_
#include "GamerCamp/GameSpecific/Fantasy/Gate/GCObjFantasyGate.h"
#endif
#ifndef _GCOBJFANTASYGATE2_H_
#include "GamerCamp/GameSpecific/Fantasy/Gate/GCObjFantasyGate2.h"
#endif
#ifndef _GCOBJFANTASYSWITCH_H_
#include "GamerCamp/GameSpecific/Fantasy/Switch/GCObjFantasySwitch.h"
#endif
#ifndef _GCOBJFANTASYSWITCH2_H_
#include "GamerCamp/GameSpecific/Fantasy/Switch/GCObjFantasySwitch2.h"
#endif
#ifndef _GCOBJFANTASYWALL_H_
	#include "GamerCamp/GameSpecific/Fantasy/Wall/GCObjFantasyWall.h"
#endif // !_GCOBJFANTASYWALL_H_
#ifndef _GCOBJFANTASYWALL4_H_
	#include "GamerCamp/GameSpecific/Fantasy/Wall/GCObjFantasyWall4.h"
#endif // !_GCOBJFANTASYWALL_H_
#ifndef _GCOBJFANTASYWALL5_H_
	#include "GamerCamp/GameSpecific/Fantasy/Wall/GCObjFantasyWall5.h"
#endif // !_GCOBJFANTASYWALL_H_
#ifndef _GCOBJFANTASYWALL11_H_
	#include "GamerCamp/GameSpecific/Fantasy/Wall/GCObjFantasyWall11.h"
#endif // !_GCOBJFANTASYWALL_H_

//collectibles
#ifndef _GCOBJMAINCOLLECTIBLE_H_
	#include "GamerCamp/GameSpecific/CollectibleMain/GCObjMainCollectible.h"  
#endif // !_GCOBJITEMS_H_
#ifndef _GCOBJSECONDCOLLECTIBLE_H_
	#include "GamerCamp/GameSpecific/CollectibleGrimm/GCObjSecondCollectible.h"  
#endif // !_GCOBJSECONDCOLLECTIBLE_H_

//dropped for now
//	#include "GamerCamp/GameSpecific/TierSwitch/CGCObjTierSwitch.h"

//goal
#ifndef _GCOBJGOAL_H_
	#include "GamerCamp/GameSpecific/Goal/CGCGoal.h"  
#endif // !_GCOBJGOAL_H_

//player data
#ifndef _GCOBJPLAYER_H_
	#include "GamerCamp/GameSpecific/Player/GCObjPlayer.h"  
#endif // !_GCOBJPLAYER_H_
#ifndef _GCGLOBALPLAYERDATA_H_
	#include "GamerCamp/GameSpecific/GlobalData/GCGlobalPlayerData.h"  
#endif // !_GCGLOBALPLAYERDATA_H_

//End Level Layer
#ifndef _GCENDGAMELAYER_H_
	#include "GamerCamp/GameSpecific/Menus/GCEndGameLayer.h"  
#endif // !_GCENDGAMELAYER_H_

#ifndef _GCCOCOSHELPERS_H_
	#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"  
#endif // !_GCCOCOSHELPERS_H_
#ifndef _APP_DELEGATE_H_
	#include "AppDelegate.h"
#endif // !_APP_DELEGATE_H_
#ifndef __MENUSCENE_H__
	#include "MenuScene.h"
#endif // !__MENUSCENE_H__
#ifndef __APPMACROS_H__
	#include "AppMacros.h"  
#endif // !__APPMACROS_H__

#ifndef _GCLEVELLOADER_OGMO_H_
	#include "GamerCamp/GCCocosInterface/LevelLoader/GCLevelLoader_Ogmo.h"
#endif

USING_NS_CC;

//GLOBAL - Needs to be accessible to many classes
b2Vec2 EnemyOffsetFromPlatform = b2Vec2 ( -31.0f, 42.0f );

CGCLevelBase::CGCLevelBase( const char*	pszPlist_background, std::string strLevelPath, const char* pszBackgroundMusicPath )
	: IGCGameLayer( GetGCTypeIDOf( CGCLevelBase ) )
	, m_pcGCOPlayer						( NULL )
	, m_pcGCGroupPlatform				( NULL )
	, m_pcGCGroupMainCollectible		( NULL )
	, m_pcGCGroupSecCollectible			( NULL )
	, m_pcGCGroupProjectilesManager		( NULL )
	, m_pcGCGroupRangedEnemies			( NULL )
	, m_pcGCGroupPatrollingEnemies		( NULL )
	, m_pcGCGroupSpikes					( NULL )
	, m_pcGCGroupWalls					( nullptr )
	, m_setpcSetOfPlatformsToSetUp ()			// Takes no arguments - NULL counts as int
	, m_bIsGameOver						( false )   // Has the game ended
	, m_iNumOfLives						( 3 )
	, m_iTotalLives						( 3 )
	, m_fTimer							( 0 )
	, m_iEnemiesKilled					( 0 )
	, m_bSecondaryCollected				( false )
	, m_bLevelInitialsized				( false )
	, m_iGrimmsCollected				( 0 )
	, m_ipagesCollected					( 0 )
	, m_pNarativeLabel					( NULL )
	, m_pcSwitch						(nullptr)
{
	m_pcEventManager = new CGCEventBaseManager();
	m_pcLevelLoader = new CGCLevelLoader_Ogmo( m_pcEventManager );
	m_pszPlist_background = pszPlist_background;
	m_strLevelPath = strLevelPath;
	m_pszBackgroundMusicPath = pszBackgroundMusicPath;
}

CGCLevelBase::~CGCLevelBase ()
{
	delete m_pcEventManager;
	delete m_pcLevelLoader;
}

void CGCLevelBase::VOnCreate ( void )
{
	// create the default object group
	IGCGameLayer::VOnCreate();

	m_pcEventManager->RegisterEventType( "PlayerCreated" );
	m_pcEventManager->RegisterEventType( "GoalCreated" );
	m_pcEventManager->RegisterEventType( "PlatformToSetUp" );

	m_pcEventManager->RegisterAsListener( this, "PlayerCreated" );
	m_pcEventManager->RegisterAsListener( this, "GoalCreated" );
	m_pcEventManager->RegisterAsListener( this, "PlatformToSetUp" );

	//Set world gravity
	B2dGetWorld ()->SetGravity ( b2Vec2 ( 0.0f, -80.0f ) );

	//Initialization
	m_bIsGameOver = false;
	m_iNumOfLives = 3;
	m_fTimer = 0.0f;

	///////////////////////////////////////////////////////////////////////////
	// Member Variable Assignment  
	///////////////////////////////////////////////////////////////////////////

	Size visibleSize = Director::getInstance ()->getVisibleSize ();
	Point origin = Director::getInstance ()->getVisibleOrigin ();

	// Memory Efficiency Placement variables
	m_fBaseLevelOriginX = origin.x;
	m_fBaseLevelOriginY = origin.y;

	m_fBaseLevelGridSpacingX = designGridScaleSize.width;
	m_fBaseLevelGridSpacingY = designGridScaleSize.height;

	// For detecting time between teleports 
	m_fTimeBetweenTeleports = 0.0f;

	// For detecting Teleportation limits
	// m _ v2 VisibleSize
	m_v2BaseLevelVisibleSize = b2Vec2 ( visibleSize.width, visibleSize.height );

	// For single axis calculations 
	// m_v2VisibleSize . x
	m_fBaseLevelVisibleSizeWidth = m_v2BaseLevelVisibleSize.x;
	m_fBaseLevelVisibleSizeHeight = m_v2BaseLevelVisibleSize.y;

	m_fBaseLevelSpacingValue = m_fBaseLevelVisibleSizeWidth / m_fBaseLevelGridSpacingX;

	// Centre of screen is a position assigned many times 
	m_v2BaseLevelVisibleSizeCentre = b2Vec2 ( ( m_fBaseLevelVisibleSizeWidth / 2.0f ),
		( m_fBaseLevelVisibleSizeHeight / 2.0f ) );

	///////////////////////////////////////////////////////////////////////////
	// default object group
	///////////////////////////////////////////////////////////////////////////

	// Repeating values - More memory efficient to define as such
	f32 fOpacityValue = 120.0f;
	Vec2 v2Anchor = Vec2 ( 0.0f, 0.0f );

	///////////////////////////////////////////////////////////////////////////
	// add label
	///////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Debug options that display various player stats for movement
	// Used to refine the control system 
	// Conversion method to be generated every frame
	// Reference: https://stackoverflow.com/questions/1374468/stringstream-string-and-char-conversion-confusion
	//
	// N.B All commented out as debugging is not currently needed - Only used to test player movement
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	m_pDebugLabelOne = Label::createWithTTF( "v2TotalForce X = ", "fonts/bokka_solid_regular.ttf", 48 );
	m_pDebugLabelOne->setColor( ccc3( 255, 0, 0 ) );
	m_pDebugLabelOne->setPosition( Vec2( m_fBaseLevelVisibleSizeWidth / 15, visibleSize.height + 100 ) );

	this->addChild( m_pDebugLabelOne, 1 );
	m_pDebugLabelTwo = Label::createWithTTF( "fVelocity = ", "fonts/bokka_solid_regular.ttf", 48 );
	m_pDebugLabelTwo->setColor( ccc3( 255, 0, 0 ) );
	m_pDebugLabelTwo->setPosition( Vec2( m_fBaseLevelVisibleSizeWidth / 2, visibleSize.height - 100 ) );

	this->addChild( m_pDebugLabelTwo, 1 );

	m_pDebugLabelThree = Label::createWithTTF( "Velocity Unit X = ", "fonts/bokka_solid_regular.ttf", 48 );
	m_pDebugLabelThree->setColor( ccc3( 255, 0, 0 ) );
	m_pDebugLabelThree->setPosition( Vec2( m_fBaseLevelVisibleSizeWidth / 2, visibleSize.height - 150 ) );

	this->addChild( m_pDebugLabelThree, 1 );

	m_pDebugLabelFour = Label::createWithTTF( "Linear Drag * Velocity = ", "fonts/bokka_solid_regular.ttf", 48 );
	m_pDebugLabelFour->setColor( ccc3( 255, 0, 0 ) );
	m_pDebugLabelFour->setPosition( Vec2( m_fBaseLevelVisibleSizeWidth / 2, visibleSize.height - 200 ) );

	this->addChild( m_pDebugLabelFour, 1 );

	m_pDebugLabelFive = Label::createWithTTF( "Drag Square * Velocity Square = ", "fonts/bokka_solid_regular.ttf", 48 );
	m_pDebugLabelFive->setColor( ccc3( 255, 0, 0 ) );
	m_pDebugLabelFive->setPosition( Vec2( m_fBaseLevelVisibleSizeWidth / 2, visibleSize.height - 250 ) );

	this->addChild( m_pDebugLabelFive, 1 );

	m_pDebugLabelSix = Label::createWithTTF( "No Input Drag = ", "fonts/bokka_solid_regular.ttf", 48 );
	m_pDebugLabelSix->setColor( ccc3( 255, 0, 0 ) );
	m_pDebugLabelSix->setPosition( Vec2( m_fBaseLevelVisibleSizeWidth / 2, visibleSize.height - 300 ) );

	this->addChild( m_pDebugLabelSix, 1 );

	m_pDebugLabelSeven = Label::createWithTTF( "V2 Total Force Y = ", "fonts/bokka_solid_regular.ttf", 48 );
	m_pDebugLabelSeven->setColor( ccc3( 255, 0, 0 ) );
	m_pDebugLabelSeven->setPosition( Vec2( m_fBaseLevelVisibleSizeWidth / 2, visibleSize.height - 350 ) );

	this->addChild( m_pDebugLabelSeven, 1 );
	*/

	///////////////////////////////////////////////////////////////////////////
	// set up physics 
	///////////////////////////////////////////////////////////////////////////

	// set "self" as contact listener
	B2dGetWorld ()->SetContactListener ( this );

	// load the physics shapes from the plist created with PhysicsEditor
	B2dLoadShapesFromPlist		( "PhysicsEditor/GameShapes.plist" );

	///////////////////////////////////////////////////////////////////////////
	// stop player from leaving the screen
	///////////////////////////////////////////////////////////////////////////

	// PTM_RATIO
	f32 PTM_RATIO = IGCGAMELAYER_B2D_PIXELS_PER_METER;

	b2Vec2 v2ScreenCentre_Pixels	( ( m_fBaseLevelOriginX + ( m_fBaseLevelVisibleSizeWidth * 0.5f ) ),
		( m_fBaseLevelOriginY + ( visibleSize.height * 0.5f ) ) );

	// define the ground body
	b2BodyDef groundBodyDef;
	groundBodyDef.position = IGCGameLayer::B2dPixelsToWorld ( v2ScreenCentre_Pixels );
	groundBodyDef.type = b2_kinematicBody;

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.

	//b2Body* groundBody = B2dGetWorld()->CreateBody( &groundBodyDef );
	m_pcGroundbox = B2dGetWorld ()->CreateBody ( &groundBodyDef );

	// Define the ground box shape.
	b2PolygonShape groundBox;

	// bottom
	groundBox.SetAsBox ( ( ( m_fBaseLevelVisibleSizeWidth * 0.5f ) / PTM_RATIO ), 0.5f,
		b2Vec2 ( 0.0f, -( ( visibleSize.height * 0.5f ) / PTM_RATIO ) ), 0.0f );
	m_pcGroundbox->CreateFixture ( &groundBox, 1 );

	// top
	groundBox.SetAsBox ( ( ( m_fBaseLevelVisibleSizeWidth * 0.5f ) / PTM_RATIO ), 0.5f,
		b2Vec2 ( 0.0f, ( ( visibleSize.height * 0.5f ) / PTM_RATIO ) ), 0.0f );
	m_pcGroundbox->CreateFixture ( &groundBox, 1 );

	// left
	groundBox.SetAsBox ( 2.5f, ( ( m_fBaseLevelVisibleSizeHeight * 0.5f ) / PTM_RATIO ),
		b2Vec2 ( -( ( m_fBaseLevelVisibleSizeWidth * 0.5f ) / PTM_RATIO ), 0.0f ), 0.0f );
	m_pcGroundbox->CreateFixture ( &groundBox, 1 );

	// right
	groundBox.SetAsBox ( 3.0f, ( ( m_fBaseLevelVisibleSizeHeight * 0.5f ) / PTM_RATIO ),
		b2Vec2 ( ( ( m_fBaseLevelVisibleSizeWidth * 0.5f ) / PTM_RATIO ), 0.0f ), 0.0f );
	m_pcGroundbox->CreateFixture ( &groundBox, 1 );

	/////////////////////////////////////////////
	// EVENT MANAGER
	/////////////////////////////////////////////

	m_pcEventManager = new CGCEventBaseManager();


	///////////////////////////////////////////////////////////////////////////
	// custom object groups
	//
	// N.B. Cannot do this in CGCObjectGroup internally on construction, 
	// because ObjectGroupRegister calls a virtual function 
	// in the CGCObjectManager interface to check the 
	// types of objects that the group handles
	//
	// A registration must be made for each group type
	//
	// We will be adding groups on a level to level basis, as needed
	// Platforms are always needed
	///////////////////////////////////////////////////////////////////////////

	// Platform object group
	m_pcGCGroupPlatform = new CGCObjGroupPlatform();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupPlatform );

	//Other groups (for OGMO use)
	m_pcGCGroupPlatformPosts = new CGCObjGroupPlatformPost();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupPlatformPosts );

	// Spikes object group
	m_pcGCGroupSpikes = new CGCObjGroupSpikes();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupSpikes );

	// Main Collectibles object group
	m_pcGCGroupMainCollectible = new CGCObjGroupMainCollectible();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupMainCollectible );

	// Secondary Collectibles object group
	m_pcGCGroupSecCollectible = new CGCObjGroupSecondCollectible();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupSecCollectible );

	// Patrolling Enemy object group
	m_pcGCGroupPatrollingEnemies = new CGCObjGroupPatrollingEnemy();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupPatrollingEnemies );

	m_pcGCGroupPatrolPosts = new CGCObjGroupPatrolPost();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupPatrolPosts );

	//Ranged Enemies object group
	m_pcGCGroupRangedEnemies = new CGCObjGroupRangedEnemy();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupRangedEnemies );

	// Enemy projectile object group
	m_pcGCGroupProjectilesManager = new CGCObjGroupRangedEnemyProjectile( m_ETcurrTheme );
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupProjectilesManager );

	//Gates Object Group
	m_pcGCGroupGates = new CGCObjGroupGates();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupGates );

	//Switches Object Group
	m_pcGCGroupSwitches = new CGCObjGroupSwitch();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupSwitches );

	//Walls Object Group
	m_pcGCGroupWalls = new CGCObjGroupWall();
	CGCObjectManager::ObjectGroupRegister( m_pcGCGroupWalls );

	LoadAllSoundsAndSfx ();

	///////////////////////////////////////////////////////////////////////////
	// Create narative Label (Do not add here)
	///////////////////////////////////////////////////////////////////////////
	m_pNarativeLabel = Label::createWithTTF( " ", "fonts/open_dyslexic_regular.ttf", 34 );

	/*m_pNarativeLabel->setColor( ccc3( 255, 255, 255 ) );
	m_pNarativeLabel->enableOutline( ccc4( 120, 63, 4, 255 ), 3 );*/
	m_pNarativeLabel->setColor ( ccc3 ( 120 , 63 , 4 ) );
	
	// Position label
	m_pNarativeLabel->setPosition( Vec2( origin.x + ( visibleSize.width * 0.58f ), ( origin.y + ( visibleSize.height*0.04f ) ) ) );
	m_pNarativeLabel->setDimensions( m_fBaseLevelVisibleSizeWidth*0.5f, m_fBaseLevelVisibleSizeHeight*0.2f );
	m_pNarativeLabel->enableWrap( true );

	addChild( m_pNarativeLabel, 1 );

	///////////////////////////////////////////////////////////////////////////
	// Add Health Counter
	///////////////////////////////////////////////////////////////////////////
	const char* pszPngHealthBackgroundPath = "Loose/heart_box.png";
	m_pLifeCounterSprite = Sprite::create ( pszPngHealthBackgroundPath );
	m_pLifeCounterSprite->setPosition ( Vec2 ( m_fBaseLevelOriginX + ( m_fBaseLevelVisibleSizeWidth / 2 ),
		m_fBaseLevelOriginY + m_fBaseLevelVisibleSizeHeight - ( m_pLifeCounterSprite->getContentSize().height / 2 ) ) );

	// add the Sprite as a child to this layer
	this->addChild ( m_pLifeCounterSprite, 1 );

	///////////////////////////////////////////////////////////////////////////
	// Add Collectable Counter
	///////////////////////////////////////////////////////////////////////////

	const char* pszPngCollectableBackgroundPath = "Loose/collectables_box.png";
	m_pCollectableCounterSprite = Sprite::create ( pszPngCollectableBackgroundPath );
	m_pCollectableCounterSprite->setPosition ( Vec2 ( m_fBaseLevelOriginX + m_fBaseLevelVisibleSizeWidth - ( m_pLifeCounterSprite->getContentSize ().width / 2 ),
		m_fBaseLevelOriginY + m_fBaseLevelVisibleSizeHeight - ( m_pLifeCounterSprite->getContentSize ().height / 2 ) ) );

	// add the Sprite as a child to this layer
	this->addChild ( m_pCollectableCounterSprite, 1 );

	UpdateLifeCounter ();

	////////////////////////////////////////////
	// BACKGROUND
	////////////////////////////////////////////

	m_pcGCSprBackGround = new CGCObjSprite();
	m_pcGCSprBackGround->CreateSprite( m_pszPlist_background );
	m_pcGCSprBackGround->SetResetPosition( b2Vec2( m_fBaseLevelVisibleSizeWidth / 2, visibleSize.height / 2 ) );
	m_pcGCSprBackGround->SetParent( this );

	m_pSharedAudioEngine->playBackgroundMusic( m_pszBackgroundMusicPath );

	if (!CCUserDefault::sharedUserDefault()->getBoolForKey( CGCGlobalPlayerData::s_pMusicPlayingKey, false ))
	{
		m_pSharedAudioEngine->pauseBackgroundMusic();
	}

	m_pcLevelLoader->LoadLevelFile( FileUtils::getInstance()->fullPathForFilename( m_strLevelPath ).c_str() );
	m_ETcurrTheme = m_pcLevelLoader->GetLevelTheme();
	m_iStarTimeLimit = m_pcLevelLoader->GetLevelTimeLimit();
	k_pszNarative = m_pcLevelLoader->GetNarative();
	m_pcLevelLoader->CreateObjects( CGCFactory_ObjSpritePhysics::GetFactory() );

	m_pcGCOPlayer = dynamic_cast<CGCObjPlayer*>	(CGCObjectManager::FindObject( NULL, GetGCTypeIDOf( CGCObjPlayer ) ));
	m_pcGCOGoal = dynamic_cast<CGCGoal*>		(CGCObjectManager::FindObject( NULL, GetGCTypeIDOf( CGCGoal ) ));

}

void CGCLevelBase::LoadAllSoundsAndSfx ( void )
{
	// load background sound
	m_pSharedAudioEngine = CocosDenshion::SimpleAudioEngine::getInstance ();
	m_pSharedAudioEngine->preloadBackgroundMusic ( m_pszBackgroundMusicPath );

	m_pSharedAudioEngine->preloadEffect( m_pszSoundProtagJumpFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundProtagDamageFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundProtagLandingFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundProtagDeathFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundCollectiblePickUpFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundMeeleDeathFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundPlatformCollapseFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundPlatformTravellatorFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundVictoryFilePath );
	m_pSharedAudioEngine->preloadEffect( m_pszSoundNarrativeFilePath );

	m_pSharedAudioEngine->preloadEffect ( CGCGlobalPlayerData::s_pPageTransitionSoundPath );

}

void CGCLevelBase::PlaySoundEffect ( const char * sfxEffectFilePath )
{
 	if ( CCUserDefault::sharedUserDefault ( )->getBoolForKey ( CGCGlobalPlayerData::s_pMusicPlayingKey , true ) )
	{
		//m_pSharedAudioEngine->stopAllEffects ( );
		m_pSharedAudioEngine->playEffect ( sfxEffectFilePath , false , 1.0f , 1.0f );
	}
}

const char * CGCLevelBase::GetNarative( void ) const
{
	return k_pszNarative;
}

///////////////////////////////////////////////////////////////////////////////////////////
// GetPositionAsPixels retruns the location that an object should spawn at in a level
// fSpacingX & fSpacingY are based on the current grid size being used 
// These values are taken from an array of positions and passing in the 2 numerical values
// Always returns a b2Vec2 that sets the position 
///////////////////////////////////////////////////////////////////////////////////////////
b2Vec2 CGCLevelBase::GetPositionAsPixels( float fSpacingX, float fSpacingY )
{
	return b2Vec2( ( m_fBaseLevelOriginX + ( m_fBaseLevelSpacingValue * fSpacingX ) ),
		( m_fBaseLevelOriginY + ( m_fBaseLevelSpacingValue * fSpacingY ) ) );
}


CIGCEventBaseListener::EListenError CGCLevelBase::OnEvent( CGCBaseEvent * ev )
{
	const char* dataname = "pointer";
	// 
	// 	if (ev->GetEventName() == "PlatformToSetUp")
	// 	{
	// 		m_setpcSetOfPlatformsToSetUp.insert( ev->GetDataByName<CGCObjPlatform*>( dataname ) );
	// 	}
	// 	else
	// 	{
	// 		return CIGCEventBaseListener::EListenError_EventDataTypeMismatch;
	// 	}

	return EListenError::EListenError_Ok;
}

///////////////////////////////////////////////////////////////////////////////////////
// VOnUpdate is called every frame and updates the GameLayer in the appropriate manner
// m_fTimer is a protected member f32 variable that updates a visual timer
// m_bLevelInitialised determines if next frame needs to initialise the level 
// i.e. the frist frame when accessed
// Default constructor for a virtual accessor used by all levels
// Function always returns 'void'
///////////////////////////////////////////////////////////////////////////////////////
void CGCLevelBase::VOnUpdate ( f32 fTimeStep )
{
	m_fTimer += fTimeStep;
	/*int mins = m_fTimer / 60;
	int secs = ( int )( m_fTimer - ( mins * 60 ) );
	int totalSecs = ( int ) m_fTimer;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Conversion method to be generated every frame
	// Reference: https://stackoverflow.com/questions/1374468/stringstream-string-and-char-conversion-confusion
	////////////////////////////////////////////////////////////////////////////////////////////////////////////

	stringstream ssDebugOne;
	ssDebugOne << "v2TotalForce X = " << m_pcGCOPlayer->GetV2TotalForce().x;
	//string& sDebugOne = ssDebugOne.str();
	//m_pLabel->setString ( sDebugOne );

	stringstream ssDebugTwo;
	ssDebugTwo << "fDragForce = " << m_pcGCOPlayer->GetV2DragForce();
	string& sDebugTwo = ssDebugTwo.str();
	m_pDebugLabelOne->setString ( sDebugTwo );

	stringstream ssDebugThree;
	ssDebugThree << "fVelocity = " << m_pcGCOPlayer->GetVelocity().x;
	string& sDebugThree = ssDebugThree.str();
	m_pDebugLabelTwo->setString ( sDebugThree );

	stringstream ssDebugFour;
	ssDebugFour << "Velocity Unit X = " << m_pcGCOPlayer->GetV2VelocityUnit().x;
	string& sDebugFour = ssDebugFour.str();
	m_pDebugLabelThree->setString ( sDebugFour );

	stringstream ssDebugFive;
	ssDebugFive << "Linear Drag * Velocity = " << ( m_pcGCOPlayer->m_fDragCoefficient_Linear * m_pcGCOPlayer->fVelocity );
	string& sDebugFive = ssDebugFive.str();
	m_pDebugLabelFour->setString ( sDebugFive );

	stringstream ssDebugSix;
	ssDebugSix << "Drag Square * Velocity Square = " << ( m_pcGCOPlayer->m_fDragCoefficient_Square * ( m_pcGCOPlayer->fVelocity * m_pcGCOPlayer->fVelocity ) );
	string& sDebugSix = ssDebugSix.str();
	m_pDebugLabelFive->setString ( sDebugSix );

	stringstream ssDebugSeven;
	ssDebugSeven << "No Input Drag = " << ( m_pcGCOPlayer->m_fNoInput_ExtraDrag_Square * ( m_pcGCOPlayer->fVelocity * m_pcGCOPlayer->fVelocity ) * m_pcGCOPlayer->fIsInputInactive );
	string& sDebugSeven = ssDebugSeven.str();
	m_pDebugLabelSix->setString ( sDebugSeven );

	stringstream ssDebugEight;
	ssDebugEight << "V2 Total Force Y = " << m_pcGCOPlayer->v2TotalForce.y;
	string& sDebugEight = ssDebugEight.str();
	m_pDebugLabelSeven->setString ( sDebugEight );
	*/

	if ( !m_bLevelInitialsized )
	{
		InitializeLevel ();
		m_bLevelInitialsized = true;
	}

	// Show the narative if all collectibles have been picked up
	if ( !m_bIsNarativeShowing )
	{
		if ( 0 == m_pcGCGroupMainCollectible->GetNumberOfRemainingCoins() )
		{
			m_pNarativeLabel->setString( k_pszNarative );
			m_bIsNarativeShowing = true;
			PlaySoundEffect ( m_pszSoundNarrativeFilePath );
		}
	}

	m_ipagesCollected = m_pcGCGroupMainCollectible->GetNumberOfCapturedCoins();
	UpdateCollectableCounter();

	// Open the exit up when at least one collectible has been picked up
	if ( m_ipagesCollected>0 )
	{
		//m_pcGCOGoal->SetVisible( true );
		m_pcGCOGoal->SetOpacity( 255 );
		m_pcGCOGoal->Activate( true );
	}

	m_pcGCGroupRangedEnemies->FlipObjects( m_pcGCOPlayer->GetPositionX() );

	IGCGameLayer::VOnUpdate ( fTimeStep );

	AppDelegate::GetKeyboardManager ()->Update ();

	HandleCollisions ();

}

///////////////////////////////////////////////////////////////////////////////////////
//When called in VOnUpdate(), the goal is disabled (Only visible once conditions are met by player)
// If the platforms have not been setup i.e. no positions have been assigned, do so now
// CGCObjPlatform3* calls SetUp() by pointer
// Functions always returns 'void'
///////////////////////////////////////////////////////////////////////////////////////
void CGCLevelBase::InitializeLevel ( void )
{
	//m_pcGCOGoal->SetVisible ( false );
	//m_pcGCOGoal->SetOpacity ( 150 );
	m_pcGCOGoal->Activate	( false );

	m_pcGCGroupPlatform->SetUp();

	//This function connects gates with switches, using both groups.
	//Each switch gets a pointer to its connected gate.
	m_pcGCGroupSwitches->SetUp( m_pcGCGroupGates );
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Cleans up any object group allocated in opposite order to creation
// If statements are required as not all managers are guaranteed to have been initialized
// Each 'if' checks for the value of the appropriate group variable
// If applicable, memory for that group is deallocated, stopping memory leaks
// Each variable checked is therefore set to 'nullptr' to not break the program
// m_pcGCOPlayer & m_pcGCOGoal are always be deleted as player & goal always spawn: Only ever once instance per level
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
void CGCLevelBase::VOnDestroy ( void )
{
	delete m_pcGCOPlayer;
	m_pcGCOPlayer = nullptr;

	delete m_pcGCOGoal;
	m_pcGCOGoal = nullptr;

	delete m_pcEventManager;
	m_pcEventManager = nullptr;

	/*delete m_pcGroundbox;
	m_pcGroundbox = nullptr;*/

	//m_setpcSetOfPlatformsToSetUp.clear();

	if (m_pcGCGroupWalls)
	{
		CGCObjectManager::ObjectGroupUnRegister( m_pcGCGroupWalls );
		delete m_pcGCGroupWalls;
		m_pcGCGroupWalls = nullptr;
	}

	if ( m_pcGCGroupPlatform )
	{
		// Platform object group
		CGCObjectManager::ObjectGroupUnRegister ( m_pcGCGroupPlatform );
		delete m_pcGCGroupPlatform;
		m_pcGCGroupPlatform = nullptr;
	}

	if ( m_pcGCGroupPlatformPosts )
	{
		// Moving platform posts object group
		CGCObjectManager::ObjectGroupUnRegister( m_pcGCGroupPlatformPosts );
		delete m_pcGCGroupPlatformPosts;
		m_pcGCGroupPlatformPosts = nullptr;
	}

	if ( m_pcGCGroupSpikes )
	{
		// Main Collectibles object group
		CGCObjectManager::ObjectGroupUnRegister ( m_pcGCGroupSpikes );
		delete m_pcGCGroupSpikes;
		m_pcGCGroupSpikes = nullptr;

	}

	if ( m_pcGCGroupMainCollectible )
	{
		// Main Collectibles object group
		CGCObjectManager::ObjectGroupUnRegister ( m_pcGCGroupMainCollectible );
		delete m_pcGCGroupMainCollectible;
		m_pcGCGroupMainCollectible = nullptr;
	}

	if ( m_pcGCGroupSecCollectible )
	{
		// Secondary Collectibles object group
		CGCObjectManager::ObjectGroupUnRegister ( m_pcGCGroupSecCollectible );
		delete m_pcGCGroupSecCollectible;
		m_pcGCGroupSecCollectible = nullptr;
	}

	// Both types are created together
	// Either none are created or both types are created
	if ( m_pcGCGroupRangedEnemies )
	{
		//Ranged Enemies object group
		CGCObjectManager::ObjectGroupUnRegister ( m_pcGCGroupRangedEnemies );
		delete m_pcGCGroupRangedEnemies;
		m_pcGCGroupRangedEnemies = nullptr;

		// Enemy projectile object group
		CGCObjectManager::ObjectGroupUnRegister ( m_pcGCGroupProjectilesManager );
		delete m_pcGCGroupProjectilesManager;
		m_pcGCGroupProjectilesManager = nullptr;
	}

	// Both types are created together
	// Either none are created or both types are created
	if ( m_pcGCGroupPatrollingEnemies )
	{
		// Patrolling Enemy object group
		CGCObjectManager::ObjectGroupUnRegister( m_pcGCGroupPatrollingEnemies );
		delete m_pcGCGroupPatrollingEnemies;
		m_pcGCGroupPatrollingEnemies = nullptr;

		// Patrolling Enemy posts object group
		CGCObjectManager::ObjectGroupUnRegister( m_pcGCGroupPatrolPosts );
		delete m_pcGCGroupPatrolPosts;
		m_pcGCGroupPatrolPosts = nullptr;
	}

	if ( m_pcGCGroupGates )
	{
		CGCObjectManager::ObjectGroupUnRegister( m_pcGCGroupGates );
		delete m_pcGCGroupGates;
		m_pcGCGroupGates = nullptr;
	}

	if ( m_pcGCGroupSwitches )
	{
		CGCObjectManager::ObjectGroupUnRegister( m_pcGCGroupSwitches );
		delete m_pcGCGroupSwitches;
		m_pcGCGroupSwitches = nullptr;
	}

	IGCGameLayer::VOnDestroy ();
}

void CGCLevelBase::AddOnScreenControls ( void )
{
}

bool CGCLevelBase::IsGameOver( void )
{
	return m_bIsGameOver;
}

//////////////////////////////////////////////////////////////////////////////////////
// Is tied to the virtual touch control system implemented in the UI
// Any time a UI button is pressed, perform the appropriate controls
// Modular to fit each new UI button added, ensure that the TouchEventType is assigned
// Can be expanded upon to fit any number of buttons
// Function returns 'void'
//////////////////////////////////////////////////////////////////////////////////////
void CGCLevelBase::HandleMovementControllerEvents ( cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType )
{
	if ( cocos2d::ui::Widget::TouchEventType::ENDED == eventType )
	{
		m_pcGCOPlayer->SetIsPlayerMoving ( false );
		m_pcGCOPlayer->SetPlayerMovingDirection ( -1 );
	}


	//this should fix the controls problem.
	if(cocos2d::ui::Widget::TouchEventType::CANCELED == eventType)
	{
		m_pcGCOPlayer->SetIsPlayerMoving( false );
		m_pcGCOPlayer->SetPlayerMovingDirection( -1 );
	}

	if ( ( ( cocos2d::ui::Widget::TouchEventType::BEGAN == eventType ) || cocos2d::ui::Widget::TouchEventType::MOVED == eventType ) )
	{
		m_pcGCOPlayer->SetIsPlayerMoving ( true );

		if ( ( ( cocos2d::ui::Button* ) pSender )->getActionTag () == ACTION_MOVE_LEFT )
		{
			m_pcGCOPlayer->SetPlayerMovingDirection ( EPA_Left );
		}
		else if ( ( ( cocos2d::ui::Button* ) pSender )->getActionTag () == ACTION_MOVE_RIGHT )
		{
			m_pcGCOPlayer->SetPlayerMovingDirection ( EPA_Right );
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////
//This function handles the jump or interact from on screen control
// Function returns 'void'
//////////////////////////////////////////////////////////////////////////////////////
void CGCLevelBase::HandleJumpOrInteract ( cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType eventType )
{
	//since there is no interact button on screen
	//no need to check the tag
	if ( cocos2d::ui::Widget::TouchEventType::BEGAN == eventType )
	{
		PlaySoundEffect( m_pszSoundProtagJumpFilePath );
		m_pcGCOPlayer->Jump();
	}

	//This is texst call to check the UI of end level layer
	//please remove once UI of end layer is done
	//ShowEndGameLayer ( );
}

//////////////////////////////////////////////////////////////////////////////
// Team Two Edit
// Declare any specific methods or variables as the level is entered
// IGCGameLayer::onEnter() ensures base level cocos2d functionality is working
// Then initialise Keyboard Action Map and set u32 value to size of the Map 
// This overrides any previous Map - Can be specific to a level if needed
// Override for specific levels will be called in their own onEnter() function
// Function always returns 'void'
//////////////////////////////////////////////////////////////////////////////
void CGCLevelBase::onEnter ()
{
	IGCGameLayer::onEnter ();

	//////////////////////////////////////////////////////////////////////////
	// init the actions
	// N.B. these 

	cocos2d::EventKeyboard::KeyCode aeKeyCodesForMovement[] =
	{
		EventKeyboard::KeyCode::KEY_A,		// EPA_Up,
		EventKeyboard::KeyCode::KEY_D,		// EPA_Down,
		EventKeyboard::KeyCode::KEY_SPACE,	// EPA_Jump	
		EventKeyboard::KeyCode::KEY_X,		// EPA_Interact

		EventKeyboard::KeyCode::KEY_G,		// EPA_ActivatePOne
		EventKeyboard::KeyCode::KEY_H		// EPA_ActivatePTwo
	};

	u32 uSizeOfMovementArray = ( sizeof ( aeKeyCodesForMovement ) / sizeof ( cocos2d::EventKeyboard::KeyCode ) );

	// call base class function	to init the keyboard manager
	AppDelegate::InitialiseKeyboardManager ( uSizeOfMovementArray, aeKeyCodesForMovement );

	m_pSharedAudioEngine->playBackgroundMusic( m_pszBackgroundMusicPath, true );
	// play backgorund sound
	if (!CCUserDefault::getInstance()->getBoolForKey( CGCGlobalPlayerData::s_pMusicPlayingKey ))
	{
		m_pSharedAudioEngine->pauseBackgroundMusic();
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// VOnReset is called every time a level needs to be restarted (from the pause menu)
// It is called BEFORE VOnResurected()
// Ensures all values that can be changed once a level has been generated to their default values
// Lives are restored, no collectibles are picked up etc.
// This is the base Reset function that enables all other Reset functions in other classes
//////////////////////////////////////////////////////////////////////////////////////////////////
void CGCLevelBase::VOnReset( void )
{
	// load the physics shapes from the plist created with PhysicsEditor
	B2dLoadShapesFromPlist		( "PhysicsEditor/GameShapes.plist" );

	IGCGameLayer::VOnReset();

	m_bIsNarativeShowing = false;
	m_pNarativeLabel->setString( " " );
	m_bLevelInitialsized = false;
	m_ipagesCollected = 0;
	m_bIsGameOver = false;				// Bool checking if the game has ended, for returning control to calling level. It is imperative that you DO NOT create another one of these.
	m_iNumOfLives = 3;					// Number of remaining lives. If this is 0, the player lost the game and did not complete the level
	m_fTimer = 0.0f;					// Time passed since level start, for star calculation
	m_iEnemiesKilled = 0;				// Number of enemies killed, for star calculation
	m_bSecondaryCollected = false;		// Bool, if the secondary collectible was collected (up to one per level)

	UpdateLifeCounter();
	m_pCollectableCounterSprite->removeAllChildrenWithCleanup ( true );
}

///////////////////////////////////////////////////////////////////////////////
// begin contact
// insert any logic that relies on detecting the first frame where a 
// contact exists
//
// Team Two Edit
// On the first frame of a collision occuring, obtain the two objects
// If either object is set to NULL, return
// Function always returns 'void'
///////////////////////////////////////////////////////////////////////////////
//virtual 
void CGCLevelBase::BeginContact( b2Contact* pB2Contact )
{
	const b2Fixture* pFixtureA = pB2Contact->GetFixtureA();
	const b2Fixture* pFixtureB = pB2Contact->GetFixtureB();

	const b2Body* pBodyA = pFixtureA->GetBody();
	const b2Body* pBodyB = pFixtureB->GetBody();

	CGCObjSpritePhysics* pGcSprPhysA = ( CGCObjSpritePhysics* )pBodyA->GetUserData();
	CGCObjSpritePhysics* pGcSprPhysB = ( CGCObjSpritePhysics* )pBodyB->GetUserData();

	// if( this is not a GC object )
	if ( pGcSprPhysA == NULL )
	{
		return;
	}

	// if( this is not a GC object )
	if ( pGcSprPhysB == NULL )
	{
		return;
	}

	// If a contact has occured & the two objects are of != GCTypeID
	if ( pB2Contact->IsEnabled()
		&& ( pGcSprPhysA->GetGCTypeID() != pGcSprPhysB->GetGCTypeID() ) )
	{

		if ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer )
			|| pGcSprPhysB->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) )
		{
			CGCObjSpritePhysics*	player = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) ) ? pGcSprPhysA : pGcSprPhysB;
			CGCObjSpritePhysics*	notPlayer = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) ) ? pGcSprPhysB : pGcSprPhysA;
			const b2Fixture*		PlayerFixture = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) ) ? pFixtureA : pFixtureB;
			const b2Fixture*		notPlayerFixture = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) ) ? pFixtureB : pFixtureA;


			if ( GetGCTypeIDOf( CGCObjPlatform ) == notPlayer->GetGCTypeID() )
			{
				CGCObjPlatform * plat = dynamic_cast<CGCObjPlatform*>( notPlayer );
				//only set to grounded (allow jump) if the player's FEET SENSOR is ABOVE the platform
				if ( PlayerFixture->IsSensor() )
				{
					if ( m_pcGCOPlayer->GetPositionY() > plat->GetPositionY() )
					{
						PlaySoundEffect( m_pszSoundProtagLandingFilePath );
						m_pcGCOPlayer->Grounded();
					}
				}

				if ( plat->VIsCollapsingPlatform() )
				{
					//So that the platform only triggers when you are on it, not when you touch it from below
					if (m_pcGCOPlayer->GetPositionY() > plat->GetPositionY())
					{
						if (((CGCObjCollapsingPlatform *)notPlayer)->IsCollidingPlatformActive())
						{
							PlaySoundEffect( m_pszSoundPlatformCollapseFilePath );
							((CGCObjCollapsingPlatform *)notPlayer)->SetIsCollidingPlatformActive( false );
						}
					}
				}
				else if ( plat->VIsCatapultPlatform() )
				{
					m_pcGCOPlayer->liftoff();
				}
			}

			// Fulfills condition of the level ending but with the player winning
			if ( GetGCTypeIDOf( CGCGoal ) == notPlayer->GetGCTypeID() )
			{
				PlaySoundEffect( m_pszSoundVictoryFilePath );
				m_bIsGameOver = true;
			}

			if ( GetGCTypeIDOf( CGCObjSwitch ) == notPlayer->GetGCTypeID() )
			{
				if ( m_pcSwitch )
				{
					return;
				}
				m_pcSwitch = dynamic_cast<CGCObjSwitch*>( notPlayer );
				m_pcSwitch->Interact();
			}


			if ( ( GetGCTypeIDOf( CGCObjRangedEnemy ) == notPlayer->GetGCTypeID() )
				|| ( GetGCTypeIDOf( CGCObjRangedEnemyProjectile ) == notPlayer->GetGCTypeID()
					|| GetGCTypeIDOf( CGCObjPatrollingEnemy ) == notPlayer->GetGCTypeID() ) )
			{
				//If you hit the enemy in the head (fixture name), kill the enemy, otherwise get hit
				//this does nothing for projectiles
				if ( notPlayerFixture->IsSensor() )
				{
					const std::string*	pstrCheckMe = cocos2d::GB2ShapeCache::getFixtureIdText( notPlayerFixture );

					if ( 0 == pstrCheckMe->compare( "head" ) )
					{
						//GotHit();
						//UpdateLifeCounter();
						PlaySoundEffect( m_pszSoundMeeleDeathFilePath );
						// If the player has no more lives, they have lost the level
						if ( m_iNumOfLives == 0 )
						{
							PlaySoundEffect( m_pszSoundProtagDeathFilePath );
							m_bIsGameOver = true;
						}
						PlaySoundEffect( m_pszSoundMeeleDeathFilePath );
						if (GetGCTypeIDOf( CGCObjRangedEnemy ) == notPlayer->GetGCTypeID())
						{
							CGCObjFantasyRanged* enemy = static_cast<CGCObjFantasyRanged*>(notPlayer);
							enemy->KillAnimation();
						}
						else if (GetGCTypeIDOf( CGCObjPatrollingEnemy ) == notPlayer->GetGCTypeID())
						{
							CGCObjFantasyMeele* enemy = static_cast<CGCObjFantasyMeele*>(notPlayer);
							enemy->KillAnimation();
						}
						++m_iEnemiesKilled;
					}
				}
				else
				{
					if ( GetGCTypeIDOf( CGCObjRangedEnemyProjectile ) == notPlayer->GetGCTypeID() )
					{
						CGCObjectManager::ObjectKill( notPlayer );
					}
					if ( GotHit() )
					{
						UpdateLifeCounter();
						// If the player has no more lives, they have lost the level
						if ( m_iNumOfLives == 0 )
						{
							PlaySoundEffect ( m_pszSoundProtagDeathFilePath );
							m_bIsGameOver = true;
						}
					}
				}
			}

			// If player collides with collectible
			if ( GetGCTypeIDOf( CGCObjMainCollectible ) == notPlayer->GetGCTypeID() )
			{
				PlaySoundEffect( m_pszSoundCollectiblePickUpFilePath );
				CGCObjectManager::ObjectKill( notPlayer );
			}

			// If player collides with shield power-up
			// Not currently implemented
			if ( GetGCTypeIDOf( CGCObjSecondCollectible ) == notPlayer->GetGCTypeID() )
			{
				CGCObjectManager::ObjectKill( notPlayer );
				m_bSecondaryCollected = true;
			}

			////////////////////////////////////////////////
			// Other functionality can be implemented here with "else if"s
			// i.e. notPlayer is of another type
			// Start Collisions can be defined here
			////////////////////////////////////////////////		
		}

		// If either object is of type CGCObjPatrollingEnemy (contact with platform, start patrolling)
		else if ( GetGCTypeIDOf( CGCObjPatrollingEnemy ) == pGcSprPhysA->GetGCTypeID()
			|| GetGCTypeIDOf( CGCObjPatrollingEnemy ) == pGcSprPhysB->GetGCTypeID() )
		{
			CGCObjSpritePhysics*	invader = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPatrollingEnemy ) ) ? pGcSprPhysA : pGcSprPhysB;
			CGCObjSpritePhysics*	isPlatform = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPatrollingEnemy ) ) ? pGcSprPhysB : pGcSprPhysA;

			CGCObjPatrollingEnemy* patrolling = dynamic_cast<CGCObjPatrollingEnemy*>( invader );

			if ( GetGCTypeIDOf( CGCObjPlatform ) == isPlatform->GetGCTypeID() )
			{
				patrolling->Grounded();
			}
			else if ( GetGCTypeIDOf( CGCObjPatrolPost ) == isPlatform->GetGCTypeID() )
			{
				patrolling->TurnBack();
			}
		}

		else if ( GetGCTypeIDOf( CGCObjPlatform ) == pGcSprPhysA->GetGCTypeID()
			|| GetGCTypeIDOf( CGCObjPlatform ) == pGcSprPhysB->GetGCTypeID() )
		{
			CGCObjSpritePhysics*	Platform = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlatform ) ) ? pGcSprPhysA : pGcSprPhysB;
			CGCObjSpritePhysics*	isPost = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlatform ) ) ? pGcSprPhysB : pGcSprPhysA;

			if ( GetGCTypeIDOf( CGCObjPlatformPost ) == isPost->GetGCTypeID() )
			{
				CGCObjPlatform* isMoving = dynamic_cast<CGCObjPlatform*>( Platform );

				if ( isMoving->VIsMovingPlatform() )
				{
					CGCObjMovingPlatform* Moving = dynamic_cast<CGCObjMovingPlatform*>( isMoving );
					Moving->TurnBack();
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
// end contact
// insert any logic that relies on detecting the last frame where a 
// contact exists
//
// Team Two Edit
// Checks a Collision pair and ends the collision
// If either object is set to NULL, return
// Function always returns 'void'
//
// Example found in void CGCGameLayerPlatformer::EndContact( b2Contact* pB2Contact )
///////////////////////////////////////////////////////////////////////////////////////////////
//virtual 
void CGCLevelBase::EndContact ( b2Contact* pB2Contact )
{
	const b2Fixture* pFixtureA = pB2Contact->GetFixtureA ();
	const b2Fixture* pFixtureB = pB2Contact->GetFixtureB ();

	const b2Body* pBodyA = pFixtureA->GetBody ();
	const b2Body* pBodyB = pFixtureB->GetBody ();

	CGCObjSpritePhysics* pGcSprPhysA = ( CGCObjSpritePhysics* )pBodyA->GetUserData ();
	// if( this is not a GC object )
	if ( pGcSprPhysA == NULL )
	{
		return;
	}

	CGCObjSpritePhysics* pGcSprPhysB = ( CGCObjSpritePhysics* )pBodyB->GetUserData ();
	// if( this is not a GC object )
	if ( pGcSprPhysB == NULL )
	{
		return;
	}

	////////////////////////////////////////////////////////////////////////////////
	// If a contact has occured & the two objects are of != GCTypeID
	// Determine at least one object's GCTypeID, enter that GCTypeID's if statements
	// Detemine the second object's GCTypeID then apply context specific interaction
	// Modular so can be expanded to fit any GCTypeID as needed
	////////////////////////////////////////////////////////////////////////////////
	if ( pB2Contact->IsEnabled ()
		&& ( pGcSprPhysA->GetGCTypeID () != pGcSprPhysB->GetGCTypeID () ) )
	{
		if ( pGcSprPhysA->GetGCTypeID () == GetGCTypeIDOf ( CGCObjPlayer )
			|| pGcSprPhysB->GetGCTypeID () == GetGCTypeIDOf ( CGCObjPlayer ) )
		{
			CGCObjSpritePhysics*	player = ( pGcSprPhysA->GetGCTypeID () == GetGCTypeIDOf ( CGCObjPlayer ) ) ? pGcSprPhysA : pGcSprPhysB;
			CGCObjSpritePhysics*	notPlayer = ( pGcSprPhysA->GetGCTypeID () == GetGCTypeIDOf ( CGCObjPlayer ) ) ? pGcSprPhysB : pGcSprPhysA;

			if ( GetGCTypeIDOf ( CGCObjPlatform ) == notPlayer->GetGCTypeID () )
			{
				CGCObjPlatform* isMoving = dynamic_cast<CGCObjPlatform*>( notPlayer );
				if ( !isMoving->VIsMovingPlatform() )
				{
					m_pcGCOPlayer->Airborne();
					//Do not process again in the VOnUpdate
					pB2Contact->SetEnabled( false );
				}
				else if ( isMoving->VIsTravellatorPlatform() )
				{
					//VITAL: So that it does not get processed again in HandleCollisions()
					pB2Contact->SetEnabled( false );
				}
			}
			else if ( GetGCTypeIDOf( CGCObjSwitch ) == notPlayer->GetGCTypeID() )
			{
				m_pcSwitch = nullptr;
			}

			////////////////////////////////////////////////
			// Other functionality can be implemented here
			// i.e. notPlayer is of another type
			// Exit Collisions can be defined here
			////////////////////////////////////////////////		
		}
	}
}

///////////////////////////////////////////////////////////////////////
// pre solve
// insert any logic that needs to be done before a contact is resolved
//
// Team Two Edit
// Checks and Sets the two objects that are colliding
// If either objects is set to NULL, return
// If both objects have a GCTypeID, check for the collision
// Any meaningful value is set outside of this function
// This function always returns 'void'
//
// Example found in void CGCGameLayerPlatformer.cpp
///////////////////////////////////////////////////////////////////////
//virtual 
void CGCLevelBase::PreSolve ( b2Contact* pB2Contact, const b2Manifold* pOldManifold )
{
	const b2Fixture* pFixtureA = pB2Contact->GetFixtureA ();
	const b2Fixture* pFixtureB = pB2Contact->GetFixtureB ();

	const b2Body* pBodyA = pFixtureA->GetBody ();
	const b2Body* pBodyB = pFixtureB->GetBody ();

	CGCObjSpritePhysics* pGcSprPhysA = ( CGCObjSpritePhysics* )pBodyA->GetUserData ();
	// if( this is not a GC object )
	if ( pGcSprPhysA == NULL )
	{
		return;
	}

	CGCObjSpritePhysics* pGcSprPhysB = ( CGCObjSpritePhysics* )pBodyB->GetUserData ();
	// if( this is not a GC object )
	if ( pGcSprPhysB == NULL )
	{
		return;
	}

	// If both pGcSprPhysA & pGcSprPhysB are not of the same GCTypeID
	if ( pGcSprPhysA->GetGCTypeID () != pGcSprPhysB->GetGCTypeID () )
	{
		// If pGcSprPhysA/pGcSprPhysB is of type CGCObjRangedEnemyProjectile
		// And collides with any object not of type CGCObjPlayer
		if ( ( ( pGcSprPhysA->GetGCTypeID () == GetGCTypeIDOf ( CGCObjRangedEnemyProjectile ) )
			&& ( pGcSprPhysB->GetGCTypeID () != GetGCTypeIDOf ( CGCObjPlayer ) ) )
			|| ( ( pGcSprPhysA->GetGCTypeID () != GetGCTypeIDOf ( CGCObjPlayer ) )
				&& ( pGcSprPhysB->GetGCTypeID () == GetGCTypeIDOf ( CGCObjRangedEnemyProjectile ) ) ) )
		{
			// Ignore collision
			pB2Contact->SetEnabled ( false );
		}
		else if ( ( ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlatform ) )
			&& ( pGcSprPhysB->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) ) )
			|| ( ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) )
				&& ( pGcSprPhysB->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlatform ) ) ) )
		{
			CGCObjSpritePhysics* pPlayer = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) ) ? pGcSprPhysA : pGcSprPhysB;
			CGCObjSpritePhysics* pPlatform = ( pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ) ) ? pGcSprPhysB : pGcSprPhysA;

			CGCObjPlatform* isPassThrough = dynamic_cast<CGCObjPlatform*>( pPlatform );
			if (isPassThrough->VIsMovingPlatform()) //moving platforms pass through
			{
				if (m_pcGCOPlayer->GetPositionY() <= isPassThrough->GetPositionY()) //We want the player to pass through even if the platform is the one moving
				{
					pB2Contact->SetEnabled( false );
				}
				else if (m_pcGCOPlayer->GetVerticalVelocity() > 0.1f) //We want the player to pass through When moving upwards
				{
					pB2Contact->SetEnabled( false );
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
// post solve
// insert any logic that needs to be done after a contact is resolved
// e.g. check the types and double the impulse
///////////////////////////////////////////////////////////////////////////////
//virtual 
void CGCLevelBase::PostSolve ( b2Contact* pB2Contact, const b2ContactImpulse* pImpulse )
{
}

////////////////////////////////////////////////////////////
// Determines if player has been hit by anything
// If the player has been hit, m_iNumOfLives is decremented
// Will always return 'true' or 'false'
////////////////////////////////////////////////////////////
bool CGCLevelBase::GotHit ( void )
{
	if ( m_pcGCOPlayer->gotHit() )
	{
		PlaySoundEffect ( m_pszSoundProtagDamageFilePath );
		--m_iNumOfLives;
		if (m_iNumOfLives <= 0)
		{
			m_bIsGameOver = true;
		}
		return true;
	}
	return false;
}

///////////////////////////////////////////////////////////////////////////////
// Returns int for the current lives player has left in this level
///////////////////////////////////////////////////////////////////////////////
int CGCLevelBase::GetRemainingLives ( void )
{
	return m_iNumOfLives;
}

int CGCLevelBase::getTimeInSecs()
{
	return ( int )round( m_fTimer );
}

int CGCLevelBase::PagesCollected()
{
	return m_ipagesCollected;
}

int CGCLevelBase::GrimmsCollected()
{
	return m_iGrimmsCollected;
}

int CGCLevelBase::GetNumOfEnemiesKilled()
{
	return m_iEnemiesKilled;
}

int CGCLevelBase::GetStarLimit()
{
	return m_iStarTimeLimit;
}

///////////////////////////////////////////////////////////////////////////////
// Handles collilisions that must have effects in every update, for example, travellator contact
// or ranged enemy sensor contact. In other words, effects that must be active WHILE in contact,
// not just on contact (like say, platforms collapsing or enemies dying)
void CGCLevelBase::HandleCollisions( void )
{
	// check for collisions

	for ( const b2Contact* pB2Contact = IGCGameLayer::ActiveInstance()->B2dGetWorld()->GetContactList();
		NULL != pB2Contact;
		pB2Contact = pB2Contact->GetNext() )
	{
		const b2Fixture* pFixtureA = pB2Contact->GetFixtureA();
		const b2Fixture* pFixtureB = pB2Contact->GetFixtureB();

		const b2Body* pBodyA = pFixtureA->GetBody();
		const b2Body* pBodyB = pFixtureB->GetBody();

		// return if either physics body has null user data
		CGCObjSpritePhysics* pGcSprPhysA = ( CGCObjSpritePhysics* )pBodyA->GetUserData();
		if ( !pGcSprPhysA )
		{
			return;
		}

		CGCObjSpritePhysics* pGcSprPhysB = ( CGCObjSpritePhysics* )pBodyB->GetUserData();
		if ( !pGcSprPhysB )
		{
			return;
		}

		// If both pGcSprPhysA & pGcSprPhysB are not of the same GCTypeID
		if ( pB2Contact->IsEnabled()
			&& ( pGcSprPhysA->GetGCTypeID() != pGcSprPhysB->GetGCTypeID() ) )
		{

			// If pGcSprPhysA || pGcSprPhysB is of GCTypeID CGCObjPlayer 
			if ((pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer ))
				|| (pGcSprPhysB->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer )))
			{
				CGCObjSpritePhysics*	player = (pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer )) ? pGcSprPhysA : pGcSprPhysB;
				CGCObjSpritePhysics*	notPlayer = (pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer )) ? pGcSprPhysB : pGcSprPhysA;
				const b2Fixture*		notPlayerFixture = (pGcSprPhysA->GetGCTypeID() == GetGCTypeIDOf( CGCObjPlayer )) ? pFixtureB : pFixtureA;

				// If player collides with platform
				if (GetGCTypeIDOf( CGCObjPlatform ) == notPlayer->GetGCTypeID())
				{
					m_pcGCOPlayer->CheckGrounded();

					CGCObjPlatform* isPassThrough = dynamic_cast<CGCObjPlatform*>(notPlayer);
					CGCObjPlatform* plat = static_cast<CGCObjPlatform*>(notPlayer);
					if (plat->VIsTravellatorPlatform())
					{
						//Set the travellator speed here
						float travellatorSpeed = 6.0f;

						switch (((CGCObjTravellatorPlatform *)notPlayer)->GetTravellatorDirection())
						{
						case CGCObjTravellatorPlatform::EDirection::EDirection_Left:
							m_pcGCOPlayer->SetExternalSpeed( b2Vec2( -travellatorSpeed, 0.0f ) );
							break;
						case CGCObjTravellatorPlatform::EDirection::EDirection_Right:
							m_pcGCOPlayer->SetExternalSpeed( b2Vec2( travellatorSpeed, 0.0f ) );
							break;
						default:
							break;
						}

					}
					else if (plat->VIsMovingPlatform()) //Send the moving platform's velocity to the player to adjust speed
					{
						m_pcGCOPlayer->SetExternalSpeed( plat->GetVelocity() );
					}

				}
				else if (GetGCTypeIDOf( CGCObjRangedEnemy ) == notPlayer->GetGCTypeID())
				{
					if (notPlayerFixture->IsSensor())
					{
						const std::string*	pstrCheckMe = cocos2d::GB2ShapeCache::getFixtureIdText( notPlayerFixture );
						if (0 == pstrCheckMe->compare( "scanner" ))
						{
							//Only Ranged enemies have scanners
							//We need to call the Theme class to run the animation. We can switch on the theme variable here.
							((CGCObjFantasyRanged*)notPlayer)->VFireProjectile();
						}
					}
				}
				//We need this here now because we want damage to be continuous after you recover from first impact
				else if (GetGCTypeIDOf( CGCObjSpikes ) == notPlayer->GetGCTypeID())
				{
					/*
					PlaySoundEffect ( m_pszSoundProtagDeathFilePath );
					m_iNumOfLives = 0;
					m_bIsGameOver = true;
					*/
					if (GotHit())
					{
						UpdateLifeCounter();
					}
				}
			}
		}
	}
}

void CGCLevelBase::UpdateLifeCounter( void )
{
	m_pLifeCounterSprite->removeAllChildrenWithCleanup ( false );

	const char* pszPngHealthIcon = "Loose/gui_heart.png";

	for ( int i = 0; i < m_iTotalLives; ++i )
	{
		CCSprite* pLifeSprite = new CCSprite ();
		pLifeSprite->initWithFile ( pszPngHealthIcon );

		float xAxisPos = m_pLifeCounterSprite->getContentSize ().width / 2;
		if ( i < ( m_iTotalLives / 2 ) )
		{
			xAxisPos -= ( pLifeSprite->getContentSize ().width * 1.5 );
		}
		else if ( i > ( m_iTotalLives / 2 ) )
		{
			xAxisPos += ( pLifeSprite->getContentSize ().width * 1.5 );
		}

		pLifeSprite->setPosition ( xAxisPos, m_pLifeCounterSprite->getContentSize().height / 2 );
		if ( i >= m_iNumOfLives )
		{
			pLifeSprite->setVisible ( false );
		}

		m_pLifeCounterSprite->addChild ( pLifeSprite, 1 );
	}
}

void CGCLevelBase::UpdateCollectableCounter ( void )
{

	if (m_pCollectableCounterSprite->getChildrenCount() == m_ipagesCollected)
	{
		return;
	}

	const char* pszPngCollectableIcon = "Loose/gui_page.png";

	CCSprite* pCollectableSprite = new CCSprite ();
	pCollectableSprite->initWithFile ( pszPngCollectableIcon );

	float xAxisPos = m_pLifeCounterSprite->getContentSize ().width / 2;
	if ( m_ipagesCollected == 1 )
	{
		xAxisPos -= ( pCollectableSprite->getContentSize ().width * 1.35 );
	}
	else if ( m_ipagesCollected == 2 )
	{
		xAxisPos -= ( pCollectableSprite->getContentSize ( ).width * 0.1f );
	}
	else if ( m_ipagesCollected == 3 )
	{
		xAxisPos += ( pCollectableSprite->getContentSize ().width * 1.1 );
	}

	pCollectableSprite->setPosition ( xAxisPos, m_pLifeCounterSprite->getContentSize ().height / 2 );
	m_pCollectableCounterSprite->addChild ( pCollectableSprite, 1 );

}