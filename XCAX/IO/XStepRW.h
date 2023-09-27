#pragma once

#include <STEPCAFControl_Reader.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <QFileDialog>
#include <QString>

class XStepRW
{
public:
	static TopoDS_Shape readFiles(const std::string filepath);

private:

};
