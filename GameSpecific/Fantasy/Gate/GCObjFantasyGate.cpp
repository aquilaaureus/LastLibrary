////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory.h>

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif

#ifndef _GCOBJFANTASYGATE_H_
	#include "GamerCamp/GameSpecific/Fantasy/Gate/GCObjFantasyGate.h"
#endif

#ifndef _GCCOCOSHELPERS_H_
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#endif

USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasyGate );


//////////////////////////////////////////////////////////////////////////
// GetGCTypeIDOf uses the template in GCTypeID to generate a unique ID for 
// this type - need this to construct our base type
CGCObjFantasyGate::CGCObjFantasyGate()
	: CGCObjGate()
{
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CGCObject interface

//////////////////////////////////////////////////////////////////////////
//  This is the red Gate
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasyGate::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire();

	const char* pszPlist_Gate = "TexturePacker/Sprites/Gates/anim_gate_red.plist";
	const char* pszAnim_G_Open = "redopened";
	const char* pszAnim_G_Opening = "redopen";
	const char* pszAnim_G_Closed = "redclosed";

	ValueMap dicPList = GCCocosHelpers::CreateDictionaryFromPlist( pszPlist_Gate );
	SetClosedAnimation( GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_G_Closed ) ) ); //repeat forever until stopped
	SetOpeningAnimation( GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_G_Opening ) ) ); //run once
	SetOpenAnimation( GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_G_Open ) ) ); //repeat forever until stopped


}


//All actions handled by base class

