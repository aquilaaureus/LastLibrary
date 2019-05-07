#ifndef H_EVENTMANAGER_H_
#define H_EVENTMANAGER_H_

#ifndef H_STDA_H_
	#include "../stdafx.h"
#endif // !H_STDA_H_

class BaseEvent;
class BaseDelayedEvent;
class EventBaseListener;

///////////////////////////////////////////////////
// THIS IS THE CENTRAL CLASS OF THE EVENT SYSTEM.
// 
// FROM HERE YOU CAN REGISTER LISTENERS FOR EVENTS OF ANY TYPE
// YOU CAN CREATE, REGISTER, AND SEND EVENTS.
//
// YOU CAN CREATE EVENTS ON YOUR OWN, WITHOUT THE MANAGER, BUT
// IF YOU DO, YOU ARE RESPONSIBLE FOR REGISTERING THEM WITH THE MANAGER
// AS WELL AS FOR DELETING THEM AFTER YOU ARE DONE WITH THEM (THEY ARE SENT).
//
// IF YOU ARE IMPLEMENTING THIS SYSTEM, YOU MUST CALL
// EITHER VOnUpdate() OR ProcessAllEvents() IN EVERY UPDATE.
//
// !!!!!!!!!!! NEVER CALL BOTH FUNCTIONS!!!!!!!!!!!!!!!!!
//
///////////////////////////////////////////////////

class ScenarioManager;

class EventBaseManager
	: FrameworkSubsystem
{
	friend ScenarioManager;
public:
	// it is good practice to detect and report errors, this allows client code to do the 
	// tedious (and application specific) error handling.
	enum EEventError
	{
		EEventError_Ok,
		EEventError_EventNotFound,	//Most likely the event is not registered with the manager
		EEventError_NoListeners		//No listeners have been registered for this event type
	};

private:

	class EventSender
	{
	private:
		ChainList<EventBaseListener>* pc_ListenersList;

	public:
		EventSender() {
			pc_ListenersList = new ChainList<EventBaseListener>();
		}

		~EventSender() {
			delete pc_ListenersList;
		};

		void RegisterListener( EventBaseListener* list ){
			pc_ListenersList->AddLast(list);
		};

		EventBaseManager::EEventError Send( BaseEvent* ev ) {
			if (!pc_ListenersList->GetCount()) {
				return EEventError_NoListeners;
			}

			EventBaseListener* curr = pc_ListenersList->GetFirst();

			while (curr)
			{
				curr->OnEvent(ev);
				curr = pc_ListenersList->GetNextFrom(curr);
			}

			return EEventError_Ok;
		};
	};

	i32 numOfRegistations;
	(const i8*)* RegisteredEventTypes;
	ChainList<EventSender>* ListOfHandlers;

	ChainList<BaseDelayedEvent>* listOfDelayedEvents;
	
	bool EventBaseManager::IsEventRegistered( const i8* pstrEventName );			//internal function to check if an event type is already registered
	i32 FindRegisteredEventIndex( const i8* pstrEventName ); //Used  to retrieve the internal index for the Array of Handlers

public:
	EventBaseManager();
	~EventBaseManager();


	// registers an event type
	// this is necessary so that events of this type can be processed
	void EventBaseManager::RegisterEventType(const i8* pstrName );

	//Send Delayed Event
	bool EventBaseManager::SendDelayedEvent( BaseDelayedEvent* pcEvent);

	// use this function to create and event, automatically register it, and get a pointer to it back.
	BaseEvent* EventBaseManager::CreateNewEvent( const i8* pstrName );

	// Registers a listener for an event.
	// This returns appropriate error codes if the event isn't registered
	EventBaseManager::EEventError EventBaseManager::RegisterAsListener( EventBaseListener* calling_this, const i8* pstrEventName );
	
	//Use this to send an event, by passing the pointer from the event creation.
	//Returns true if successful, false otherwise. 
	//Failure is most likely because the event has not been properly registered.
	//Remember that registration is case sensitive.
	EventBaseManager::EEventError EventBaseManager::SendEvent( BaseEvent* pcEvent );
	
	virtual void VOnUpdate( f32 deltatime ) override;

	virtual void VInitialize() override;

	virtual void VLoad(const i8* n) override
	{};

};

#endif // !H_EVENTMANAGER_H_

