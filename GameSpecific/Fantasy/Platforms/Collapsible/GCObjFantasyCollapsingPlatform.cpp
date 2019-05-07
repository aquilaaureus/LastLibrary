#ifndef _GCOBJFANTASYCOLLAPSINGPLATFORMS_H_
	#include "GCObjFantasyCollapsingPlatform.h"
#endif

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif

#ifndef _GCCOCOSHELPERS_H_
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#endif // !_GCCOCOSHELPERS_H_

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasyCollidingPlatform );


//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasyCollidingPlatform::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed
	const char* pszPlist_Collapsible = "TexturePacker/Sprites/Fantasy/Platforms/Collapsible/plat_collap.plist";
	const char* pszPlist_C_Steady = "steady";
	const char* pszPlist_C_Collapse= "collap_1";

	ValueMap dicPList = GCCocosHelpers::CreateDictionaryFromPlist( pszPlist_Collapsible );
	m_pACollapse =  GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszPlist_C_Collapse ) );
	m_pACollapse->retain();
	m_pASteady =  GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszPlist_C_Steady ) );
	m_pASteady->retain();
}
