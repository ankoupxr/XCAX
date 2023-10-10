#include <Command.h>

Command::Command(AppPtr app)
	: QObject(nullptr),m_app(app)
{
}

void Command::SetAction(QAction* action)
{
	m_action = action;
	QObject::connect(action, &QAction::triggered, this, &Command::Execute);
}