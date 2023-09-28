
#include <XCAFTools.h>
#include <XCAFDoc_DocumentTool.hxx>

Handle_XCAFDoc_ShapeTool XCAFTools::shapeTool() const
{
    return XCAFDoc_DocumentTool::ShapeTool(m_labelMain);
}

Handle_XCAFDoc_LayerTool XCAFTools::layerTool() const
{
    return XCAFDoc_DocumentTool::LayerTool(m_labelMain);
}

Handle_XCAFDoc_ColorTool XCAFTools::colorTool() const
{
    return XCAFDoc_DocumentTool::ColorTool(m_labelMain);
}

Handle_XCAFDoc_MaterialTool XCAFTools::materialTool() const
{
    return XCAFDoc_DocumentTool::MaterialTool(m_labelMain);
}

Handle_XCAFDoc_VisMaterialTool XCAFTools::visMaterialTool() const
{
    return XCAFDoc_DocumentTool::VisMaterialTool(m_labelMain);
}
