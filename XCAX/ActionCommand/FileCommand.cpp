#include <FileCommand.h>
#include <stringcov.h>
#include <QFileDialog>
#include <XStepRW.h>


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
	action->setText(QString::fromLocal8Bit("����STEP�ļ�"));
	this->SetAction(action);

	m_doc = app->GetCurrentDocPtr();

}

void ImportStepCommand::Execute() 
{
	// ����ѡ��Step�ļ�����
	QString filePath = QFileDialog::getOpenFileName(nullptr, "ѡ��Step�ļ�", "", "Step�ļ� (*.step *.stp)");

	XStepRW rw;
	TopoDS_Shape ts = rw->readFiles(filePath.toStdString());
	
	m_app->GetMainWin()->renderShape(ts);

	delete rw;
}

ImportObjCommand::ImportObjCommand(AppPtr app) :Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("����OBJ�ļ�"));
	this->SetAction(action);

	m_doc = app->GetCurrentDocPtr();
}