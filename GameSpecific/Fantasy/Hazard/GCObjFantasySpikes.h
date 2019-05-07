#ifndef _GCOBJFANTASYSPIKES_H_
#define _GCOBJFANTASYSPIKES_H_

#ifndef _GCOBJSPIKES_H_
	#include "GamerCamp/GameSpecific/Base/Hazard/GCObjSpikes.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif


class CGCObjFantasySpikes
	: public CGCObjSpikes
{
public:
	CGCObjFantasySpikes( void )
		: CGCObjSpikes() 
	{
	}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasySpikes );

	virtual void VOnResourceAcquire			( void ) override;

	~CGCObjFantasySpikes()
	{};
};

#endif
