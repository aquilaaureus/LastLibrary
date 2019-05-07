#ifndef H_STDA_H_
	#include "../stdafx.h"
#endif

#ifndef H_EVENTLISTENER_H_
	#include "EventBaseListener.h"
#endif

//included here so that the listener implementation has access to the event properties and functions
#ifndef H_EVENT_H_
	#include "BaseEvent.h"
#endif

EventBaseListener::EventBaseListener()
{
}


EventBaseListener::~EventBaseListener()
{
}

EventBaseListener::EListenError EventBaseListener::OnEvent( BaseEvent * ev )
{
	return EListenError::EListenError_NoCallback;
}
