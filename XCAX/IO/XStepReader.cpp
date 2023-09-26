#include "XStepReader.h"

Handle(TopTools_HSequenceOfShape) XStepReader::ReadStep()
{
	Handle(TopTools_HSequenceOfShape) Shapes = new TopTools_HSequenceOfShape();

	QString filename = QFileDialog::getOpenFileName(nullptr,QObject::tr("read a stp file"),
		"E:",QObject::tr("STEP Files(*.stp *.step)"));

	STEPControl_Reader reader_Step;

	Shapes->Clear();
	auto file = filename.toStdString();
	IFSelect_ReturnStatus status = reader_Step.ReadFile(file.data());
	
	// Collecting resulting entities
	Standard_Integer nbs = reader_Step.NbShapes();

	auto shape = reader_Step.OneShape();

	Shapes->Append(shape);
	return Shapes;
}