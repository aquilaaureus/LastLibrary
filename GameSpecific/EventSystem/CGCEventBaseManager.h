#ifndef _BASEEVENTMANAGER_H_
#define _BASEEVENTMANAGER_H_

#include "CGCBaseEvent.h"
#include "CIGCEventBaseListener.h"

#include <list>

///////////////////////////////////////////////////
// THIS IS THE CENTRAL CLASS OF THE EVENT SYSTEM.
// 
// FROM HERE YOU CAN REGISTER LISTENERS FOR EVENTS OF ANY TYPE
// YOU CAN CREATE, REGISTER, AND SEND EVENTS.
//
// YOU CAN CREATE EVENTS ON YOUR OWN, WITHOUT THE MANAGER, BUT
// IF YOU DO, YOU ARE RESPONSIBLE FOR REGISTERING THEM WITH THE MANAGER
//
// IF YOU ARE IMPLEMENTING THIS SYSTEM, YOU MUST CALL ProcessAllEvents()
// IN EVERY UPDATE.
///////////////////////////////////////////////////

class CGCEventBaseManager
{
private:
	std::list<const char*> * m_pcAllEventTypes;										//List of Registered Event Types (names)
	std::map<const char*, std::list<CIGCEventBaseListener*> * > * m_pmAllListeners;	//List of Registered Listeners, for each event type.

	bool IsEventRegistered( const char* pstrEventName );			//Internal function to check if an event type is already registered
public:
	// it is good practice to detect and report errors, this allows client code to do the 
	// tedious (and application specific) error handling.
	enum EEventError
	{
		EEventError_Ok,
		EEventError_EventNotFound,	//Most likely the event is not registered with the manager
		EEventError_NoListeners		//No listeners have been registered for this event type
	};

	CGCEventBaseManager();
	~CGCEventBaseManager();


	// registers an event type
	// this is necessary so that events of this type can be processed
	void RegisterEventType(const char* pstrName );

	// use this function to create and event, automatically register it, and get a pointer to it back.
	CGCBaseEvent* CreateNewEvent( const char* pstrName );

	// Registers a listener for an event.
	// This returns appropriate error codes if the event isn't registered
	EEventError RegisterAsListener( CIGCEventBaseListener* calling_this, const char* pstrEventName );
	
	//Use this to send an event, by passing the pointer from the event creation.
	//Returns true if sucesssul, false otherwise. 
	//Failure is most likely because the event has not been properly registered.
	//Remember that registration is case sensitive.
	EEventError SendEvent( CGCBaseEvent* pcEvent );

};
#endif