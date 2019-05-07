#ifndef _GCOBJFANTASYSPIKES4_H_
	#include "GamerCamp/GameSpecific/Fantasy/Hazard/GCObjFantasySpikes4x3.h"
#endif

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif


USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasySpikes4 );

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasySpikes4::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed
}


