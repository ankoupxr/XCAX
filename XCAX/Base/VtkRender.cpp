#include "VtkRender.h"

QTVtkRender::QTVtkRender()
{
    m_vtkwidget = new QVTKOpenGLNativeWidget();
    m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    m_renderer = vtkSmartPointer<vtkRenderer>::New();
    m_renderWindow->AddRenderer(m_renderer);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow(m_renderWindow);

    vtkSmartPointer<vtkCellPicker> picker = vtkSmartPointer<vtkCellPicker>::New();
    interactor->SetPicker(picker);

    m_vtkwidget->setRenderWindow(m_renderWindow);
}


void QTVtkRender::AddActor(vtkActor* actor)
{
    m_renderer->AddActor(actor);
}

void QTVtkRender::RemoveActor(vtkActor* actor)
{
    m_renderer->RemoveActor(actor);
}

void QTVtkRender::Render()
{
    m_renderWindow->Render();
}


void QTVtkRender::renderShape(TopoDS_Shape ts)
{
    vtkNew<IVtkTools_ShapeDataSource> occSource; //创建一个e添加到数据源中
    occSource->SetShape(new IVtkOCC_Shape(ts)); //将shap
    vtkNew<vtkPolyDataMapper> mapper; //创建一个VTK数据类型

    mapper->SetInputConnection(occSource->GetOutputPort());

    vtkNew<vtkActor> actor; //创建一个vtk actor
    actor->SetMapper(mapper); //将vtk数据交给actor
    m_renderer->AddActor(actor); //在渲染器中加入vtk actor
}

QTVtkRender::~QTVtkRender() 
{

}