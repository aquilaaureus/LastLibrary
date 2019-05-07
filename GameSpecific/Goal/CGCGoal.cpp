
#ifndef _GCOBJGOAL_H_
	#include "GamerCamp/GameSpecific/Goal/CGCGoal.h"
#endif

#ifndef _GCCOCOSHELPERS_H_
#include "GamerCamp/GCCocosInterface/GCCocosHelpers.h"
#endif // !_GCCOCOSHELPERS_H_


USING_NS_CC;

//////////////////////////////////////////////////////////////////////////
// implement the factory method to enable this to be created via CGCFactory_ObjSpritePhysics 
GCFACTORY_IMPLEMENT_CREATEABLECLASS( CGCGoal );



//////////////////////////////////////////////////////////////////////////
// NOTE: When the opening animation is in, after updating the tps and building data,
// Comment out line 75: RunAction( m_pAOpen ); and comment in lines 40, 41, and 76-80 (the definition of m_pAOpening and the Sequence RunAction)
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCGoal::VOnResourceAcquire( void )
{
	//When creating a Sprite from a plist file that contains animations, the starting sprite is determined randomly.
	//To use the image you want, make an animation with a single frame out of it, and run it. Run it in OnRessurected(), 
	//AFTER chaining to the parent class.
	CGCObjSpritePhysics::VOnResourceAcquire(); // Always call this first

	//Add Animation here if needed
	const char* pszPlist_Goal = "TexturePacker/Sprites/Goal/prop_exit_1.plist";
	const char* pszPlist_G_Closed = "closed";
	const char* pszPlist_G_Opening = "Opening";
	const char* pszPlist_G_Open = "Open";

	ValueMap dicPList = GCCocosHelpers::CreateDictionaryFromPlist( pszPlist_Goal );
	m_pAClosed = GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszPlist_G_Closed ) ); //repeat forever until stopped
	m_pAClosed->retain();
	m_pAOpening = GCCocosHelpers::CreateAnimationActionOnce( GCCocosHelpers::CreateAnimation( dicPList, pszPlist_G_Opening ) ); //repeat forever until stopped
	m_pAOpening->retain();
	m_pAOpen = GCCocosHelpers::CreateAnimationActionLoop( GCCocosHelpers::CreateAnimation( dicPList, pszPlist_G_Open ) ); //repeat forever until stopped
	m_pAOpen->retain();

}



//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual , called BEFORE VOnResurected()
void CGCGoal::VOnReset(void)
{
	StopAllActions();
	m_bActivate = false;
	CGCObjSpritePhysics::VOnReset();
}



//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual 
void CGCGoal::VOnUpdate(f32 fTimeStep)
{
	if (m_bActivate)
	{
		if (!GetPhysicsBody()->IsAwake())
		{
			GetPhysicsBody()->SetAwake( m_bActivate );
			GetPhysicsBody()->SetActive( m_bActivate );
			StopAllActions();
			//RunAction( m_pAOpen );
			RunAction( Sequence::create(
				m_pAOpening,
				(cocos2d::Action*)CallFunc::create( [this] {
				RunAction( m_pAOpen ); } ),
				nullptr ) );
		}
	}
	else
	{	//Activate flag is false here, and this is the natural state of the level
		if (GetPhysicsBody()->IsAwake())
		{
			GetPhysicsBody()->SetAwake( m_bActivate );
			GetPhysicsBody()->SetActive( m_bActivate );
			StopAllActions();
			RunAction( m_pAClosed );
		}
	}
}


//////////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////////
//virtual
void CGCGoal::VOnResourceRelease(void)
{
	DestroySprite();
	m_pAOpen->release();
	m_pAOpening->release();
	m_pAClosed->release();
}

void CGCGoal::VOnResurrected( void )
{
	CGCObjSpritePhysics::VOnResurrected();
	StopAllActions();
	RunAction( m_pAClosed );
}

void CGCGoal::Activate(bool bactivateFlag)
{
	m_bActivate = bactivateFlag;
}


