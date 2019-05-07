////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class CGCObjPlayer sets up the player for use in game levels.
// CGCObjPlayer is a child of CGCObjSpritePhysics, inheriting virtual functions from it
// Private variables in this class manage physics handling variables & currently defunct bool values
// These bool variables were used to implement "Abilities" to the player 
// 
// N.B. "Ability" variables have been kept in code as they may be implemented later in development
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJPLAYER_H_
#define _GCOBJPLAYER_H_

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

#include "GamerCamp/GameSpecific/Base/Platforms/Travellator/GCObjTravellatorPlatform.h"

//////////////////////////////////////////////////////////////////////////
// forward declare
class CGCObjGroupRangedEnemyProjectile;

//////////////////////////////////////////////////////////////////////////
// This is a sample class derived from CGCObject.
// 
// It could be the basis of your player object, it's up to you really.
//
// The player will be the only gameplay object in the default object group
//
//////////////////////////////////////////////////////////////////////////
class CGCObjPlayer 
: public CGCObjSpritePhysics
{
private:

	CGCObjTravellatorPlatform::EDirection m_ETDdir;

	//bool for not double jumping
	bool m_bIsAirborne;
	bool m_bIsInvincible	= false;
	bool m_bIsShieldActive	= false;
	bool m_bWasFalling;
	bool m_bWasMoving;
	float m_fShieldRemainingTime;
	float m_fLastHitTime;

	//Speed Limit Variables
	const float m_fHorizontalMovementLimit = 20.0f;
	const float m_fVerticalSpeedLimit = 30.0f;
	const float m_fHorizontalMovementIncrement = 1.5f;

	//Speed variable
	b2Vec2 m_v2ExternalSpeed = b2Vec2_zero;
	float m_fHorizontalMovementSpeed;


	// float for Super Jump Mutator
	float m_fJumpHeight;

	// used to fire projectiles
	//CGCObjGroupRangedEnemyProjectile* m_pProjectileManager; 

	bool m_bIsPlayerMoving = false;
	int	m_iPlayerMovingDirection;

public:
	CGCObjPlayer();

	//Animation action pointers for storing the action.
	cocos2d::Action* m_pAWalk;
	cocos2d::Action* m_pAJump;
	cocos2d::Action* m_pALand;
	cocos2d::Action* m_pADamage;
	cocos2d::Action* m_pAIdle_1;
	cocos2d::Action* m_pAIdle_2;

	f32 fIsInputInactive;
	f32 fVelocity;
	f32 fDragForce;

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjPlayer );

	//////////////////////////////////////////////////////////////////////////
	// we need a virtual destructor since delete will be called on pointers of 
	// this class to delete derived types.
	virtual ~CGCObjPlayer()
	{}

	void Grounded( void );

	void Airborne( void );

	void CheckGrounded( void );
	
	//////////////////////////////////////////////////////////////////////////
	// Virtual Overrides from the game object interface

	// This will be called exactly once for each CGCObject derived class instance 
	// registered with CGCObjectManager as soon as the TGB level file has stopped 
	// loading- it is an "explicit constructor".
	virtual void VOnResourceAcquire( void );

	// OnReset is called for each CGCObject derived class when CGCObjectManager is 
	// reset
	virtual void VOnReset( void ); 

	virtual void VOnResurrected( void ) override;

	// OnUpdate is called for each CGCObject derived class when CGCObjectManager is 
	// updated in t2dSCeneGraph onProcessTick()
	virtual void VOnUpdate( f32 fTimeStep ); 

    // called immediately before the managing object group releases its own assets
    virtual void VOnResourceRelease( void );

	// Virtual Overrides from the game object interface
	//////////////////////////////////////////////////////////////////////////

	// updates the movement of the CCSprite
	void UpdateMovement( f32 fTimeStep );

	void	SetIsPlayerMoving			( bool isMoving );
	bool	GetIsPlayerMoving			( void );

	void	SetPlayerMovingDirection	( int movingDirection );
	int		GetPlayerMovingDirection	( void );

	//switch player to background
	//void	SetToBackground				( bool bsetValue );

	//return if damage was done to the player
	bool	gotHit						( void );

	//use on catapult platforms
	void	liftoff						( void );

	b2Vec2	getPlayerVelocity			( void );

	//Use every time the player collects a shield power up
	void	ActivateShield				( void );

	//Call to jump (for use in UI touch controls)
	void	Jump						( void );

	//call in HandleCollisions while on Moving platforms
	void SetExternalSpeed( b2Vec2 v2Speed );

	float	GetPositionY	();
	float	GetPositionX	();

	float GetVerticalVelocity();
};
#endif // #ifndef _GCOBJPLAYER_H_