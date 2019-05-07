////////////////////////////////////////////////////////////////////////////////////////////////////////////
// (C) Gamer Camp 2012 
// This document should not be distributed or reproduced in part or in whole without obtaining written 
// permission from the copyright holders.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <memory.h>

#ifndef _GCOBJECTMANAGER_H_
	#include "GamerCamp/GCObject/GCObjectManager.h"
#endif

#ifndef _GCOBJFANTASYMEELE_H_
	#include "GamerCamp/GameSpecific/Fantasy/MeleeEnemy/GCObjFantasyMelee.h"
#endif


USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCObjFantasyMeele );


//////////////////////////////////////////////////////////////////////////
// GetGCTypeIDOf uses the template in GCTypeID to generate a unique ID for 
// this type - need this to construct our base type
CGCObjFantasyMeele::CGCObjFantasyMeele()
	: CGCObjPatrollingEnemy()
{
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// CGCObject interface

//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCObjFantasyMeele::VOnResourceAcquire( void )
{
	CGCObjSpritePhysics::VOnResourceAcquire();

	//add animation if needed
	const char* pszPlist_MeeleEnemy = "TexturePacker/Sprites/Fantasy/MeleeEnemy/Fantasy_Melee.plist";
	const char* pszAnim_ME_Walk = "walk";
	const char* pszAnim_ME_Death = "death";

	ValueMap dicPList = GCCocosHelpers::CreateDictionaryFromPlist( pszPlist_MeeleEnemy );
	m_pAWalk = GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ME_Walk ) ); //repeat forever until stopped
	m_pAWalk->retain();

	m_pADeathAnim = GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszAnim_ME_Death ) ); //run once
	m_pADeathAnim->retain();

}

void CGCObjFantasyMeele::VOnReset( void )
{
	m_bIsKilled = false;
	CGCObjPatrollingEnemy::VOnReset();
	StopAllActions();
	RunAction( (cocos2d::Action*)m_pAWalk );
}

void CGCObjFantasyMeele::VOnResourceRelease( void )
{
	m_pADeathAnim->release();
	m_pAWalk->release();
}

void CGCObjFantasyMeele::VOnUpdate( float ts )
{
	if (m_bIsKilled)
	{
		if (GetPhysicsBody()->IsActive())
		{
			GetPhysicsBody()->SetLinearVelocity( b2Vec2_zero );
			GetPhysicsBody()->SetActive( false );
		}
	}

	CGCObjPatrollingEnemy::VOnUpdate( ts );
}

void CGCObjFantasyMeele::KillAnimation( void )
{
	StopAllActions();
	m_bIsKilled = true;
	RunAction(
		Sequence::create(
			m_pADeathAnim,
			(cocos2d::Action*)CallFunc::create( [this] {
		CGCObjectManager::ObjectKill( (CGCObject *) this );
	} ),
			nullptr
		)
	);
}


//All actions handled by base class

