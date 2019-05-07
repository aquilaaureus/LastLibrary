////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GCOBJFANTASYTRAVELLATORPLATFORMS8_H_
	#include "GamerCamp/GameSpecific/Fantasy/Platforms/Travellator/GCObjFantasyTravellatorPlatform8.h"
#endif

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif


USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasyTravellatorPlatform8 );


//////////////////////////////////////////////////////////////////////////////////////////
// Acquire the resources needed to display the correct sprite
// And appropriate physics boxes 
// Then sets the object to be a child of the GameLayer it is currently being called from
//////////////////////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasyTravellatorPlatform8::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed
}

