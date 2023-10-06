#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>


class VtkRender
{
public:
	VtkRender();
	~VtkRender();

	void AddActor(vtkActor* actor);
	void RemoveActor(vtkActor* actor);
	void Render();
	vtkRenderer* GetRenderer();

private:
	vtkSmartPointer<vtkRenderer> m_renderer;
	vtkSmartPointer<vtkRenderWindow> m_renderWindow;
};

