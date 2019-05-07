////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _GCOBJFANTASYTRAVELLATORPLATFORMS_H_
	#include "GamerCamp/GameSpecific/Fantasy/Platforms/Travellator/GCObjFantasyTravellatorPlatform.h"
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
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasyTravellatorPlatform );


//////////////////////////////////////////////////////////////////////////////////////////
// Acquire the resources needed to display the correct sprite
// And appropriate physics boxes 
// Then sets the object to be a child of the GameLayer it is currently being called from
//////////////////////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasyTravellatorPlatform::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed

	const char* pszPlist_MeeleEnemy = "TexturePacker/Sprites/Fantasy/Platforms/Travellator/plat_travel.plist";
	const char* pszAnim_TP_travel = "Travel";

	ValueMap dicPList = GCCocosHelpers::CreateDictionaryFromPlist( pszPlist_MeeleEnemy );
	m_pATravel = GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_TP_travel ) ); //repeat forever until stopped
	
	m_pATravel->retain();

}

void CGCObjFantasyTravellatorPlatform::VOnReset( void )
{
	CGCObjTravellatorPlatform::VOnReset();
	StopAllActions();
	RunAction( (cocos2d::Action*)m_pATravel );
}

void CGCObjFantasyTravellatorPlatform::VOnResourceRelease( void )
{
	m_pATravel->release();
}



