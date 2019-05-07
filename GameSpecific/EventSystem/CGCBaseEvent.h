#ifndef H_EVENT_H_
#define H_EVENT_H_

#ifndef H_STDA_H_
#include "../stdafx.h"
#endif // !_STDA_H_


//////////////////////////////////////////////////////////////////////////
// BASE EVENT CLASS
// YOU CAN USE THIS AS IT IS, OR EXTEND IT
// YOU CAN STORE DATA IN THIS CLASS BY NAME AND RETRIEVE IT AT THE LISTENER
//////////////////////////////////////////////////////////////////////////

//The following classes and structs are for storing data inside the event
class CMyFieldi32erface
{
public:
	~CMyFieldi32erface()
	{
	};
};

template <typename T>
class CMyField : public CMyFieldi32erface
{
public:
	T m_Value;
	CMyField( T val )
	{
		m_Value = val;
	}

	T GetValue()
	{
		return m_Value;
	}
};


//////////////////////////////////////////////////////////////////////////
// ATTENTION: ADD ONLY BASIC TYPES
// NO ARRAYS, NO i8* (USE STRING INSTEAD)
// NOTHING THAT DOES NOT INCLUDE ITS OWN SIZE, IT WILL CAUSE AN OVERFLOW.
// USE MORE COMPLEX TYPES AT YOUR RISK. IT WILL PROBABLY WORK, THOUGH.
//////////////////////////////////////////////////////////////////////////


class BaseEvent
{
private:
	const i8* m_pchzType;

public:
	// accessors for name and event data type id
	BaseEvent( const i8* a );
	BaseEvent( i8* a );
	BaseEvent( BaseEvent& ev ) {};

	~BaseEvent();

	//Get the name (type) of the Event, decided upon creation and used for registration
	const i8* BaseEvent::GetEventName() const;

	//Add data to the event, by using a name
	template <class DATATYPE> void AddData( const i8* name, DATATYPE data )
	{
		m_pmNames->insert( make_pair( name, new CMyField<DATATYPE>( data ) ) );
		//m_pvData->push_back( new MyField<DATATYPE>( data ) );
	}

	//get Data from the event, by using the same name as when the data was added.
	template <class DATATYPE> DATATYPE GetDataByName( const i8* name )
	{
		if (m_pmNames)// && m_pvData)
		{
			if (m_pmNames->find( name ) != m_pmNames->end())
			{
				//i32 i = m_pmNames->at( name );
				CMyField<DATATYPE>* y = (CMyField<DATATYPE>*)m_pmNames->at( name ); //m_pvData[i].data();
				return y->GetValue();
			}
		}
		return NULL;
	}
};

#endif // !H_EVENT_H_
