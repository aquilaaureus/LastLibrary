#ifndef _GCOBJSWITCH_H_
	#include "GCObjSwitch.h"
#endif

USING_NS_CC;



void CGCObjSwitch::SetControl( const char * pstz_Name )
{
	SetName( pstz_Name );
}

void CGCObjSwitch::SetGate( CGCObjGate * pGate )
{
	m_pcConnectedGate = pGate;
}

void CGCObjSwitch::Interact( void )
{
	if (m_pcConnectedGate)
	{
		SetFlippedX( !IsFlippedX() );
		m_pcConnectedGate->OperateGate();
	}
}

CGCObjSwitch::~CGCObjSwitch()
{
}


