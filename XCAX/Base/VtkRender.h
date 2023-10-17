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

class QTVtkRender
{
public:
	QTVtkRender();
	~QTVtkRender();

	void AddActor(vtkActor* actor);
	void RemoveActor(vtkActor* actor);
	void Render();
	QVTKOpenGLNativeWidget* GetInstance() const { return m_vtkwidget; };
	void renderShape(TopoDS_Shape ts);

private:
	vtkSmartPointer<vtkRenderer> m_renderer;
	vtkSmartPointer<vtkRenderWindow> m_renderWindow;
	QVTKOpenGLNativeWidget* m_vtkwidget;
};

