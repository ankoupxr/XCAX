
#include <XCAFTools.h>
#include <XCAFDoc_DocumentTool.hxx>

Handle_XCAFDoc_ShapeTool XCAF::shapeTool() const
{
    return XCAFDoc_DocumentTool::ShapeTool(m_labelMain);
}

Handle_XCAFDoc_LayerTool XCAF::layerTool() const
{
    return XCAFDoc_DocumentTool::LayerTool(m_labelMain);
}

Handle_XCAFDoc_ColorTool XCAF::colorTool() const
{
    return XCAFDoc_DocumentTool::ColorTool(m_labelMain);
}

Handle_XCAFDoc_MaterialTool XCAF::materialTool() const
{
    return XCAFDoc_DocumentTool::MaterialTool(m_labelMain);
}

Handle_XCAFDoc_VisMaterialTool XCAF::visMaterialTool() const
{
    return XCAFDoc_DocumentTool::VisMaterialTool(m_labelMain);
}
