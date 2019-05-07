#ifndef _GCOBJSWITCH_H_
#define _GCOBJSWITCH_H_


#ifndef _GCOBJSPRITEPHYSICS_H_
#include "GamerCamp/GCCocosInterface/GCObjSpritePhysics.h"
#endif

#ifndef _GCOBJGATE_H_
#include "GamerCamp/GameSpecific/Base/Gate/GCObjGate.h"
#endif

class CGCObjSwitch
	: public CGCObjSpritePhysics
{
private:
	CGCObjGate* m_pcConnectedGate;
public:
	CGCObjSwitch( void )
		: CGCObjSpritePhysics(GetGCTypeIDOf	( CGCObjSwitch ) )
	{
	}

	//On Interact, send event "SwitchUsed" holding the ID of the switch as "ID"

	virtual void VOnResourceAcquire			( void ) override =0;

	void SetControl( const char* pstz_Name );
	void SetGate( CGCObjGate* pGate );
	void Interact( void );

	~CGCObjSwitch();
};

#endif
