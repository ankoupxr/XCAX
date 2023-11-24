#ifndef GEOSHAPE_H
#define GEOSHAPE_H

#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QString>

#include <TopoDS_Shape.hxx>
#include <vtkPolyData.h>

#include <Entity.h>

class GeoShape : public Entity
{
public:
	GeoShape();
	~GeoShape();

	TopoDS_Shape* getShape();
	void setShape(TopoDS_Shape* shape);
private:
	vtkPolyData* m_polyData = nullptr;
	TopoDS_Shape* m_Shape = nullptr;//Ö÷Shape
	QList<GeoShape*> m_subShapeList;//×ÓShape

	static int m_maxid;
};


#endif // !GEOSHAPE_H
