#include <FileCommand.h>
#include <stringcov.h>
#include <QFileDialog>
#include <XStepRW.h>


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
	action->setText(QString::fromLocal8Bit("导入STEP文件"));
	this->SetAction(action);

	m_doc = app->GetCurrentDocPtr();

}

void ImportStepCommand::Execute() 
{
	// 创建选择Step文件窗口
	QString filePath = QFileDialog::getOpenFileName(nullptr, "选择Step文件", "", "Step文件 (*.step *.stp)");

	XStepRW rw;
	TopoDS_Shape ts = rw->readFiles(filePath.toStdString());
	
	m_app->GetMainWin()->renderShape(ts);

	delete rw;
}

ImportObjCommand::ImportObjCommand(AppPtr app) :Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("导入OBJ文件"));
	this->SetAction(action);

	m_doc = app->GetCurrentDocPtr();
}