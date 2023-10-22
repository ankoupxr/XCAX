#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	m_ui(new Ui_MainWindow)
{
	m_ui->setupUi(this);
	m_ui->splitter_Main->setStretchFactor(0, 1);
	m_ui->splitter_Main->setStretchFactor(1, 1000);
	this->setWindowIcon(QIcon(":/images/windowIcon.jpg"));

	auto app = new App();
	m_app = app->GetInstance();
	m_cmdContainer.SetApp(m_app);

	m_modeltree = new ModelTreeWidget();
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(m_modeltree);
	m_modeltree->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	m_ui->widget_Left->setLayout(layout);
	m_app->SetModelTree(m_modeltree);
	//创建菜单
	InitCommands();
	InitMenu();

	QTVtkRender* vtkRender = new QTVtkRender();
	m_app->SetMainWin(vtkRender);

	m_ui->stack_GuiDocuments->addWidget(vtkRender->GetInstance());
}

MainWindow::~MainWindow()
{
	
}

void MainWindow::InitMenu()
{
	QMenuBar* bar = m_ui->menuBar;
	this->setMenuBar(bar);
	QMenu* fileMenu = bar->addMenu(QString::fromLocal8Bit("文件"));
	fileMenu->addAction(m_cmdContainer.FindCommandAction(NewFileCommand::Name));
	fileMenu->addAction(m_cmdContainer.FindCommandAction(ImportStepCommand::Name));
	fileMenu->addAction(m_cmdContainer.FindCommandAction(ImportObjCommand::Name));
	QMenu* paramMenu = bar->addMenu(QString::fromLocal8Bit("参数化建模"));
	paramMenu->addAction(m_cmdContainer.FindCommandAction(CreateCubeCommand::Name));
	QMenu* interactiveMenu = bar->addMenu(QString::fromLocal8Bit("交互式建模"));
	QMenu* featureMenu = bar->addMenu(QString::fromLocal8Bit("特征操作"));
	featureMenu->addAction(m_cmdContainer.FindCommandAction(ChamferCommand::Name));
	
	QToolBar* tool = m_ui->toolBar;
	this->addToolBar(tool);//构建工具栏
	QAction* tool1 = new QAction(QString::fromLocal8Bit("打开"));
	QAction* tool2 = new QAction(QString::fromLocal8Bit("导出"));
	QAction* tool3 = new QAction(QString::fromLocal8Bit("后"));
	QAction* tool4 = new QAction(QString::fromLocal8Bit("下"));
	QAction* tool5 = new QAction(QString::fromLocal8Bit("前"));
	QAction* tool6 = new QAction(QString::fromLocal8Bit("左"));
	QAction* tool7 = new QAction(QString::fromLocal8Bit("右"));
	QAction* tool8 = new QAction(QString::fromLocal8Bit("上"));
	QAction* tool9 = new QAction(QString::fromLocal8Bit("原来"));
	tool1->setIcon(QIcon(":/images/file.svg"));
	tool2->setIcon(QIcon(":/images/export.svg"));
	tool3->setIcon(QIcon(":/images/view-back.svg"));
	tool4->setIcon(QIcon(":/images/view-bottom.svg"));
	tool5->setIcon(QIcon(":/images/view-front.svg"));
	tool6->setIcon(QIcon(":/images/view-left.svg"));
	tool7->setIcon(QIcon(":/images/view-right.svg"));
	tool8->setIcon(QIcon(":/images/view-top.svg"));
	tool9->setIcon(QIcon(":/images/view-iso.svg"));
	tool->addAction(tool1);
	tool->addAction(tool2);
	tool->addAction(tool3);
	tool->addAction(tool4);
	tool->addAction(tool5);
	tool->addAction(tool6);
	tool->addAction(tool7);
	tool->addAction(tool8);
	tool->addAction(tool9);

}


void MainWindow::InitCommands() 
{
	//文件
	this->m_cmdContainer.AddNamedCommand<NewFileCommand>();
	this->m_cmdContainer.AddNamedCommand<ImportStepCommand>();
	//参数化
	this->m_cmdContainer.AddNamedCommand<CreateCubeCommand>();
	//特征
	this->m_cmdContainer.AddNamedCommand<ChamferCommand>();
}

void MainWindow::OnResized()
{

}

void MainWindow::recvModelTreeItemSignal(const QTreeWidgetItem* selectedItem)
{
   auto docName = selectedItem->text(0);
   DocPtr docptr = m_app->FindDocumentByName(docName.toStdString());
   m_app->SetCurrentDocPtr(docptr);
}
