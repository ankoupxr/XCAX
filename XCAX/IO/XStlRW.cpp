#include "XStlRW.h"


void XStlRW::ReadStl(const std::string filename, const vtkSmartPointer<vtkRenderer> renderer)
{
	OSD_Path stlFile(filename.c_str());
	Handle(Poly_Triangulation) mesh = RWStl::ReadFile(stlFile);
}