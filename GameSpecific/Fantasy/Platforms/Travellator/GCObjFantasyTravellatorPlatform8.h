////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Sets up Travellator Platforms and their logic
// Edirection applies Left, Right or no direction to Travellator movement
// VOnResourceAcquire obtains appropriate resources to make Travellator functional
// VOnUpdate updates the Travellator every frame
// GetTravellatorDirection determines the direction the Travellator moves the player
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJFANTASYTRAVELLATORPLATFORMS8_H_
#define _GCOBJFANTASYTRAVELLATORPLATFORMS8_H_

#ifndef _GCOBJTRAVELLATORPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Base/Platforms/Travellator/GCObjTravellatorPlatform.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

class CGCObjFantasyTravellatorPlatform8
: public CGCObjTravellatorPlatform
{
public:

	////////////////////////////
	// Constructor Definitions
	////////////////////////////
	CGCObjFantasyTravellatorPlatform8( )
	: CGCObjTravellatorPlatform( )
	{
	}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasyTravellatorPlatform8 );

	virtual void	VOnResourceAcquire	( void ) override;
	
	virtual ~CGCObjFantasyTravellatorPlatform8()
	{};

};


#endif
