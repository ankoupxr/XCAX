#pragma once


#include <Quantity_Color.hxx>
#include <Standard_Version.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_LayerTool.hxx>
#include <XCAFDoc_Material.hxx>
#include <XCAFDoc_MaterialTool.hxx>
#include <XCAFDoc_VisMaterialTool.hxx>


class XCAFTools
{
public:
	

	Handle_XCAFDoc_ShapeTool shapeTool() const;
	Handle_XCAFDoc_LayerTool layerTool() const;
	Handle_XCAFDoc_ColorTool colorTool() const;
	Handle_XCAFDoc_MaterialTool materialTool() const;
	Handle_XCAFDoc_VisMaterialTool visMaterialTool() const;

private:
    friend class Document;
    TDF_Label m_labelMain;
};
