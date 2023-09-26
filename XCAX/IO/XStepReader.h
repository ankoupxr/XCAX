#pragma once

#include <STEPControl_Reader.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <QFileDialog>
#include <QString>

class XStepReader
{
public:
	static Handle(TopTools_HSequenceOfShape) XStepReader::ReadStep();

private:

};
