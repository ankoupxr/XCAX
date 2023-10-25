#pragma once

#include <STEPCAFControl_Reader.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <QFileDialog>
#include <QString>
#include <Ptr.h>
#include <XCAFApp_Application.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <TreeNode.h>

class XStepRW
{
public:
	static TopoDS_Shape readFiles(const std::string filepath);

    static void BuildModelTree(const Handle(XCAFDoc_ShapeTool)& ShapeTool,
        const Handle(XCAFDoc_ColorTool)& ColorTool,
        const TDF_Label& Label,
        TopLoc_Location Location,
        TreeNodeId ParentNode,
        Tree& Tree);

private:

};
