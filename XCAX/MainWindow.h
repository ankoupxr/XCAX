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

private:
	class Ui_MainWindow* m_ui = nullptr;
	QVTKOpenGLNativeWidget* qvtkWidget;
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;
	vtkSmartPointer<vtkRenderer> renderer;

	AppPtr m_app;
	CommandContainer m_cmdContainer;
};
