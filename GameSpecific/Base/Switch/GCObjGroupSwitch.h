#ifndef	_GCOBJECTGROUPSWITCHES_H_
#define	_GCOBJECTGROUPSWITCHES_H_


#ifndef BOX2D_H
#include "Box2d/Box2D.h"
#endif

#ifndef	_GCOBJECTGROUP_H_
#include "GamerCamp/GCObject/GCObjectGroup.h"
#endif

#ifndef _GCOBJECTGROUPGATES_H_
#include "GamerCamp/GameSpecific/Base/Gate/GCObjGroupGates.h"
#endif

//////////////////////////////////////////////////////////////////////////
// forward declare
class CGCObjSprite;
class CGCObjSwitch;

//////////////////////////////////////////////////////////////////////////
// 
class CGCObjGroupSwitch
	: public CGCObjectGroup
{
private:
	bool m_bIsSetUp;

	// destroy managed platforms
	void DestroySpikes( void );

public:
	CGCObjGroupSwitch();
	virtual ~CGCObjGroupSwitch();

//////////////////////////////////////////////////////////////////////////
	// overrides for CGCObjectGroup public interface

	// handles GCObjPlatform
	virtual bool		VHandlesThisTypeId(GCTypeID idQueryType);

	// must return the typeid of the CGCObjectGroup derived class
	virtual GCTypeID	VGetTypeId( void );

	virtual void		VOnGroupResourceRelease( void );
	void SetUp( CGCObjGroupGates* pcGatesGroup );



	// CGCObjectGroup public interface
//////////////////////////////////////////////////////////////////////////
};

#endif