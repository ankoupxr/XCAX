#include <FeatureCommand.h>

ChamferCommand::ChamferCommand(AppPtr app) :Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("µ¹½Ç"));
	this->SetAction(action);

	m_doc = app->GetCurrentDocPtr();
}

void ChamferCommand::Execute()
{

}