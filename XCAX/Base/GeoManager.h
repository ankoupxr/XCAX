#ifndef GEOMANAGER_H
#define GEOMANAGER_H

#include <GeoShape.h>

class GeoManager
{
public:
	static GeoManager* getInstance();
	int GetGeoShapeListCount();
	GeoShape* GetShapeById(int id);

private:
	GeoManager() = default;
	~GeoManager();

private:
	static GeoManager* m_instance;
	QList<GeoShape*> m_geoShapeList;

};



#endif // !GEOMANAGER_H
