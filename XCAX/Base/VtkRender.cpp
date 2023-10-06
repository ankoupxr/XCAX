#include "VtkRender.h"

VtkRender::VtkRender()
{
    m_renderer = vtkSmartPointer<vtkRenderer>::New();
    m_renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    m_renderWindow->AddRenderer(m_renderer);
}


void VtkRender::AddActor(vtkActor* actor)
{
    m_renderer->AddActor(actor);
}

void VtkRender::RemoveActor(vtkActor* actor)
{
    m_renderer->RemoveActor(actor);
}

void VtkRender::Render()
{
    m_renderWindow->Render();
}

vtkRenderer* VtkRender::GetRenderer()
{
    return m_renderer;
}