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
#include <QTreeWidget>
#include <TDF_Label.hxx>
#include <TDF_Tool.hxx>
#include <TDF_ChildIterator.hxx>
#include <QTreeWidgetItem>
#include <TDataStd_Name.hxx>

class XStepRW
{
public:
	static TopoDS_Shape readFiles(const std::string filepath, QTreeWidgetItem* parentItem);

	static void buildTreeWidget(const TDF_Label& label, QTreeWidgetItem* parentItem);

private:

};
