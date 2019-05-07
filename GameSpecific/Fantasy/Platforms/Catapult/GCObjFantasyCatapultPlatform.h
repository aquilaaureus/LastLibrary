#ifndef _GCOBJFANTASYCATAPULTPLATFORMS_H_
#define _GCOBJFANTASYCATAPULTPLATFORMS_H_

#ifndef _GCOBJCATAPULTPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Base/Platforms/Catapult/GCObjCatapultPlatform.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif


class GCObjFantasyCatapultPlatform
	: public GCObjCatapultPlatform
{
public:
	GCObjFantasyCatapultPlatform(	void )
		: GCObjCatapultPlatform()
	{}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( GCObjFantasyCatapultPlatform );

	virtual void	VOnResourceAcquire		(	void	) override;

	virtual ~GCObjFantasyCatapultPlatform( void )
	{};

};

#endif // _GCOBJCOLLIDINGPLATFORMS_H_
