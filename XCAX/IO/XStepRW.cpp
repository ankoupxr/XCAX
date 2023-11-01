#include "XStepRW.h"

TopoDS_Shape XStepRW::readFiles(const std::string filepath,Tree& tree)
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

		TreeNodeId rootNodeId = tree.GetRootNode();
		for (int index = 1; index <= Roots; index++)
		{
			TDF_Label label = tdfLabels.Value(index);
			BuildModelTree(ShapeTool, ColorTool, label,TopLoc_Location(), rootNodeId,tree);
		}
	}

	return reader.Reader().OneShape();
}

void XStepRW::BuildModelTree(const Handle(XCAFDoc_ShapeTool)& ShapeTool,
	const Handle(XCAFDoc_ColorTool)& ColorTool,
	const TDF_Label& Label,
	TopLoc_Location Location,
	TreeNodeId ParentNode,
	Tree& Tree)
{
	TDF_LabelSequence components;
	if (ShapeTool->GetComponents(Label, components))
	{
		for (Standard_Integer compIndex = 1; compIndex <= components.Length(); ++compIndex) 
		{
			TDF_Label ChildLabel = components.Value(compIndex);
			if (ShapeTool->IsReference(ChildLabel))
			{
				TDF_Label ShapeLabel;
				if (ShapeTool->GetReferredShape(ChildLabel, ShapeLabel))
				{
					TopLoc_Location LocalLocation = Location * ShapeTool->GetLocation(ChildLabel);
					//TreeData treeData = GetData(ShapeTool, ColorTool, ShapeLabel, LocalLocation);
					TreeNodeId Node = Tree.AppendChild(ParentNode,ShapeLabel);
					BuildModelTree(ShapeTool, ColorTool, ShapeLabel, LocalLocation, Node, Tree);
				}
			}
		}
	}
}