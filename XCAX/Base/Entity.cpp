#include "Entity.h"

void Entity::setIdentify(int id)
{
	m_id = id;
}

int Entity::getIdentify() 
{
	return m_id;
}

void Entity::setName(const QString& name) 
{
	m_name = name;
}

QString Entity::getName() 
{
	return m_name;
}
