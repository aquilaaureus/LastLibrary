////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

//#ifdef _GCOBJECTGROUPWALL_H_
#include "GCObjGroupWall.h"
//#endif // _GCOBJECTGROUPWALL_H_

#ifndef _GCOBJWALL_H_
#include "GCObjWall.h"
#endif

#ifdef _GCOBJECTMANAGER_H_
#include "GamerCamp/GCObject/GCObjectManager.h"
#endif // _GCOBJECTMANAGER_H_

#ifndef _IGCGAMELAYER_H_
#include "GamerCamp/GCCocosInterface/IGCGameLayer.h"
#endif // !_IGCGAMELAYER_H_

#ifdef _GCTYPES_H_
#include "GamerCamp/Core/GCTypes.h"
#endif // _GCTYPES_H_

#ifndef _GCOBJECT_H_
#include "GamerCamp/GCObject/GCObject.h"
#endif // !_GCOBJECT_H_

#ifndef _GCCOCOSHELPERS_H_
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#endif // !_GCCOCOSHELPERS_H_


//////////////////////////////////////////////////////////////////////////
// using
using namespace cocos2d;


//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
CGCObjGroupWall::CGCObjGroupWall()
	:CGCObjectGroup()
{
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
// virtual
CGCObjGroupWall::~CGCObjGroupWall()
{
}

//////////////////////////////////////////////////////////////////////////
// only handle platforms
//////////////////////////////////////////////////////////////////////////
//virtual 
bool CGCObjGroupWall::VHandlesThisTypeId( GCTypeID idQueryType )
{
	return( GetGCTypeIDOf( CGCObjWall ) == idQueryType );
}

//////////////////////////////////////////////////////////////////////////
// must return the typeid of the CGCObjectGroup derived class
//////////////////////////////////////////////////////////////////////////
//virtual 
GCTypeID CGCObjGroupWall::VGetTypeId( void )
{
	return GetGCTypeIDOf( CGCObjGroupWall );
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjGroupWall::VOnGroupResourceRelease( void )
{
	// n.b. this must happen first, as will fail if objects destroyed before 
	CGCObjectGroup::VOnGroupResourceRelease(); 
	DestroyWalls();
}

void CGCObjGroupWall::VOnGroupUpdate( f32 a )
{

	CGCObjectGroup::VOnGroupUpdate(a);

}


//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
void CGCObjGroupWall::DestroyWalls( void )
{
	// this iterates the array of registered CGCObjects 
	// calling the supplied functor then deleting them
	auto cMyLambda = [&] ( CGCObject* pObject )
	{
		GCASSERT ( GetGCTypeIDOf ( CGCObjWall ) == pObject->GetGCTypeID ( ) , "wrong type!" );
		CGCObjSprite* pProjectileAsSprite = static_cast< CGCObjSprite* >( pObject );
		pProjectileAsSprite->DestroySprite ( );
	};

	DestroyObjectsReverseOrder ( cMyLambda );
}

