#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
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

#include <Container.h>
#include <App.h>

class MainWindow  : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void OnResized();
	void InitMenu();
	void InitCommands();

public slots:
	void recvModelTreeItemSignal(const QTreeWidgetItem* selectedItem);
	void renderShape(const TopoDS_Shape ts);

private:
	class Ui_MainWindow* m_ui = nullptr;
	QVTKOpenGLNativeWidget* qvtkWidget;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;
	vtkSmartPointer<vtkRenderer> renderer;
	ModelTreeWidget* m_modeltree;

	AppPtr m_app;
	CommandContainer m_cmdContainer;
};
