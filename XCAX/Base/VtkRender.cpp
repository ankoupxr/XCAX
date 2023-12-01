#include "VtkRender.h"

QTVtkRender::QTVtkRender()
{
    m_vtkwidget = new QVTKOpenGLNativeWidget();
    m_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    m_renderer = vtkSmartPointer<vtkRenderer>::New();
    m_renderWindow->AddRenderer(m_renderer);
    m_vtkwidget->setRenderWindow(m_renderWindow);

    // ��ʾ����ϵ��vtk���
    vtkSmartPointer<vtkAxesActor> axes_actor = vtkSmartPointer<vtkAxesActor>::New();
    axes_actor->SetPosition(0, 0, 0);
    axes_actor->SetTotalLength(2, 2, 2);
    axes_actor->SetShaftType(0);
    axes_actor->SetCylinderRadius(0.03);
    axes_actor->SetAxisLabels(1);
    axes_actor->SetTipType(0);
    axes_actor->SetXAxisLabelText("X");
    axes_actor->SetYAxisLabelText("Y");
    axes_actor->SetZAxisLabelText("Z");
    axes_actor->GetXAxisShaftProperty()->SetColor(1, 0, 0);
    axes_actor->GetYAxisShaftProperty()->SetColor(0, 1, 0);
    axes_actor->GetZAxisShaftProperty()->SetColor(0, 0, 1);

    // ��������ϵ��ʹ֮���ӽǹ�ͬ�仯
    MarkerWidget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    MarkerWidget->SetOrientationMarker(axes_actor);
    MarkerWidget->SetInteractor(m_vtkwidget->interactor());
    MarkerWidget->SetViewport(0.0, 0.0, 0.2, 0.2);
    MarkerWidget->SetEnabled(1);
    MarkerWidget->SetOutlineColor(1, 0, 0);
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

void QTVtkRender::Draw(TopoDS_Shape* ts)
{
    IVtkOCC_Shape::Handle aShapeImpl = new IVtkOCC_Shape(*ts);
    vtkSmartPointer<IVtkTools_ShapeDataSource> DS = vtkSmartPointer<IVtkTools_ShapeDataSource>::New();
    DS->SetShape(aShapeImpl);
    vtkSmartPointer<vtkPolyDataMapper> Mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    Mapper->SetInputConnection(DS->GetOutputPort());
    vtkSmartPointer<vtkActor> Actor = vtkSmartPointer<vtkActor>::New();
    Actor->SetMapper(Mapper);
    Actor->GetProperty()->SetColor(0, 0, 0);
    Actor->GetProperty()->SetRepresentationToWireframe();
    Actor->GetProperty()->SetLineWidth(3);
    Actor->SetPickable(false);
    m_renderer->AddActor(Actor);
}

void QTVtkRender::Remove(TopoDS_Shape* ts)
{

}

void QTVtkRender::OnLeftButtonDown()
{
    vtkInteractorStyleRubberBandPick::OnLeftButtonDown();
    int* pos = this->GetInteractor()->GetEventPosition();
    switch (m_drawMode)
    {
        case DrawMode::Sketch:
            m_coordinate->SetCoordinateSystemToDisplay();
            m_coordinate->SetValue(pos[0], pos[1], 0);
            double* d = m_coordinate->GetComputedWorldValue(m_renderer);
            emit saveMousePoint(d);
            break;
    }
}


QTVtkRender::~QTVtkRender() 
{

}