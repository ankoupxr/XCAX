#pragma once
#include <Command.h>
#include <BRepBuilderAPI_MakeEdge.hxx>

class SketchCommand : public Command
{
	Q_OBJECT
public:
	SketchCommand(AppPtr app);
protected:
	bool m_IsClose = false;
	QList<gp_Pnt> m_pointList;

};

class SketchPolylineCommand : public SketchCommand {
	Q_OBJECT
public:
	SketchPolylineCommand(AppPtr app);
	void Execute() override;
	static constexpr std::string_view Name = "sketch-polyline";
};