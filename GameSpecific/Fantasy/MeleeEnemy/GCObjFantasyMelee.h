////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJFANTASYMEELE_H_
#define _GCOBJFANTASYMEELE_H_


#ifndef __COCOS2D_H__
#include "cocos2d.h"
#endif // !__COCOS2D_H__


#ifndef _GCOBJPATROLLINGENEMY_H_
	#include "GamerCamp/GameSpecific/Base/MeleeEnemy/GCObjPatrollingEnemy.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

#ifndef _GCCOCOSHELPERS_H_
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#endif // !_GCCOCOSHELPERS_H_


//////////////////////////////////////////////////////////////////////////
// This is a fantasy meele enemy override
//
// all actions are handled in base class. This exists only for selecting graphics
//////////////////////////////////////////////////////////////////////////
class CGCObjFantasyMeele 
: public CGCObjPatrollingEnemy
{
private:
	cocos2d::ActionInterval* m_pAWalk;
	cocos2d::ActionInterval* m_pADeathAnim;
	bool m_bIsKilled;
public:
	CGCObjFantasyMeele();

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasyMeele );

	//////////////////////////////////////////////////////////////////////////
	// we need a virtual destructor since delete will be called on pointers of 
	// this class to delete derived types.
	virtual ~CGCObjFantasyMeele()
	{}

	//////////////////////////////////////////////////////////////////////////
	// overridden virtual functions from the game object interface
	virtual void VOnResourceAcquire	( void ) override;
	virtual void VOnReset( void ) override;
	virtual void VOnResourceRelease	( void ) override;
	//actions handled by base class
	void VOnUpdate(float ts);

	virtual void KillAnimation( void );
};
#endif // #ifndef _GCOBJINVADER_H_