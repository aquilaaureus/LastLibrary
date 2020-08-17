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
	m_inumOfRegistations = 0;

	//ON DEBUG: Check to see exactly what data this holds after registering a few events, we want each element to be a (const) i8* .
	RegisteredEventTypes = new const i8* [MAX_EVENT_TYPES];

	p_ArrayOfHandlers = new EventSender* [MAX_EVENT_TYPES];

	listOfDelayedEvents = new ChainList<BaseDelayedEvent>();

	/*m_pcAllEventTypes = new std::vector<const i8*>();
	m_pmAllListeners = new std::map<const i8*, std::vector<EventBaseListener*>* >();
	m_pcAllDelayedEvents = new std::vector<BaseDelayedEvent*>();*/
}

EventBaseManager::~EventBaseManager()
{
	delete[] pc_RegisteredEventTypes;
	delete[] p_ArrayOfHandlers;

	pch_listOfDelayedEvents->ClearList();
	delete pch_listOfDelayedEvents;
}

bool EventBaseManager::IsEventRegistered( const i8 * pstrEventName )
{
	return -1 != FindRegisteredEventIndex( pstrEventName );
}

i32 EventBaseManager::FindRegisteredEventIndex( const i8 * pstrEventName )
{
	if (m_inumOfRegistations)
	{
		for (i32 i = 0; i < m_inumOfRegistations; ++i)
		{
			if (pstrEventName == pc_RegisteredEventTypes[i])
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
		pc_RegisteredEventTypes[numOfRegistations++] = pstrName;
		p_ArrayOfHandlers[numOfRegistations] = new EventSender();
		//m_pmAllListeners->insert( std::make_pair( pstrName, new std::vector<EventBaseListener*>() ) );
		//m_pcAllEventTypes->push_back( pstrName );
	}
}

void EventBaseManager::RegisterEventType( const i8 * pstrName, i32 NumOfListeners )
{
	if (!IsEventRegistered( pstrName ))
	{
		pc_RegisteredEventTypes[m_inumOfRegistations++] = pstrName;
		p_ArrayOfHandlers[m_inumOfRegistations] = new EventSender( NumOfListeners );
		//m_pmAllListeners->insert( std::make_pair( pstrName, new std::vector<EventBaseListener*>() ) );
		//m_pcAllEventTypes->push_back( pstrName );
	}
}

bool EventBaseManager::SendDelayedEvent( BaseDelayedEvent * pcEvent )
{
	if (IsEventRegistered( pcEvent->GetEventName() ))
	{
		//Add to delayed list
		pch_listOfDelayedEvents->AddLast( pcEvent );
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
		p_ArrayOfHandlers[index]->RegisterListener( calling_this );
		return EventBaseManager::EEventError::EEventError_Ok;
	}

	return EventBaseManager::EEventError::EEventError_EventNotFound;
}

EventBaseManager::EEventError EventBaseManager::SendEvent( BaseEvent* ev )
{
	i32 index = FindRegisteredEventIndex( ev->GetEventName() );
	if ( -1!= index ) //verify that the event is registered
	{
		if (p_ArrayOfHandlers[index]->NumOfRegisteredListeners()) {
			p_ArrayOfHandlers[index]->Send( ev );
			return EventBaseManager::EEventError::EEventError_Ok;
		}
		else
		{
			return EventBaseManager::EEventError::EEventError_NoListeners; //no listeners
		}
	}
	return EventBaseManager::EEventError::EEventError_EventNotFound; //event not registered
}

void EventBaseManager::VInitialize()
{
	if (!m_inumOfRegistations) {
		pri32f("WARN \tEVENT MANAGER: NO EVENTS REGISTERED");
	}
}

void EventBaseManager::VOnUpdate( f32 deltatime )
{
	if (pch_listOfDelayedEvents->IsEmpty())
	{
		return;
	}
	
	BaseDelayedEvent* curr = pch_listOfDelayedEvents->GetFirst();
	do 
	{
		curr->VOnUpdate( deltatime );

		if (curr->IsDelayOver()) {
			SendEvent( curr );
			curr = pch_listOfDelayedEvents->GetNextFrom( curr );
			pch_listOfDelayedEvents->Remove( pch_listOfDelayedEvents->GetPreviousOf( curr ) );
		} else {
			curr = pch_listOfDelayedEvents->GetNextFrom( curr );
		}
	} while (curr != pch_listOfDelayedEvents->GetLast())

}


