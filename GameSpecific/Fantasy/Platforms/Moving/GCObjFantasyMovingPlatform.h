////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJFANTASYMOVINGPLATFORM_H_
#define _GCOBJFANTASYMOVINGPLATFORM_H_

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

#ifndef _GCOBJMOVINGPLATFORM_H_
	#include "GamerCamp/GameSpecific/Base/Platforms/Moving/GCObjMovingPlatform.h"
#endif

class CGCObjFantasyMovingPlatform
: public CGCObjMovingPlatform
{
public:
	CGCObjFantasyMovingPlatform( ) :
		CGCObjMovingPlatform( )
	{};

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasyMovingPlatform );

	void SetUpSpeed( void );

	virtual void VOnResourceAcquire( void ) override;

	virtual ~CGCObjFantasyMovingPlatform()
	{};
};


#endif
