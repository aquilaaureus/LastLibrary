#ifndef _GCOBJFANTASYSPIKESS_H_
#define _GCOBJFANTASYSPIKESS_H_

#ifndef _GCOBJSPIKES_H_
	#include "GamerCamp/GameSpecific/Base/Hazard/GCObjSpikes.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif


class CGCObjFantasySpikesS
	: public CGCObjSpikes
{
public:
	CGCObjFantasySpikesS( void )
		: CGCObjSpikes() 
	{
	}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasySpikesS );

	virtual void VOnResourceAcquire			( void ) override;

	~CGCObjFantasySpikesS()
	{};
};

#endif
