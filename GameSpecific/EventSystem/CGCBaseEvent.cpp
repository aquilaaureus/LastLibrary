#ifndef H_EVENT_H_
	#include "BaseEvent.h"
#endif

BaseEvent::BaseEvent( i8* type )
{
	m_pchzType = type;
	//m_pvData = new std::vector<MyFieldi32erface*>();
	m_pmNames = new std::map<const i8*, CMyFieldi32erface*, cmp_str>();
}

BaseEvent::BaseEvent( const i8* type )
{
	m_pchzType = type;
	//m_pvData = new std::vector<MyFieldi32erface*>();
	m_pmNames = new std::map<const i8*, CMyFieldi32erface*, cmp_str>();
}


BaseEvent::~BaseEvent()
{
	delete m_pmNames;
	//delete m_pvData;
}

const i8* BaseEvent::GetEventName() const
{
	return m_pchzType;
}

/*
void* CGCBaseEvent::GetDataByName( i8* name )
{
	if (m_pmdatafields)
	{
		if (m_pmdatafields->find( name ) != m_pmdatafields->end())
		{
			auto k = m_pmdatafields->at( name );
			return k;
		}
	}
	return nullptr;
}

void CGCBaseEvent::AddData( i8* name, void* item )
{
	m_pmdatafields->insert( std::pair<i8*, void*>( name, item ) );
}
*/

