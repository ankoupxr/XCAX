#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_XCAX.h"
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

#include "IO/XStepReader.h"

class XCAX : public QMainWindow
{
    Q_OBJECT

public:
    XCAX(QWidget *parent = nullptr);
    ~XCAX();

    void InitMenu();

private:
    Ui::XCAXClass ui;

    QVTKOpenGLNativeWidget* qvtkWidget;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderer> renderer;

    Handle(TopTools_HSequenceOfShape) shapes;
};
