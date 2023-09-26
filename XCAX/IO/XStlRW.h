#include <RWStl.hxx>
#include <gp_Vec.hxx>
#include <OSD_Path.hxx>
#include <vtkSmartPointer.h>
#include <vtkOpenGLPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>

class XStlRW
{
public:
	static void ReadStl(const std::string filename,const vtkSmartPointer<vtkRenderer> renderer);

private:

};
