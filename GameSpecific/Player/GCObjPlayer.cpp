////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory.h>

#include "AppDelegate.h"

#ifndef _GCCOCOSHELPERS_H_
	#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#endif // !_GCCOCOSHELPERS_H_

#ifndef _LEVELBASE_H_
	#include "GamerCamp/GameSpecific/Levels/GCLevelBase.h"
#endif // !_LEVELBASE_H_

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif // !_GCOBJECTMANAGER_H_


#ifndef _GCGLOBALPLAYERDATA_H_
	#include "GamerCamp/GameSpecific/GlobalData/GCGlobalPlayerData.h"
#endif // !_GCGLOBALPLAYERDATA_H_

//#include "GamerCamp/GameSpecific/Interactable/Interactable.h"

#include "GCObjPlayer.h"

USING_NS_CC;


//////////////////////////////////////////////////////////////////////////
// GetGCTypeIDOf uses the template in GCTypeID to generate a unique ID for 
// this type - need this to construct our base type
CGCObjPlayer::CGCObjPlayer()
	: CGCObjSpritePhysics( GetGCTypeIDOf( CGCObjPlayer ) )
	//, m_pProjectileManager			( NULL )
	, m_bIsAirborne						( true )
	, m_fLastHitTime					( 0.0f )
	, m_fHorizontalMovementSpeed		( 0.0f )
	, m_bIsInvincible					( false )
	, m_bWasFalling						( false )
	, m_bWasMoving						( false )
{
}

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjPlayer );


//////////////////////////////////////////////////////////////////////////////////////////////////////
// Grounded & Airborne check if the player is currently moving on the y-axis
// If they are moving up or down, it is assumed that the player is not touching the ground
// Takes in single private variable: m_bIsAirborne 
// m_bIsAirborne defaults to 'true' and is assumed to always be as such until vertical movement occurs
//
// Grounded is called in void CGCLevelBase::BeginContact( b2Contact* pB2Contact )
// Airborne is called in void CGCLevelBase::EndContact	( b2Contact* pB2Contact )
//
// Both functions return void
// Subject to change later in development
//////////////////////////////////////////////////////////////////////////////////////////////////////
void CGCObjPlayer::Grounded( void )
{
	if (m_bIsAirborne)
	{
		// All actions relating to motion need to be stopped
		// Edge case - Touching the edge of a platform causes it to break if they are not
		StopAllActions();
		m_bWasMoving = false;
		m_bWasFalling = false;
		RunAction	( m_pALand );
	}
	m_bIsAirborne = false;
}

void CGCObjPlayer::Airborne( void )
{
	if (abs( GetPhysicsBody()->GetLinearVelocity().y ) > 0.15f)
	{
		m_bIsAirborne = true;
	}
}

void CGCObjPlayer::CheckGrounded( void )
{
	if (m_bIsAirborne)
	{
		if (abs( GetPhysicsBody()->GetLinearVelocity().y ) < 0.1f)
		{
			Grounded();
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjPlayer::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed
	m_fJumpHeight = 1600.0f;

	//Cocos Helpers might cause this to break on Android, because Android filepaths "might be" case-sensitive.
	//If necessary, AND ONLY IF NECESSARY, go to Perforce, source assets folder, right-click each "Frames" folder (in each object) and rename it to "frames".

	const char* pszPlist_Protag			= "TexturePacker/Sprites/Protag/Protag.plist";
	const char* pszAnim_ProtagWalk		= "Walk";
	const char* pszAnim_ProtagJump		= "Jump";
	const char* pszAnim_ProtagLand		= "Land";
	const char* pszAnim_ProtagDamage	= "Damage";
	const char* pszAnim_ProtagIdle1		= "Idle_1";
	const char* pszAnim_ProtagIdle2		= "Idle_2";

	ValueMap dicPList = GCCocosHelpers::CreateDictionaryFromPlist( pszPlist_Protag );
	m_pAWalk	= GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ProtagWalk ) ); //repeat forever until stopped
	m_pAWalk->retain();
	m_pAJump	= GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ProtagJump ) ); //run once
	m_pAJump->retain();
	m_pALand	= GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ProtagLand ) ); //run once
	m_pALand->retain();
	m_pADamage	= GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ProtagDamage ) ); //run once
	m_pADamage->retain();
	m_pAIdle_1 = GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ProtagIdle1 ) ); //run once
	m_pAIdle_1->retain();
	m_pAIdle_2 = GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ProtagIdle2 ) ); //run once
	m_pAIdle_2->retain();
}

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjPlayer::VOnReset( void )
{
	CGCObjSpritePhysics::VOnReset();

	// reset velocity and flip state
	SetFlippedX( false );
	SetFlippedY( false );

	// reset. This does not run. There is no Physics body at this point
	if ( GetPhysicsBody() )
	{
		GetPhysicsBody()->SetLinearVelocity( b2Vec2( 0.0f, 0.0f ) );
		GetPhysicsBody()->SetTransform( IGCGameLayer::B2dPixelsToWorld( GetSpritePosition() ), 0.0f );
		GetPhysicsBody()->SetFixedRotation( true );
		GetPhysicsBody()->SetGravityScale( 100.0f );
	}

	m_v2ExternalSpeed = b2Vec2_zero;
	m_fHorizontalMovementSpeed = 0;
	m_bIsInvincible = false;

}

void CGCObjPlayer::VOnResurrected( void )
{
	CGCObjSpritePhysics::VOnResurrected();
	
}

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjPlayer::VOnUpdate( f32 fTimeStep )
{
	if ( m_bIsShieldActive )
	{
		m_fShieldRemainingTime -= fTimeStep;

		if ( m_fShieldRemainingTime <= 0 )
		{
			m_bIsShieldActive = false;
			m_fShieldRemainingTime = 0.0f;
		}
	}

	if ( m_fLastHitTime > 3.0f ) {
		m_bIsInvincible = false;
		m_fLastHitTime = 0.0f;
		SetVisible( true );
	}
	else if ( m_bIsInvincible )
	{
		m_fLastHitTime += fTimeStep;
		SetVisible( !IsVisible() );
	}

	// handle movement
	UpdateMovement( fTimeStep );
}

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual
void CGCObjPlayer::VOnResourceRelease( void )
{
	DestroySprite();
	m_pAWalk->release();
	m_pADamage->release();
	m_pALand->release();
	m_pAJump->release();
	m_pAIdle_1->release();
	m_pAIdle_2->release();
}

//////////////////////////////////////////////////////////////////////////
// updates the movement of the CCSprite owned by this instance
//
//////////////////////////////////////////////////////////////////////////
void CGCObjPlayer::UpdateMovement( f32 fTimeStep )
{
	// these 2 floats are used to add / remove the effect of various terms 
	// in equations based on whether input has been applied this frame
	//Now needed for starting the walking animation
	fIsInputInactive = 1.0f;

	const CGCKeyboardManager* pKeyManager = AppDelegate::GetKeyboardManager();

	//check if keyboard key is pressed or is the on screen control has triggered onTouchBegan
	if ( pKeyManager->ActionIsPressed( CGCLevelBase::EPA_Left ) ||
		( m_bIsPlayerMoving && m_iPlayerMovingDirection == CGCLevelBase::EPA_Left ) )
	{
		if (m_fHorizontalMovementSpeed > 0)
		{
			//if you want the player to stop immediately when changing directions (instead of slowing down), uncomment the following line in both cases
			m_fHorizontalMovementSpeed = 0.0f;
		}
		if (m_fHorizontalMovementSpeed > -m_fHorizontalMovementLimit)
		{
			m_fHorizontalMovementSpeed -= m_fHorizontalMovementIncrement;
		}
		fIsInputInactive = 0.0f;
	}
	else if ( pKeyManager->ActionIsPressed( CGCLevelBase::EPA_Right ) ||
		( m_bIsPlayerMoving && m_iPlayerMovingDirection == CGCLevelBase::EPA_Right ) )
	{
		if (m_fHorizontalMovementSpeed < 0)
		{
			//if you want the player to stop immediately when changing directions (instead of slowing down), uncomment the following line in both cases
			m_fHorizontalMovementSpeed = 0.0f;
		}
		if (m_fHorizontalMovementSpeed < m_fHorizontalMovementLimit)
		{
			m_fHorizontalMovementSpeed += m_fHorizontalMovementIncrement;
		}
		fIsInputInactive = 0.0f;
	}
	else //slowing down (friction emulation. Increase the value to slow down faster).
	{
		if (!m_bIsAirborne) //Obviously no friction while airborne
		{
			float f_frictionefficiency = 75.0f;
			if (m_fHorizontalMovementSpeed < 0)
			{
				m_fHorizontalMovementSpeed += f_frictionefficiency;
				if (m_fHorizontalMovementSpeed > 0)
				{
					m_fHorizontalMovementSpeed = 0.0f;
				}
			}
			else
			{
				m_fHorizontalMovementSpeed -= f_frictionefficiency;
				if (m_fHorizontalMovementSpeed < 0)
				{
					m_fHorizontalMovementSpeed = 0.0f;
				}
			}
		}
	}

	if (!m_bIsAirborne)
	{
		if (fIsInputInactive == 0.0f)
		{
			if (!m_bWasMoving)
			{
				StopAllActions();
				RunAction( m_pAWalk );
				m_bWasMoving = true;
			}
		}
		else
		{
			if (m_bWasMoving)
			{
				StopAction( m_pAWalk );
				m_bWasMoving = false;
				(rand() % 3 != 0) ? RunAction( m_pAIdle_1 ) : RunAction( m_pAIdle_2 );
			}
		}
	}



	if ( pKeyManager->ActionIsPressed( CGCLevelBase::EPA_Jump ) )
	{
		Jump();
	}

	float vertical = GetVerticalVelocity();

	if (vertical >= 0)
	{
		if (m_v2ExternalSpeed.y > 0) //on moving platform, going up
		{
			if (vertical < m_v2ExternalSpeed.y)
			{
				vertical = m_v2ExternalSpeed.y + 2.0f; //Correction needed for moving platform going upwards.
			}
		}
	}

	//Yes, it bumps when the moving platform is going up. I will fix it later.
	GetPhysicsBody()->SetLinearVelocity( b2Vec2( m_fHorizontalMovementSpeed + m_v2ExternalSpeed.x, vertical ) );

	if (m_fHorizontalMovementSpeed > 0.0f )
	{
		SetFlippedX( true );
	}
	else if (m_fHorizontalMovementSpeed < 0.0f )
	{
		SetFlippedX( false );
	}

	//Important: Reset on the end of every update
	m_v2ExternalSpeed = b2Vec2_zero;
}

void CGCObjPlayer::SetIsPlayerMoving( bool isMoving )
{
	m_bIsPlayerMoving = isMoving;
}

bool CGCObjPlayer::GetIsPlayerMoving( void )
{
	return m_bIsPlayerMoving;
}

void CGCObjPlayer::SetPlayerMovingDirection( int movingDirection )
{
	m_iPlayerMovingDirection = movingDirection;
}

int CGCObjPlayer::GetPlayerMovingDirection( void )
{
	return m_iPlayerMovingDirection;
}

//////////////////////////////////////////////////////////////////////////////
// A currently defunct function that worked with original 'Switch' Mechanic
// Is not currently used but retained for potential use in future builds
// Returns void
//////////////////////////////////////////////////////////////////////////////
//void CGCObjPlayer::SetToBackground(bool bsetValue)
//{
//	GetPhysicsBody()->ApplyLinearImpulse(b2Vec2(0.0f, 15.0f), GetPhysicsBody()->GetPosition(), true);
//
//	if (bsetValue)
//	{
//		//SetScale(0.6f);
//		auto ScaleTo = cocos2d::ScaleTo::create(1.3f, 0.6f);
//		RunAction(ScaleTo);
//		//SetOpacity(128);
//
//	}
//	else
//	{
//		//SetScale(1.0f);
//		auto ScaleTo = cocos2d::ScaleTo::create(1.3f, 1.0f);
//		RunAction(ScaleTo);
//		//SetOpacity(255);
//	}
//}

//////////////////////////////////////////////////////////////////////////
// Determines if the player has been hit by an enemy or a projectile
// If Private Member variable 'm_bIsInvincible' is false, returns true
// Default case returns false
// Must always return true or false
// Called by bool CGCLevelBase::GotHit( void )
//////////////////////////////////////////////////////////////////////////
bool CGCObjPlayer::gotHit( void )
{
	//if (m_bIsShieldActive)
	//{
	//	return false;
	//}
	if ( !m_bIsInvincible )
	{
		StopAllActions();
		RunAction( m_pADamage );
		m_fLastHitTime = 0;
		m_bIsInvincible = true;
		m_bIsAirborne = true;
		//impulse velocity (fling back on damage)
		m_fHorizontalMovementSpeed = (GetPhysicsBody()->GetLinearVelocity().x > 0) ? (-3.0f):(3.0f);
		GetPhysicsBody()->ApplyLinearImpulse( b2Vec2( 0.0f, 700.0f ), b2Vec2( 0.5f, 0.5f ), true );

		return true;
	}
	return false;
}

//for use in catapult platforms
void CGCObjPlayer::liftoff( void )
{
	GetPhysicsBody()->ApplyLinearImpulse( b2Vec2( 0.0f, 1600.0f ), b2Vec2( 0.5f, 0.5f ), true );

	m_bIsAirborne = true;
}

//helper function for parallax
b2Vec2 CGCObjPlayer::getPlayerVelocity( void )
{
	return GetPhysicsBody()->GetLinearVelocity();
}

void CGCObjPlayer::ActivateShield( void )
{
	m_bIsShieldActive = true;
	m_fShieldRemainingTime += 5.0f;
}

void CGCObjPlayer::Jump( void )
{
	if ( !m_bIsAirborne )
	{
		// Make sure that if a jump has been started, it is stopped before calling again 
		// Not doing this breaks the program - A.S-H
		StopAllActions();
		RunAction	( m_pAJump );
		
		//Use impulse to control jump. This way, the jump force is not counteracted by gravity.
		//30 decided by trial and error
		GetPhysicsBody()->ApplyLinearImpulse( b2Vec2( 0.0f, m_fJumpHeight ), b2Vec2( 0.4f, 0.4f ), true );
		m_bWasFalling = false;
		m_bIsAirborne = true;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//We use interact by calling an Interact function on the player and passing a pointer to an Object that implements interactable.
//We get the pointer from the collision data 
//(on contact begin, set pointer member variable on GameLayerPlatformer to colliding object, on Contact End, set back to null)
//Then we pass the pointer variable here.
//The easiest way to move an Object with the player (carry it) it to make it a child of the player.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
void CGCObjPlayer::Interact( Interactable* PointerToInteractableObject )
{
	if ( PointerToInteractableObject )
	{
		PointerToInteractableObject->VInteract();
	}
}
*/

//////////////////////////////////////////////////////////////////////////
// Apply additional velocity when in contact
// 
// Cal ONLY on moving platforms and travellators
void CGCObjPlayer::SetExternalSpeed( b2Vec2 v2Speed )
{
	m_v2ExternalSpeed = v2Speed;
}

float CGCObjPlayer::GetPositionY()
{
	return GetPhysicsBody()->GetPosition().y;
}

float CGCObjPlayer::GetPositionX()
{
	return GetPhysicsBody()->GetPosition().x;
}

float CGCObjPlayer::GetVerticalVelocity()
{
	return getPlayerVelocity().y;
}
