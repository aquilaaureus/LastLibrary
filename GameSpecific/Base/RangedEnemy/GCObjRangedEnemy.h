////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJRANGEDENEMY_H_
#define _GCOBJRANGEDENEMY_H_

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif



class CGCObjGroupRangedEnemyProjectile;

//////////////////////////////////////////////////////////////////////////
// This class is the basis class for ranged enemies. It was decided to
// separate patrolling and ranged enemies because of the projectile object behaviour
// and the different formations (starting points) for different kinds of enemies,
// even though they do share some funtionality (like being killed).
//
// It would be too much hassle to try to coordinate positions with enemy types
// when setting up formation
//////////////////////////////////////////////////////////////////////////
class CGCObjRangedEnemy
: public CGCObjSpritePhysics
{
private:
	float m_ffireinterval = 2.2f;
	float m_fTimeToFire;

	CGCObjGroupRangedEnemyProjectile * m_pProjectileManager;
public:
	CGCObjRangedEnemy();

	//////////////////////////////////////////////////////////////////////////
	// we need a virtual destructor since delete will be called on pointers of 
	// this class to delete derived types.
	virtual ~CGCObjRangedEnemy()
	{}

	//////////////////////////////////////////////////////////////////////////
	// overridden virtual functions from the game object interface
	virtual void VOnResourceAcquire	( void ) override = 0;

	virtual void VOnResurrected		( void ) override;

	void VOnUpdate(float ts);

	virtual void VFireProjectile();

	void FlipIfNeeded( float fPlayerPosX );

};
#endif // #ifndef _GCOBJFANTASYRANGED_H_