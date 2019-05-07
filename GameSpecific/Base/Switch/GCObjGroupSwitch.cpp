#include <string.h>

#include "GamerCamp/GameSpecific/Base/Switch/GCObjGroupSwitch.h"
#include "GamerCamp/GameSpecific/Base/Switch/GCObjSwitch.h"

#include "GamerCamp/GameSpecific/Base/Gate/GCObjGate.h"

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
CGCObjGroupSwitch::CGCObjGroupSwitch()
{
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
CGCObjGroupSwitch::~CGCObjGroupSwitch()
{
}

//////////////////////////////////////////////////////////////////////////
// Only handle spikes
//////////////////////////////////////////////////////////////////////////
//virtual 
bool CGCObjGroupSwitch::VHandlesThisTypeId(GCTypeID idQueryType)
{
	return(GetGCTypeIDOf( CGCObjSwitch ) == idQueryType);
}

//////////////////////////////////////////////////////////////////////////
// must return the typeid of the CGCObjectGroup derived class
//////////////////////////////////////////////////////////////////////////
//virtual 
GCTypeID CGCObjGroupSwitch::VGetTypeId(void)
{
	return GetGCTypeIDOf( CGCObjGroupSwitch );
}

//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjGroupSwitch::VOnGroupResourceRelease(void)
{
	// n.b. this must happen first, as will fail if objects destroyed before 
	CGCObjectGroup::VOnGroupResourceRelease();
	DestroySpikes();
}

//Call this in Level AFTER creating all object (preferably on Initialize)
void CGCObjGroupSwitch::SetUp( CGCObjGroupGates * pcGatesGroup )
{

	SGCObjectGatherer sMyGatherer;
	ForEachObject( sMyGatherer );
	for (u32 uIndex = 0; uIndex < sMyGatherer.uCount; ++uIndex)
	{
		CGCObject* pcItemAsObject = sMyGatherer.apObjects[uIndex];
		CCAssert( (GetGCTypeIDOf( CGCObjSwitch ) == pcItemAsObject->GetGCTypeID()),
			"CGCObject derived type mismatch!" );

		CGCObjSwitch* pObjectAsSwitch = static_cast<CGCObjSwitch*>(pcItemAsObject);

		CGCObjGate* pRelatedGate = dynamic_cast<CGCObjGate*>(pcGatesGroup->OnFindObject( pObjectAsSwitch->GetName().c_str(), GetGCTypeIDOf( CGCObjGate ) ));
		
		pObjectAsSwitch->SetGate( pRelatedGate );
	}
}



//////////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////////
void CGCObjGroupSwitch::DestroySpikes(void)
{
	// this iterates the array of registered CGCObjects 
	// calling the supplied functor then deleting them
	auto cMyLambda = [&] ( CGCObject* pObject )
	{
		GCASSERT ( GetGCTypeIDOf ( CGCObjSwitch ) == pObject->GetGCTypeID ( ) , "wrong type!" );
		CGCObjSprite* pProjectileAsSprite = static_cast< CGCObjSprite* >( pObject );
		pProjectileAsSprite->DestroySprite ( );
	};

	DestroyObjectsReverseOrder ( cMyLambda );
}