#include "GeoManager.h"


GeoManager* GeoManager::m_instance = nullptr;

GeoManager* GeoManager::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new GeoManager;
	}
	return m_instance;
}


GeoManager::~GeoManager() 
{

}

int GeoManager::GetGeoShapeListCount()
{
	return m_geoShapeList.size();
}

GeoShape* GeoManager::GetShapeById(int id)
{
	if (id >= 0 && id < m_geoShapeList.size()) 
	{
		return m_geoShapeList.at(id);
	}
	else 
	{
		return nullptr;
	}
}