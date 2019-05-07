#include "CGCEventBaseManager.h"
#include "cocos2d.h"

CGCEventBaseManager::CGCEventBaseManager()
{
	m_pcAllEventTypes = new std::list<const char*>();
	m_pmAllListeners = new std::map<const char*, std::list<CIGCEventBaseListener*>* >();
}


CGCEventBaseManager::~CGCEventBaseManager()
{
	delete m_pcAllEventTypes;
	delete m_pmAllListeners;

	//No need to set them to null pointer here, since they will be removed as the object gets destroyed
}


bool CGCEventBaseManager::IsEventRegistered( const char * pstrEventName )
{
	if (m_pcAllEventTypes->empty())
	{
		return false;
	}
	for (std::list<const char*>::iterator it = m_pcAllEventTypes->begin(); it != m_pcAllEventTypes->end(); ++it)
	{
		if(pstrEventName == *it)
		{
			return true;
		}
	}
	return false;
}

//Use this to register a new event you "new"ed yourself with the manager.
//Do not use for events created with CreateNewEvent(char* Name).
//Returns true if sucesssul, false otherwise. 
//Failure is most likely because the event has not been properly registered.
//Remember that registration is case sensitive.
void CGCEventBaseManager::RegisterEventType( const char * pstrName )
{
	if (!IsEventRegistered( pstrName ))
	{
		m_pmAllListeners->insert( std::make_pair( pstrName, new std::list<CIGCEventBaseListener*>() ) );
		m_pcAllEventTypes->push_back( pstrName );
	}
}

//It is recomended to use this class to generate new events.
//If you don't, registering them and deleting them is your responsibility
CGCBaseEvent * CGCEventBaseManager::CreateNewEvent( const char * pstrName )
{
	CGCBaseEvent* newEvent = new CGCBaseEvent( pstrName );

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
CGCEventBaseManager::EEventError CGCEventBaseManager::RegisterAsListener( CIGCEventBaseListener* calling_this, const char* pstrEventName )
{
	if (IsEventRegistered( pstrEventName )) //check that the event is registered.
	{
        //m_pmAllListeners->at( pstrEventName )->push_back( calling_this );
        auto Cit = m_pmAllListeners->find( pstrEventName );
        if(Cit != m_pmAllListeners->end())
        {
            std::list<CIGCEventBaseListener*> * myvector = Cit->second;
            myvector->push_back(calling_this);
            CCLOG("OnEventListen");
        }
		return CGCEventBaseManager::EEventError::EEventError_Ok;
	}
    CCLOG("OnEvent404");
	return CGCEventBaseManager::EEventError::EEventError_EventNotFound;
}

CGCEventBaseManager::EEventError CGCEventBaseManager::SendEvent( CGCBaseEvent* ev )
{
	if (IsEventRegistered( ev->GetEventName() )) //verify that the event is registered
	{
		auto Cit = m_pmAllListeners->find( ev->GetEventName() ); //Verify that the event has listeners

		if (Cit != m_pmAllListeners->end()) 
		{
			std::list<CIGCEventBaseListener*> * myvector = Cit->second; //get the vector of listeners for this event type
			for (std::list<CIGCEventBaseListener*>::iterator it = myvector->begin(); it != myvector->end(); ++it) //for each listener in the vector...
			{
				CCLOG("OnEventSendToL");
				(*it)->OnEvent( ev ); //...Call OnEvent
			}
            CCLOG("OnEventSend");
            return CGCEventBaseManager::EEventError::EEventError_Ok;
		}
		else
		{
            CCLOG("OnEventSendNoL");
            return CGCEventBaseManager::EEventError::EEventError_NoListeners; //no listeners
		}
	}
    CCLOG("OnEvent404");
    return CGCEventBaseManager::EEventError::EEventError_EventNotFound; //event not registered
}
