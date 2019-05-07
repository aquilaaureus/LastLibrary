////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJRANGEDENEMYPROJECTILE_H_
#define _GCOBJRANGEDENEMYPROJECTILE_H_

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif


//////////////////////////////////////////////////////////////////////////
// This is a sample class derived from CGCObject.
// 
// It demonstrates how you might do projectiles, it relies on 
// CGCObjGroupProjectilePlayer to manage the lifetimes of these.
//
//////////////////////////////////////////////////////////////////////////
class CGCObjRangedEnemyProjectile
: public CGCObjSpritePhysics
{
protected:
	b2Vec2	m_v2VelocityDesired;	// velocity of the projectile
	f32		m_fRemainingLifetime;	// remaining lifetime

public:
	CGCObjRangedEnemyProjectile()
		: CGCObjSpritePhysics( GetGCTypeIDOf( CGCObjRangedEnemyProjectile ) ) 
	{};

	//////////////////////////////////////////////////////////////////////////
	// we need a virtual destructor since delete will be called on pointers of 
	// this class to delete derived types.
	virtual ~CGCObjRangedEnemyProjectile()
	{}

	// accessors for data members
	inline void SetVelocity( b2Vec2 v2Velocity );
	inline void SetLifeTime( f32 fLifeTime );

	//////////////////////////////////////////////////////////////////////////
	// overridden virtuals from the game object interface

		virtual void VOnResourceAcquire	( void ) override = 0;

		virtual void VOnReset(void) override;

		virtual void VOnUpdate			( f32 fTimeStep ) override;

	// overridden virtuals from the game object interface
	//////////////////////////////////////////////////////////////////////////
};



//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
inline void CGCObjRangedEnemyProjectile::SetVelocity( b2Vec2 v2Velocity )
{
	m_v2VelocityDesired = v2Velocity;
}



//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
inline void CGCObjRangedEnemyProjectile::SetLifeTime( f32 fLifeTime )
{
	m_fRemainingLifetime = fLifeTime;
}


#endif // #ifndef _GCOBJPROJECTILEFANTASYRANGED_H_