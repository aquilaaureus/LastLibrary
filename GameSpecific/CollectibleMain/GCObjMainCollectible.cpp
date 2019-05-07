////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GCOBJMAINCOLLECTIBLE_H_
	#include "GCObjMainCollectible.h"
#endif

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif

#ifndef _GCCOCOSHELPERS_H_
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#endif

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjMainCollectible );


//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjMainCollectible::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed

	const char* pszPlist_Page = "TexturePacker/Sprites/MainCollectible/coll_basic.plist";
	const char* pszAnim_P_Shine = "shine";
	
	ValueMap dicPList = GCCocosHelpers::CreateDictionaryFromPlist( pszPlist_Page );
	m_pAShine = GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_P_Shine ) ); //repeat forever until stopped

	RunAction( m_pAShine );
}

