#include "CGCBaseEvent.h"


CGCBaseEvent::CGCBaseEvent( char* type )
{
	m_pchzType = type;
	//m_pvData = new std::vector<MyFieldInterface*>();
	m_pmNames = new std::map<const char*, CMyFieldInterface*, cmp_str>();
}

CGCBaseEvent::CGCBaseEvent( const char* type )
{
	m_pchzType = type;
	//m_pvData = new std::vector<MyFieldInterface*>();
	m_pmNames = new std::map<const char*, CMyFieldInterface*, cmp_str>();
}


CGCBaseEvent::~CGCBaseEvent()
{
	delete m_pmNames;
	//delete m_pvData;
}

const char* CGCBaseEvent::GetEventName() const
{
	return m_pchzType;
}

/*
void* CGCBaseEvent::GetDataByName( char* name )
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

void CGCBaseEvent::AddData( char* name, void* item )
{
	m_pmdatafields->insert( std::pair<char*, void*>( name, item ) );
}
*/

