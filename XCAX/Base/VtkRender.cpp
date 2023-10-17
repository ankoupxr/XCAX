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
    vtkNew<IVtkTools_ShapeDataSource> occSource; //����һ��e��ӵ�����Դ��
    occSource->SetShape(new IVtkOCC_Shape(ts)); //��shap
    vtkNew<vtkPolyDataMapper> mapper; //����һ��VTK��������

    mapper->SetInputConnection(occSource->GetOutputPort());

    vtkNew<vtkActor> actor; //����һ��vtk actor
    actor->SetMapper(mapper); //��vtk���ݽ���actor
    m_renderer->AddActor(actor); //����Ⱦ���м���vtk actor
}

QTVtkRender::~QTVtkRender() 
{

}