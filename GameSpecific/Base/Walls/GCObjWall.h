////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJWALL_H_
#define _GCOBJWALL_H_

#include "Gamercamp/GCCocosInterface/GCObjSpritePhysics.h"


//////////////////////////////////////////////////////
//
//This is the basic platform class
//
// child classes can override the graphics and physics selection
//
// child classes override virtual funtions to determine/reveal their own type

//////////////////////////////////////////////////////

class CGCObjWall
: public CGCObjSpritePhysics
{
private:

public:

	////////////////////////////
	// Constructor Definitions
	////////////////////////////
	CGCObjWall( void )
		: CGCObjSpritePhysics( GetGCTypeIDOf( CGCObjWall ) )
	{}

	virtual void VOnResourceAcquire( void ) override = 0;
};


#endif
