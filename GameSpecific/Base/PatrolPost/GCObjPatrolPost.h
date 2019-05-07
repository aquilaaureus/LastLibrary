////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef _GCOBJPATROLPOST_H_
#define _GCOBJPATROLPOST_H_

#ifndef _GCFACTORY_OBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCFactory_ObjSpritePhysics.h"
#endif

#ifndef _GCOBJSPRITEPHYSICS_H_
	#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

//////////////////////////////////////////////////////////////////////////
// This is a sample class derived from CGCObject.
// 
// It demonstrates how you might do projectiles, it relies on 
// CGCObjGroupProjectilePlayer to manage the lifetimes of these.
//
//////////////////////////////////////////////////////////////////////////
class CGCObjPatrolPost
: public CGCObjSpritePhysics
{

public:
	CGCObjPatrolPost()
		: CGCObjSpritePhysics( GetGCTypeIDOf( CGCObjPatrolPost ) )
	{
	};

	// declare the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
	GCFACTORY_DECLARE_CREATABLECLASS( CGCObjPatrolPost );

	//////////////////////////////////////////////////////////////////////////
	// we need a virtual destructor since delete will be called on pointers of 
	// this class to delete derived types.
	virtual ~CGCObjPatrolPost()
	{}

	//////////////////////////////////////////////////////////////////////////
	// overridden virtuals from the game object interface

		virtual void VOnResourceAcquire	( void ) override;

	// overridden virtuals from the game object interface
	//////////////////////////////////////////////////////////////////////////
};

#endif
