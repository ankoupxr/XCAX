#include <FileCommand.h>
#include <stringcov.h>



NewFileCommand::NewFileCommand(AppPtr app) 
	:Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("创建文档"));
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
	action->setText("导入STEP文件");
	this->SetAction(action);
	//this->connect(this, &NewFileCommand::sendNewFileSignal, app->GetModelTree(), &ModelTreeWidget::recvNewFileSignal);
}