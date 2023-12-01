#include <GeoShape.h>

int	GeoShape::m_maxid = 0;

GeoShape::GeoShape()
{
	m_maxid++;
	setIdentify(m_maxid);
}

GeoShape::~GeoShape() 
{
	if (m_Shape != nullptr) 
	{
		delete m_Shape;
	}
}

TopoDS_Shape* GeoShape::getShape() 
{
	return m_Shape;
}

void GeoShape::setShape(TopoDS_Shape* shape)
{
	m_Shape = shape;
}