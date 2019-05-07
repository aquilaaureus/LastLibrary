////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJMAINCOLLECTIBLE_H_
#define _GCOBJMAINCOLLECTIBLE_H_

#ifndef __COCOS2D_H__
#include "cocos2d.h"
#endif // !__COCOS2D_H__

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

class CGCObjMainCollectible
: public CGCObjSpritePhysics
{
private:
	cocos2d::FiniteTimeAction* m_pAShine;

public:

	CGCObjMainCollectible()
		: CGCObjSpritePhysics(GetGCTypeIDOf(CGCObjMainCollectible))
	{
	}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjMainCollectible );

	virtual void VOnResourceAcquire( void ) override;

};


#endif
