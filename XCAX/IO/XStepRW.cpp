#include "XStepRW.h"

TopoDS_Shape XStepRW::readFiles(const std::string filepath, QTreeWidgetItem* parentItem)
{

	auto file = filepath.data();
	
	STEPCAFControl_Reader reader;
	reader.SetColorMode(true);
	reader.SetNameMode(true);

	IFSelect_ReturnStatus status = reader.ReadFile(file);
	Handle(XCAFApp_Application) anApp = XCAFApp_Application::GetApplication();

	Handle(TDocStd_Document) doc;
	anApp->NewDocument("MDTV-XCAF", doc);
	bool IsSuccess = reader.Transfer(doc);
	if (IsSuccess) 
	{
		TDF_Label mainLabel = doc->Main();
		Handle(XCAFDoc_ShapeTool) ShapeTool = XCAFDoc_DocumentTool::ShapeTool(mainLabel);
		Handle(XCAFDoc_ColorTool) ColorTool = XCAFDoc_DocumentTool::ColorTool(mainLabel);
		TDF_LabelSequence tdfLabels;
		ShapeTool->GetFreeShapes(tdfLabels);

		int Roots = tdfLabels.Length();
		for (Standard_Integer i = 1;i <= Roots;i++) 
		{
			const TDF_Label& shapeLabel = tdfLabels.Value(i);

			TCollection_AsciiString labelId;
			TDF_Tool::Entry(mainLabel, labelId);

			Handle_TDataStd_Name nameAttr;
			if (mainLabel.FindAttribute(TDataStd_Name::GetID(), nameAttr))
			{
				TCollection_ExtendedString partName = nameAttr->Get();
				QTreeWidgetItem* childItem = new QTreeWidgetItem(parentItem);
				childItem->setText(0, QString::fromUtf16(partName.ToExtString(), partName.Length()));

				buildTreeWidget(mainLabel, childItem);
			}
		}


		buildTreeWidget(mainLabel, parentItem);
	}

	return reader.Reader().OneShape();
}

void XStepRW::buildTreeWidget(const TDF_Label& label, QTreeWidgetItem* parentItem) {
	TDF_ChildIterator it(label, Standard_True);
	for (; it.More(); it.Next()) {
		const TDF_Label& childLabel = it.Value();

		TCollection_AsciiString labelId;
		TDF_Tool::Entry(childLabel, labelId);

		Handle_TDataStd_Name nameAttr;
		if (childLabel.FindAttribute(TDataStd_Name::GetID(), nameAttr)) 
		{
			TCollection_ExtendedString partName = nameAttr->Get();
			QTreeWidgetItem* childItem = new QTreeWidgetItem(parentItem);
			childItem->setText(0, QString::fromUtf16(partName.ToExtString(), partName.Length()));

			buildTreeWidget(childLabel, childItem);
		}
	}
}