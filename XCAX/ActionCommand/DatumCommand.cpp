#include <DatumCommand.h>

SketchPolylineCommand::SketchPolylineCommand(AppPtr app) :SketchCommand(app)
{

}

void SketchPolylineCommand::Execute()
{
	if (m_pointList.size() < 2)
	{
		return;
	}

	TopoDS_Compound result;
	BRep_Builder resultBuider;
	resultBuider.MakeCompound(result);
	for (int i = 0; i < m_pointList.size() - 1; i++)
	{
		BRepBuilderAPI_MakeEdge edge(m_pointList[i], m_pointList[i + 1]);
		resultBuider.Add(result, edge);
	}

	if (m_IsClose && m_pointList.size() > 2)
	{
		BRepBuilderAPI_MakeEdge edge(m_pointList.last(),m_pointList.first());
		resultBuider.Add(result,edge);
	}

	m_resultShape = new TopoDS_Shape;
	*m_resultShape = result;

}