////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GCOBJFLOOR_H_
	#include "GCObjFloor.h"
#endif

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFloor );


void CGCObjFloor::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire();
}
