#ifndef _GCOBJGOAL_H_
#define _GCOBJGOAL_H_

#ifndef __COCOS2D_H__
#include "cocos2d.h"
#endif // !__COCOS2D_H__

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

class CGCGoal
	: public CGCObjSpritePhysics
{
private:
	bool m_bActivate;
	cocos2d::FiniteTimeAction* m_pAClosed;
	cocos2d::FiniteTimeAction* m_pAOpening;
	cocos2d::FiniteTimeAction* m_pAOpen;
public:
	CGCGoal(void)
		: CGCObjSpritePhysics(GetGCTypeIDOf( CGCGoal ) )
	{}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCGoal );

	//////////////////////////////////////////////////////////////////////////
	// overridden virtuals from the game object interface

	// This will be called exactly once for each CGCObject derived class instance 
	// registered with CGCObjectManager as soon as the TGB level file has stopped 
	// loading- it is an "explicit constructor".
	virtual void VOnResourceAcquire(void);

	// OnReset is called for each CGCObject derived class when CGCObjectManager is 
	// reset
	virtual void VOnReset(void);

	// OnUpdate is called for each CGCObject derived class when CGCObjectManager is 
	// updated in t2dSCeneGraph onProcessTick()
	virtual void VOnUpdate(f32 fTimeStep);

	// called immediately before the managing object group releases its own assets
	virtual void VOnResourceRelease(void);

	virtual void VOnResurrected( void ) override;

	void	Activate	(bool bactivateFlag);

};
#endif // !
