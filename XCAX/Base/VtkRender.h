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


class VtkRender : public QVTKOpenGLNativeWidget
{
	Q_OBJECT
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

