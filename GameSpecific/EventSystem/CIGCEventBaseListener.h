#ifndef _BASEEVENTLISTENER_H_
#define _BASEEVENTLISTENER_H_


//////////////////////////////////////////////////////////////////////////
// INHERIT FROM THIS IN ANY CLASS AND IMPLEMENT THE FUNCTIONALITY YOU WANT IN OnEvent
// YOU ALSO RECEIVE THE ACTUAL EVENT TO EXTRACT ANY DATA FROM IT
// SINCE YOU ALSO ADD DATA TO THE EVENT WHEN IT IS SENT FROM ITS SOURCE, 
// MAKE SURE YOU MATCH TYPES AND NAMES.
//
// DO NOT FORGET TO REGISTER YOUR CLASS AS AN LISTENER WITH THE EVENTS MANAGER.
// YOU CAN DO THIS RIGHT AFTER CREATING THE OBJECT, AND YOU SHOULD DO IT ONLY ONCE.
// IF YOU REGISTER TWICE, YOU WILL RECEIVE THE SAME EVENT TWICE.
//////////////////////////////////////////////////////////////////////////

//included here so that the listener implementation has access to the event properties and functions
#include "CGCBaseEvent.h"


class CIGCEventBaseListener
{
public:
	CIGCEventBaseListener()
	{}

	virtual ~CIGCEventBaseListener()
	{}

	// errors that can occur when attempting to call OnEvent
	enum EListenError
	{
		EListenError_Ok = 0,
		EListenError_EventDataTypeMismatch,
		EListenError_NoCallback
	};

	virtual EListenError OnEvent( CGCBaseEvent * ev ) = 0;
};
#endif
