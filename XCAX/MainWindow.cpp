#include "MainWindow.h"
#include <BRepPrimAPI_MakeBox.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepAlgoAPI_Cut.hxx>
#include <FileCommand.h>


MainWindow::MainWindow(QWidget* parent)
	: QMainWindow(parent),
	m_ui(new Ui_MainWindow)
{
	m_ui->setupUi(this);
	m_ui->splitter_Main->setStretchFactor(0, 1);
	m_ui->splitter_Main->setStretchFactor(1, 120);
	this->setWindowIcon(QIcon(":/images/windowIcon.jpg"));

	auto app = new App();
	m_app = app->GetInstance();
	m_cmdContainer.SetApp(m_app);

	//�����˵�
	InitCommands();
	InitMenu();

	//��ʼ��VTK���ڣ�����ΪqvtkWidget��ԭ���QPushButton����QT�Դ��Ŀؼ�һ����ֻ�Ǹÿؼ���VTK�ṩ���÷���QPushButton��һ���ģ�
	qvtkWidget = new QVTKOpenGLNativeWidget();
	//��ʼ��VTK����Ⱦ����ƽʱ�õıȽ϶���vtkRenderWindow��������QT��Ҫ����vtkGenericOpenGLRenderWindow��ʵ������vtkRenderWindow����һ��
	renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	// ��Ⱦ��
	renderer = vtkSmartPointer<vtkRenderer>::New();
	renderWindow->AddRenderer(renderer);

	//����Ⱦ�����뵽VTK�����С�������д��һ�У������ٽ�׼���õ�vtkRenderer���뵽renderWindow��Ҳ�ǿ���ͬ�����ݵ�
	qvtkWidget->setRenderWindow(renderWindow);
	m_ui->stack_GuiDocuments->addWidget(qvtkWidget);
	//ui.vtlayout->addWidget(qvtkWidget);
}

MainWindow::~MainWindow()
{}

void MainWindow::InitMenu()
{
	QMenuBar* bar = m_ui->menuBar;
	this->setMenuBar(bar);
	QMenu* fileMenu = bar->addMenu(QString::fromLocal8Bit("�ļ�"));
	fileMenu->addAction(m_cmdContainer.FindCommandAction(NewFileCommand::Name));
	//�����˵�
	//QMenuBar* bar = m_ui->menuBar;
	//this->setMenuBar(bar);
	//QMenu* fileMenu = bar->addMenu(QString::fromLocal8Bit("�ļ�"));
	//QAction* readerDocMenu = fileMenu->addAction(QString::fromLocal8Bit("�½�"));
	//QAction* readerSTPMenu = fileMenu->addAction(QString::fromLocal8Bit("����STEP"));
	//QAction* readerSTLMenu = fileMenu->addAction(QString::fromLocal8Bit("����STL"));
	//QAction* readerOBJMenu = fileMenu->addAction(QString::fromLocal8Bit("����OBJ"));
	//QMenu* modelingMenu = bar->addMenu(QString::fromLocal8Bit("������"));
	//QAction* CubeMenu = modelingMenu->addAction(QString::fromLocal8Bit("������"));
	//QAction*Menu = modelingMenu->addAction(QString::fromLocal8Bit("Բ����"));
	//QAction* ShellMenu = modelingMenu->addAction(QString::fromLocal8Bit("Բ׶��"));
	//QAction* ThickeningMenu = modelingMenu->addAction(QString::fromLocal8Bit("�Ӻ�"));
	//QAction* TorsionMenu = modelingMenu->addAction(QString::fromLocal8Bit("Ťת"));
	//QMenu* meshMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	//QAction* FillHoleMenu = meshMenu->addAction(QString::fromLocal8Bit("����"));
	//QAction* SimpleMenu = meshMenu->addAction(QString::fromLocal8Bit("��"));
	//QMenu* surfaceMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	//QAction* SufaceFilletConstructorMenu = surfaceMenu->addAction(QString::fromLocal8Bit("��Բ"));
	//QAction* SufaceChamferConstructorMenu = surfaceMenu->addAction(QString::fromLocal8Bit("����"));
	//QAction* SufaceThickeningMenu = surfaceMenu->addAction(QString::fromLocal8Bit("�Ӻ�"));
	//QAction* SufaceTorsionMenu = surfaceMenu->addAction(QString::fromLocal8Bit("Ťת"));
	//QMenu* toolMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	//QMenu* helpMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	//QToolBar* tool = m_ui->toolBar;
	////this->addToolBar(tool);//����������
	//QAction* tool1 = new QAction(QString::fromLocal8Bit("��"));
	//QAction* tool2 = new QAction(QString::fromLocal8Bit("����"));
	//QAction* tool3 = new QAction(QString::fromLocal8Bit("��"));
	//QAction* tool4 = new QAction(QString::fromLocal8Bit("��"));
	//QAction* tool5 = new QAction(QString::fromLocal8Bit("ǰ"));
	//QAction* tool6 = new QAction(QString::fromLocal8Bit("��"));
	//QAction* tool7 = new QAction(QString::fromLocal8Bit("��"));
	//QAction* tool8 = new QAction(QString::fromLocal8Bit("��"));
	//QAction* tool9 = new QAction(QString::fromLocal8Bit("ԭ��"));
	//tool1->setIcon(QIcon(":/images/file.svg"));
	//tool2->setIcon(QIcon(":/images/export.svg"));
	//tool3->setIcon(QIcon(":/images/view-back.svg"));
	//tool4->setIcon(QIcon(":/images/view-bottom.svg"));
	//tool5->setIcon(QIcon(":/images/view-front.svg"));
	//tool6->setIcon(QIcon(":/images/view-left.svg"));
	//tool7->setIcon(QIcon(":/images/view-right.svg"));
	//tool8->setIcon(QIcon(":/images/view-top.svg"));
	//tool9->setIcon(QIcon(":/images/view-iso.svg"));
	//tool->addAction(tool1);
	//tool->addAction(tool2);
	//tool->addAction(tool3);
	//tool->addAction(tool4);
	//tool->addAction(tool5);
	//tool->addAction(tool6);
	//tool->addAction(tool7);
	//tool->addAction(tool8);
	//tool->addAction(tool9);

}


void MainWindow::InitCommands() 
{
	//�ļ�
	this->m_cmdContainer.AddNamedCommand<NewFileCommand>();
}

void MainWindow::OnResized()
{

}