////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJFLOOR_H_
#define _GCOBJFLOOR_H_

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

#ifndef _GCOBJPLATFORMS_H_
#include "GamerCamp/GameSpecific/Base/Platforms/Static/GCObjPlatform.h"
#endif
//////////////////////////////////////////////////////
//
//This is the basic platform class
//
// child classes can override the graphics and physics selection
//
// child classes override virtual funtions to determine/reveal their own type

//////////////////////////////////////////////////////

class CGCObjFloor
: public CGCObjPlatform
{
private:

public:

	////////////////////////////
	// Constructor Definitions
	////////////////////////////
	CGCObjFloor( void )
		: CGCObjPlatform()
	{}


	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFloor );



	virtual void VOnResourceAcquire( void ) override;
};


#endif
