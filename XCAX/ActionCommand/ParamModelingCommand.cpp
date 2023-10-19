#include <ParamModelingCommand.h>


CreateCubeCommand::CreateCubeCommand(AppPtr app)
	:Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("创建立方体"));
	this->SetAction(action);
}

void CreateCubeCommand::Execute()
{
	gp_Pnt P(0, 0, 0);
	TopoDS_Shape cube = BRepPrimAPI_MakeBox(P,100,100,100).Shape();
	m_app->GetMainWin()->renderShape(cube);
}

