#include <FileCommand.h>
#include <stringcov.h>



NewFileCommand::NewFileCommand(AppPtr app) 
	:Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("�����ĵ�"));
	this->SetAction(action);
	this->connect(this, &NewFileCommand::sendNewFileSignal, app->GetModelTree(),&ModelTreeWidget::recvNewFileSignal);
}

void NewFileCommand::Execute() 
{
	auto docPtr = this->GetApp()->CreateDocFile(Document::FormatType::Binary);
	emit this->sendNewFileSignal(docPtr);
}


ImportStepCommand::ImportStepCommand(AppPtr app) :Command(app)
{
	auto action = new QAction(this);
	action->setText("����STEP�ļ�");
	this->SetAction(action);
	//this->connect(this, &NewFileCommand::sendNewFileSignal, app->GetModelTree(), &ModelTreeWidget::recvNewFileSignal);
}