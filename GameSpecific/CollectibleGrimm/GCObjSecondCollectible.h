////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJSECONDCOLLECTIBLE_H_
#define _GCOBJSECONDCOLLECTIBLE_H_

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

class CGCObjSecondCollectible
: public CGCObjSpritePhysics
{

public:

	const char* k_cPowerUpType;

	CGCObjSecondCollectible()
		: CGCObjSpritePhysics(GetGCTypeIDOf(CGCObjSecondCollectible))
	{
	}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjSecondCollectible );

	void SetUpPower( char* cPowerUpType );

	virtual void VOnResourceAcquire( void ) override;

};


#endif
