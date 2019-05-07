#ifndef _GCOBJFANTASYSPIKES_H_
	#include "GamerCamp/GameSpecific/Fantasy/Hazard/GCObjFantasySpikesSmall.h"
#endif

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif


USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasySpikesS );

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasySpikesS::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed
}


