#ifndef GEOSHAPE_H
#define GEOSHAPE_H

#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QString>

#include <TopoDS_Shape.hxx>
#include <vtkPolyData.h>

class GeoShape
{
public:
	GeoShape();
	~GeoShape();

	void setIdentify(int id);

	TopoDS_Shape* getShape(int index);
	void setShape(TopoDS_Shape* shape);
private:
	vtkPolyData* m_polyData;
	TopoDS_Shape* m_Shape;//Ö÷Shape
	QList<GeoShape*> m_subShapeList;//×ÓShape
};


#endif // !GEOSHAPE_H
