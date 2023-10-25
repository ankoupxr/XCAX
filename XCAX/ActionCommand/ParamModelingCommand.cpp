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
	cubeDialog = new cube_widget(m_app);
	cubeDialog->show();

}

