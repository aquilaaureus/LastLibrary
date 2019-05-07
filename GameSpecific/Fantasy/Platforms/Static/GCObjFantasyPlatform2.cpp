////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GCOBJFANTASYPLATFORMS2_H_
	#include "GCObjFantasyPlatform2.h"
#endif

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasyPlatform2 );


//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasyPlatform2::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed
}
