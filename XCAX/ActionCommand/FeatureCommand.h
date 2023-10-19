#pragma once
#include <Command.h>
#include <IVtkTools_ShapePicker.hxx>
#include <IVtkTools_ShapeObject.hxx>
#include <TopoDS_Shape.hxx> 
#include <TopoDS.hxx> 
#include <BRepPrimAPI_MakeBox.hxx> 
#include <TopoDS_Solid.hxx> 
#include <BRepFilletAPI_MakeFillet.hxx> 
#include <TopExp_Explorer.hxx> 

class ChamferCommand : public Command {
	Q_OBJECT
public:
	ChamferCommand(AppPtr app);
	void Execute() override;
	static constexpr std::string_view Name = "chamfer";
};
