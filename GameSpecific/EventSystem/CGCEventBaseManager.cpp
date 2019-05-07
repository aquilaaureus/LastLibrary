#ifndef H_STDA_H_
	#include "../stdafx.h"
#endif

#ifndef H_EVENT_H_
	#include "BaseEvent.h"
#endif

#ifndef H_EVENTLISTENER_H_
	#include "EventBaseListener.h"
#endif

#ifndef H_EVENTMANAGER_H_
	#include "EventBaseManager.h"
#endif

#ifndef H_DELAYEDEVENT_H_
	#include "BaseDelayedEvent.h"
#endif

EventBaseManager::EventBaseManager()
{
	numOfRegistations = 0;

	//ON DEBUG: Check to see exactly what data this holds after registering a few events, we want each element to be a (const) i8* .
	RegisteredEventTypes = new const i8* [MAX_EVENT_TYPES];

	ArrayOfHandlers = new EventSender* [MAX_EVENT_TYPES];

	listOfDelayedEvents = new ChainList<BaseDelayedEvent>();

	/*m_pcAllEventTypes = new std::vector<const i8*>();
	m_pmAllListeners = new std::map<const i8*, std::vector<EventBaseListener*>* >();
	m_pcAllDelayedEvents = new std::vector<BaseDelayedEvent*>();*/
}

EventBaseManager::~EventBaseManager()
{
	delete[] RegisteredEventTypes;
	delete[] ArrayOfHandlers;

	listOfDelayedEvents->ClearList();
	delete listOfDelayedEvents;
}

bool EventBaseManager::IsEventRegistered( const i8 * pstrEventName )
{
	return -1 != FindRegisteredEventIndex( pstrEventName );
}

i32 EventBaseManager::FindRegisteredEventIndex( const i8 * pstrEventName )
{
	if (numOfRegistations)
	{
		for (i32 i = 0; i < numOfRegistations; ++i)
		{
			if (pstrEventName == RegisteredEventTypes[i])
			{
				return i;
			}
		}
	}
	return -1; //Not found
}

//Use this to register a new event you "new"ed yourself with the manager.
//Do not use for events created with CreateNewEvent(i8* Name).
//Remember that registration is case sensitive.
void EventBaseManager::RegisterEventType( const i8 * pstrName )
{
	if (!IsEventRegistered( pstrName ))
	{
		RegisteredEventTypes[numOfRegistations++] = pstrName;
		ArrayOfHandlers[numOfRegistations] = new EventSender();
		//m_pmAllListeners->insert( std::make_pair( pstrName, new std::vector<EventBaseListener*>() ) );
		//m_pcAllEventTypes->push_back( pstrName );
	}
}

void EventBaseManager::RegisterEventType( const i8 * pstrName, i32 NumOfListeners )
{
	if (!IsEventRegistered( pstrName ))
	{
		RegisteredEventTypes[numOfRegistations++] = pstrName;
		ArrayOfHandlers[numOfRegistations] = new EventSender( NumOfListeners );
		//m_pmAllListeners->insert( std::make_pair( pstrName, new std::vector<EventBaseListener*>() ) );
		//m_pcAllEventTypes->push_back( pstrName );
	}
}

bool EventBaseManager::SendDelayedEvent( BaseDelayedEvent * pcEvent )
{
	if (IsEventRegistered( pcEvent->GetEventName() ))
	{
		//Add to delayed list
		listOfDelayedEvents->AddLast( pcEvent );
		return true;
	}
	else
	{
		return false;
	}
}

//It is recomended to use this class to generate new events.
//If you don't, registering them and deleting them is your responsibility
BaseEvent * EventBaseManager::CreateNewEvent( const i8 * pstrName )
{
	BaseEvent* newEvent = new BaseEvent( pstrName );

	if (!IsEventRegistered( newEvent->GetEventName() ))
	{
		RegisterEventType( newEvent->GetEventName() ); //register the event type, if it is not registered.
	}

	return newEvent;
}

//Use this to register a listener for an event.
//Returns true if sucesssul, false otherwise. 
//Failure is most likely because the event has not been properly registered.
//Remember that registration is case sensitive.
EventBaseManager::EEventError EventBaseManager::RegisterAsListener( EventBaseListener* calling_this, const i8* pstrEventName )
{
	i32 index = FindRegisteredEventIndex( pstrEventName );
	if (-1 != index) //check that the event is registered.
	{
		//m_pmAllListeners->at( pstrEventName )->push_back( calling_this );
		ArrayOfHandlers[index]->RegisterListener( calling_this );
		return EventBaseManager::EEventError::EEventError_Ok;
	}

	return EventBaseManager::EEventError::EEventError_EventNotFound;
}

EventBaseManager::EEventError EventBaseManager::SendEvent( BaseEvent* ev )
{
	i32 index = FindRegisteredEventIndex( ev->GetEventName() );
	if ( -1!= index ) //verify that the event is registered
	{
		if (ArrayOfHandlers[index]->NumOfRegisteredListeners()) {
			ArrayOfHandlers[index]->Send( ev );
			return EventBaseManager::EEventError::EEventError_Ok;
		}
		//if (it != m_pmAllListeners->end()) 
		//{
		//	std::vector<EventBaseListener*> * myvector = it->second; //get the vector of listeners for this event type
		//	for (std::vector<EventBaseListener*>::iterator it = myvector->begin(); it != myvector->end(); ++it) //for each listener in the vector...
		//	{
		//		(*it)->OnEvent( ev ); //...Call OnEvent
		//	}
		//	//m_pvcAllEventsList->push_back( ev ); //add event to the stack (send) in order to be processed
		//	return EventBaseManager::EEventError::EEventError_Ok;
		//}
		else
		{
			return EventBaseManager::EEventError::EEventError_NoListeners; //no listeners
		}
	}
	return EventBaseManager::EEventError::EEventError_EventNotFound; //event not registered
}

void EventBaseManager::VInitialize()
{
	if (!numOfRegistations) {
		pri32f("WARN \tEVENT MANAGER: NO EVENTS REGISTERED");
	}
}

void EventBaseManager::VOnUpdate( f32 deltatime )
{
	if (listOfDelayedEvents->IsEmpty())
	{
		return;
	}
	
	BaseDelayedEvent* curr = listOfDelayedEvents->GetFirst();
	do 
	{
		curr->VOnUpdate( deltatime );

		if (curr->IsDelayOver()) {
			SendEvent( curr );
			curr = listOfDelayedEvents->GetNextFrom( curr );
			listOfDelayedEvents->Remove( listOfDelayedEvents->GetPreviousOf( curr ) );
		} else {
			curr = listOfDelayedEvents->GetNextFrom( curr );
		}
	} while (curr != listOfDelayedEvents->GetLast());

	//for (std::vector<BaseDelayedEvent*>::iterator it = m_pcAllDelayedEvents->begin(); it != m_pcAllDelayedEvents->end(); ++it) //for each listener in the vector...
	//{
	//	(*it)->VOnUpdate( deltatime );
	//	if ((*it)->IsDelayOver())
	//	{
	//		SendEvent( (*it) );

	//	}
	//}

}


