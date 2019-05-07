#ifndef _GCOBJFANTASYSPIKES4_H_
#define _GCOBJFANTASYSPIKES4_H_

#ifndef _GCOBJSPIKES_H_
	#include "GamerCamp/GameSpecific/Base/Hazard/GCObjSpikes.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif


class CGCObjFantasySpikes4
	: public CGCObjSpikes
{
public:
	CGCObjFantasySpikes4( void )
		: CGCObjSpikes() 
	{
	}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasySpikes4 );

	virtual void VOnResourceAcquire			( void ) override;

	~CGCObjFantasySpikes4()
	{};
};

#endif
