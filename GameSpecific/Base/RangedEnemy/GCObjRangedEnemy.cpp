////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "GamerCamp/GameSpecific/Base/RangedEnemy/GCObjRangedEnemy.h"

#include <memory.h>

#include "GamerCamp/GCObject/GCObjectManager.h"
#include "GamerCamp/GameSpecific/Base/Projectile/GCObjGroupRangedEnemyProjectile.h"


USING_NS_CC;

const float SPEED = 200.0f;

//////////////////////////////////////////////////////////////////////////
// GetGCTypeIDOf uses the template in GCTypeID to generate a unique ID for 
// this type - need this to construct our base type
CGCObjRangedEnemy::CGCObjRangedEnemy()
	: CGCObjSpritePhysics(GetGCTypeIDOf( CGCObjRangedEnemy ))
{
	m_fTimeToFire = 0.0f;
	m_pProjectileManager = static_cast<CGCObjGroupRangedEnemyProjectile*>
		(CGCObjectManager::FindObjectGroupByID(GetGCTypeIDOf( CGCObjGroupRangedEnemyProjectile )));
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CGCObject interface


//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjRangedEnemy::VOnResurrected( void )
{
	CGCObjSpritePhysics::VOnResurrected();

	SetFlippedX ( true );
	GetPhysicsBody()->SetGravityScale(10.0f);
	GetPhysicsBody()->SetLinearDamping(0.0f);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// this class' public interface
void CGCObjRangedEnemy::VOnUpdate(float ts)
{
	m_fTimeToFire += ts;

	//If he is on the right side of the screen, we want him flipped
	//We want it checked continuously, in case he moves (later in production)
	//Get this from global data if it keeps causing problems
	//SetFlippedX( GetResetPosition().x < (Director::getInstance()->getVisibleSize().width / 2) );
	
	//So that the ranged enemy does not randomly move around
	GetPhysicsBody()->SetLinearVelocity( b2Vec2( 0.0f, GetPhysicsBody()->GetLinearVelocity().y ) );
}

void CGCObjRangedEnemy::VFireProjectile()
{
	if (m_fTimeToFire >= m_ffireinterval)
	{
		m_fTimeToFire = 0.0f; //reset firing timer
		b2Vec2 speed( 25.0f, 0.0f );
		// supply initial position, velocity, lifetime, based on enemy being flipped or not
		if (IsFlippedX())
		{
			m_pProjectileManager->VSpawnProjectile( GetSpritePosition() - b2Vec2( -7.0f, -2.0f ), speed, 3.0f );
		}
		else
		{
			m_pProjectileManager->VSpawnProjectile( GetSpritePosition() - b2Vec2( 7.0f, -2.0f ), -speed, 3.0f );
		}
	}

}

void CGCObjRangedEnemy::FlipIfNeeded( float fPlayerPosX )
{
	if (GetPhysicsBody())
	{
		SetFlippedX( GetPhysicsBody()->GetPosition().x < fPlayerPosX );
	}
}
