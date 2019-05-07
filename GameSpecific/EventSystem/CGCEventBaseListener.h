#ifndef H_EVENTLISTENER_H_
#define H_EVENTLISTENER_H_

#ifndef H_STDA_H_
#include "../stdafx.h"
#endif // !H_STDA_H_

#ifndef H_EVENT_H_
#include "BaseEvent.h"
#endif // !H_EVENT_H_


//////////////////////////////////////////////////////////////////////////
// INHERIT FROM THIS IN ANY CLASS AND IMPLEMENT THE FUNCTIONALITY YOU WANT IN OnEvent
// YOU ALSO RECEIVE THE ACTUAL EVENT TO EXTRACT ANY DATA FROM IT
// SINCE YOU ALSO ADD DATA TO THE EVENT WHEN IT IS SENT FROM ITS SOURCE, 
// MAKE SURE YOU MATCH TYPES AND NAMES.
//
// DO NOT FORGET TO REGISTER YOUR CLASS AS AN LISTENER WITH THE EVENTS MANAGER.
// YOU CAN DO THIS IN MAIN, AND YOU SHOULD DO IT ONLY ONCE.
// IF YOU REGISTER TWICE, YOU WILL RECEIVE THE SAME EVENT TWICE.
//////////////////////////////////////////////////////////////////////////

class EventBaseListener
	: ListObject
{
public:
	EventBaseListener();
	~EventBaseListener();

	// errors that can occur when attempting to call OnEvent
	enum EListenError
	{
		EListenError_Ok = 0,
		EListenError_EventDataTypeMismatch,
		EListenError_NoCallback
	};

	virtual EListenError OnEvent( BaseEvent * ev ) {};
};

#endif // !H_EVENTLISTENER_H_
