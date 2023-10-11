#pragma once


#include <Quantity_Color.hxx>
#include <Standard_Version.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_LayerTool.hxx>
#include <XCAFDoc_Material.hxx>
#include <XCAFDoc_MaterialTool.hxx>
#include <XCAFDoc_VisMaterialTool.hxx>


class XCAF
{
public:
	

	Handle_XCAFDoc_ShapeTool shapeTool() const;
	Handle_XCAFDoc_LayerTool layerTool() const;
	Handle_XCAFDoc_ColorTool colorTool() const;
	Handle_XCAFDoc_MaterialTool materialTool() const;
	Handle_XCAFDoc_VisMaterialTool visMaterialTool() const;

	void setLabelMain(const TDF_Label& labelMain) { m_labelMain = labelMain; }
	//void setModelTree(Tree<TDF_Label>& modelTree) { m_modelTree = &modelTree; }

private:
    friend class Document;
    TDF_Label m_labelMain;
	//Tree<TDF_Label>* m_modelTree = nullptr;
};
