////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string.h>

#include "GamerCamp/GameSpecific/Base/RangedEnemy/GCObjGroupRangedEnemy.h"

#include "GamerCamp/GCObject/GCObjectManager.h"
#include "GamerCamp/GCCocosInterface/IGCGameLayer.h"
#include "GamerCamp/Core/GCTypes.h"
#include "GamerCamp/GCObject/GCObject.h"
#include "GamerCamp/GameSpecific/Base/RangedEnemy/GCObjRangedEnemy.h"
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"


//////////////////////////////////////////////////////////////////////////
// using
using namespace cocos2d;



//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
CGCObjGroupRangedEnemy::CGCObjGroupRangedEnemy()
{
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
// virtual
CGCObjGroupRangedEnemy::~CGCObjGroupRangedEnemy()
{}

//////////////////////////////////////////////////////////////////////////
// only handle invaders
//////////////////////////////////////////////////////////////////////////
//virtual 
bool CGCObjGroupRangedEnemy::VHandlesThisTypeId( GCTypeID idQueryType )
{
	return( GetGCTypeIDOf( CGCObjRangedEnemy ) == idQueryType );
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjGroupRangedEnemy::VOnGroupResourceRelease(void)
{
	// N.B. need to do this first as it clears internal lists
	CGCObjectGroup::VOnGroupResourceRelease();
	VDestroyInvaders();
}

//////////////////////////////////////////////////////////////////////////
// must return the typeid of the CGCObjectGroup derived class
//////////////////////////////////////////////////////////////////////////
//virtual 
GCTypeID CGCObjGroupRangedEnemy::VGetTypeId( void )
{
	return GetGCTypeIDOf( CGCObjGroupRangedEnemy );
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjGroupRangedEnemy::VOnGroupResourceAcquire( void )
{
	CGCObjectGroup::VOnGroupResourceAcquire();
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
void CGCObjGroupRangedEnemy::VDestroyInvaders( void )
{
	// this iterates the array of registered CGCObjects 
	// calling the supplied functor then deleting them
	auto cMyLambda = [&] ( CGCObject* pObject )
	{
		GCASSERT ( GetGCTypeIDOf ( CGCObjRangedEnemy ) == pObject->GetGCTypeID ( ) , "wrong type!" );
		CGCObjSprite* pProjectileAsSprite = static_cast< CGCObjSprite* >( pObject );
		pProjectileAsSprite->DestroySprite ( );
	};

	DestroyObjectsReverseOrder ( cMyLambda );
}

void CGCObjGroupRangedEnemy::FlipObjects( float fPlayerPositionX )
{
	SGCObjectGatherer sMyGatherer;
	ForEachObject( sMyGatherer );
	for (u32 uIndex = 0; uIndex < sMyGatherer.uCount; ++uIndex)
	{
		CGCObject* pcItemAsObject = sMyGatherer.apObjects[uIndex];
		CCAssert( (GetGCTypeIDOf( CGCObjRangedEnemy ) == pcItemAsObject->GetGCTypeID()),
			"CGCObject derived type mismatch!" );

		CGCObjRangedEnemy* pProjectileAsPlatfrom = static_cast<CGCObjRangedEnemy*>(pcItemAsObject);

		pProjectileAsPlatfrom->FlipIfNeeded( fPlayerPositionX );
	}
}
