#ifndef _GCOBJFANTASYCOLLAPSINGPLATFORMS_H_
#define _GCOBJFANTASYCOLLAPSINGPLATFORMS_H_

#ifndef _GCOBJCOLLAPSINGPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Base/Platforms/Collapsible/GCObjCollapsingPlatform.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif


class CGCObjFantasyCollidingPlatform
	: public CGCObjCollapsingPlatform
{
private:
	bool m_bIsPlatformActive = true;

	//measure the time of touch 
	//and kill the platform if touched 
	//and time is more than 3.0f
	f32 m_ulLastPlayerTouchTime;

public:
	CGCObjFantasyCollidingPlatform(	void )
		: CGCObjCollapsingPlatform()
	{}

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasyCollidingPlatform );


	virtual void	VOnResourceAcquire		(	void	) override;
	
	virtual ~CGCObjFantasyCollidingPlatform()
	{};
};

#endif // _GCOBJCOLLIDINGPLATFORMS_H_
