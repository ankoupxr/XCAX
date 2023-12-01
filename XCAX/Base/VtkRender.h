#pragma once

#include <QVTKOpenGLNativeWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <QGridLayout>
#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkOpenGLPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <BRepPrimAPI_MakeBox.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <vtkCellPicker.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkProperty.h>
#include <vtkInteractorStyleRubberBandPick.h>
#include <vtkCoordinate.h>

enum DrawMode
{
	None = -1,
	Sketch
};

class QTVtkRender : public QObject, public vtkInteractorStyleRubberBandPick
{
	Q_OBJECT
public:
	QTVtkRender();
	~QTVtkRender();

	void AddActor(vtkActor* actor);
	void RemoveActor(vtkActor* actor);
	void Render();
	vtkRenderer* GetRenderer() const { return m_renderer; };
	QVTKOpenGLNativeWidget* GetInstance() const { return m_vtkwidget; };
	void renderShape(TopoDS_Shape ts);

signals:
	void saveMousePoint(double* p);

public slots:
	void Draw(TopoDS_Shape*);
	void Remove(TopoDS_Shape*);

private:
	virtual void OnLeftButtonDown() override;

private:
	vtkSmartPointer<vtkRenderer> m_renderer;
	vtkSmartPointer<vtkRenderWindow> m_renderWindow;
	QVTKOpenGLNativeWidget* m_vtkwidget;
	vtkSmartPointer<vtkOrientationMarkerWidget> MarkerWidget;
	DrawMode m_drawMode{ DrawMode::None };
	vtkCoordinate* m_coordinate = nullptr;
};

