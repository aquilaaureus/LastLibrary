#ifndef _BASEEVENT_H_
#define _BASEEVENT_H_


#include <vector>
#include <map>

//////////////////////////////////////////////////////////////////////////
// BASE EVENT CLASS
// YOU CAN USE THIS AS IT IS, OR EXTEND IT
// YOU CAN STORE DATA IN THIS CLASS BY NAME AND RETRIEVE IT AT THE LISTENER
//
// WHEN CREATING AN EVENT, YOU NEED TO SUPPLY A "NAME" THAT WILL ACT AS THE EVENT TYPE
// YOU CAN JUST USE A (SHORT) DESCRIPTION OF THE FUNCTIONALITY OR PURPOSE,
// EG "LevelEnded" OR "SwitchUsed". THEN YOU REGISTER ANOTHER OBJECT TO
// LISTEN FOR THIS EVEN TYPE, RETRIEVE DATA FROM IT AND ACT ACCORDINGLY.
//////////////////////////////////////////////////////////////////////////

//The following classes and structs are for storing data inside the event
class CMyFieldInterface
{
public:
	~CMyFieldInterface()
	{
	};
};

template <typename T>
class CMyField : public CMyFieldInterface
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

struct cmp_str
{
	bool operator()( char const *a, char const *b ) const
	{
		return strcmp( a, b ) < 0;
	}
};

//////////////////////////////////////////////////////////////////////////
// ATTENTION: ADD ONLY BASIC TYPES
// NO ARRAYS, NO CHAR* (USE STRING INSTEAD)
// NOTHING THAT DOES NOT INCLUDE ITS OWN SIZE, IT WILL CAUSE AN OVERFLOW.
// USE MORE COMPLEX TYPES AT YOUR RISK. IT WILL PROBABLY WORK, THOUGH.
//////////////////////////////////////////////////////////////////////////


class CGCBaseEvent
{

private:
	const char* m_pchzType;
	std::map<const char*, CMyFieldInterface*, cmp_str>* m_pmNames;

public:
	// accessors for name and event data type id
	CGCBaseEvent( const char* a );
	CGCBaseEvent( char* a );
	~CGCBaseEvent();

	//Get the name (type) of the Event, decided upon creation and used for registration
	const char* GetEventName() const;

	//Add data to the event, by using a name
	template <class DATATYPE> void AddData( const char* name, DATATYPE data )
	{
		m_pmNames->insert( std::make_pair( name, new CMyField<DATATYPE>( data ) ) );
		//m_pvData->push_back( new MyField<DATATYPE>( data ) );
	}

	//get Data from the event, by using the same name as when the data was added.
	template <class DATATYPE> DATATYPE GetDataByName( const char* name )
	{
		if (m_pmNames)// && m_pvData)
		{
			if (m_pmNames->find( name ) != m_pmNames->end())
			{
				//int i = m_pmNames->at( name );
				CMyField<DATATYPE>* y = (CMyField<DATATYPE>*)m_pmNames->at( name ); //m_pvData[i].data();
				return y->GetValue();
			}
		}
		return NULL;
	}
}; 
#endif