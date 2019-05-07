////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJFANTASYGATE_H_
#define _GCOBJFANTASYGATE_H_

#ifndef _GCOBJGATE_H_
	#include "GamerCamp/GameSpecific/Base/Gate/GCObjGate.h"
#endif

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif


//////////////////////////////////////////////////////////////////////////
// This is a fantasy meele enemy override
//
// all actions are handled in base class. This exists only for selecting graphics
//////////////////////////////////////////////////////////////////////////
class CGCObjFantasyGate 
: public CGCObjGate
{
private:

public:
	CGCObjFantasyGate();

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjFantasyGate );

	//////////////////////////////////////////////////////////////////////////
	// we need a virtual destructor since delete will be called on pointers of 
	// this class to delete derived types.
	virtual ~CGCObjFantasyGate()
	{}

	//////////////////////////////////////////////////////////////////////////
	// overridden virtual functions from the game object interface
	virtual void VOnResourceAcquire	( void ) override;

	//actions handled by base class
	//void VOnUpdate(float ts);

};
#endif // #ifndef _GCOBJINVADER_H_