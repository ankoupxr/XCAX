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
	action->setText("����STEP�ļ�");
	this->SetAction(action);

	m_doc = app->GetCurrentDocPtr();

	this->connect(this, &ImportStepCommand::sendImportStepSignal, app->GetMainWin(),&MainWindow::renderShape);
}

void ImportStepCommand::Execute() 
{
	// ����ѡ��Step�ļ�����
	QString filePath = QFileDialog::getOpenFileName(nullptr, "ѡ��Step�ļ�", "", "Step�ļ� (*.step *.stp)");

	XStepRW* rw = new XStepRW();
	TopoDS_Shape ts = rw->readFiles(filePath.toStdString());
	emit this->sendImportStepSignal(ts);
	delete rw;
}