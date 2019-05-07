////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <string.h>

#include "GamerCamp/GameSpecific/Base/PlatformPost/GCObjGroupPlatformPost.h"

#include "GamerCamp/GameSpecific/Base/PlatformPost/GCObjPlatformPost.h"

#include "GamerCamp/GCObject/GCObjectManager.h"
#include "GamerCamp/GCCocosInterface/IGCGameLayer.h"
#include "GamerCamp/Core/GCTypes.h"
#include "GamerCamp/GCObject/GCObject.h"
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"


//////////////////////////////////////////////////////////////////////////
// using
using namespace cocos2d;


//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
CGCObjGroupPlatformPost::CGCObjGroupPlatformPost()
{
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
// virtual
CGCObjGroupPlatformPost::~CGCObjGroupPlatformPost()
{
}

//////////////////////////////////////////////////////////////////////////
// only handle platforms
//////////////////////////////////////////////////////////////////////////
//virtual 
bool CGCObjGroupPlatformPost::VHandlesThisTypeId( GCTypeID idQueryType )
{
	return( GetGCTypeIDOf( CGCObjPlatformPost ) == idQueryType );
}

//////////////////////////////////////////////////////////////////////////
// must return the typeid of the CGCObjectGroup derived class
//////////////////////////////////////////////////////////////////////////
//virtual 
GCTypeID CGCObjGroupPlatformPost::VGetTypeId( void )
{
	return GetGCTypeIDOf( CGCObjGroupPlatformPost );
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjGroupPlatformPost::VOnGroupResourceRelease( void )
{
	// n.b. this must happen first, as will fail if objects destroyed before 
	CGCObjectGroup::VOnGroupResourceRelease(); 
	DestroyPlatformPosts();
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
void CGCObjGroupPlatformPost::DestroyPlatformPosts( void )
{
	// this iterates the array of registered CGCObjects 
	// calling the supplied functor then deleting them
	auto cMyLambda = [&] ( CGCObject* pObject )
	{
		GCASSERT ( GetGCTypeIDOf ( CGCObjPlatformPost ) == pObject->GetGCTypeID ( ) , "wrong type!" );
		CGCObjSprite* pProjectileAsSprite = static_cast< CGCObjSprite* >( pObject );
		pProjectileAsSprite->DestroySprite ( );
	};

	DestroyObjectsReverseOrder ( cMyLambda );
}

