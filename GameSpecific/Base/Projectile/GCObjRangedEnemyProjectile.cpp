////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory.h>

#include "GamerCamp/GCObject/GCObjectManager.h"
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#include "GamerCamp/GCObject/GCObjectManager.h"
#include "GamerCamp/GCCocosInterface/IGCGameLayer.h"
#include "GamerCamp/GCCocosInterface/GB2ShapeCache-x.h"

#include "GCObjRangedEnemyProjectile.h"

USING_NS_CC;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CGCObject interface


//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjRangedEnemyProjectile::VOnReset( void )
{
	CGCObjSpritePhysics::VOnReset();
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjRangedEnemyProjectile::VOnUpdate( f32 fTimeStep )
{
	if (GetPhysicsBody()->GetGravityScale() != 0)
	{
		GetPhysicsBody()->SetGravityScale(0.0f);
	}

	// changes to desired velocity
	b2Vec2 v2DesiredVelocityDelta = ( m_v2VelocityDesired - GetPhysicsBody()->GetLinearVelocity() );

	// 1) f = m * a -> a = f/m
	// 2) v = a * t -> a = v/t
	// so f/m = v/t -> f = (v/t) * m
	b2Vec2 v2RequiredForce = GetPhysicsBody()->GetMass() * ( ( 1.0f / fTimeStep ) * v2DesiredVelocityDelta );
	GetPhysicsBody()->ApplyForceToCenter( v2RequiredForce, true );

	// handle lifetime
	m_fRemainingLifetime -= fTimeStep;
	if (m_fRemainingLifetime < 2.5f)
	{
		if (GetPhysicsBody()->GetLinearVelocity().x == 0.0f)
		{
			CGCObjectManager::ObjectKill( this );
		}
	}
	if( m_fRemainingLifetime < 0.0f )
	{
		CGCObjectManager::ObjectKill( this );
	}
}
