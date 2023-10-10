#include <FileCommand.h>



NewFileCommand::NewFileCommand(AppPtr app) 
	:Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("´´½¨ÎÄµµ"));
	this->SetAction(action);
}

void NewFileCommand::Execute() 
{
	static unsigned docSequenceId = 0;
	auto docPtr = this->GetApp()->CreateDocFile(Document::FormatType::Binary);
	//docPtr->setName(to_stdString(Command::tr("Anonymous%1").arg(++docSequenceId)));
}