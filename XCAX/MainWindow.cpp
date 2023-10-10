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

	//创建菜单
	InitCommands();
	InitMenu();

	//初始化VTK窗口，命名为qvtkWidget（原理和QPushButton这种QT自带的控件一样，只是该控件由VTK提供，用法跟QPushButton是一样的）
	qvtkWidget = new QVTKOpenGLNativeWidget();
	//初始化VTK的渲染器，平时用的比较多是vtkRenderWindow，但是在QT中要改用vtkGenericOpenGLRenderWindow，实质上与vtkRenderWindow功能一致
	renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	// 渲染器
	renderer = vtkSmartPointer<vtkRenderer>::New();
	renderWindow->AddRenderer(renderer);

	//将渲染器加入到VTK窗口中。可以先写这一行，后续再将准备好的vtkRenderer加入到renderWindow中也是可以同步数据的
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
	QMenu* fileMenu = bar->addMenu(QString::fromLocal8Bit("文件"));
	fileMenu->addAction(m_cmdContainer.FindCommandAction(NewFileCommand::Name));
	//创建菜单
	//QMenuBar* bar = m_ui->menuBar;
	//this->setMenuBar(bar);
	//QMenu* fileMenu = bar->addMenu(QString::fromLocal8Bit("文件"));
	//QAction* readerDocMenu = fileMenu->addAction(QString::fromLocal8Bit("新建"));
	//QAction* readerSTPMenu = fileMenu->addAction(QString::fromLocal8Bit("导入STEP"));
	//QAction* readerSTLMenu = fileMenu->addAction(QString::fromLocal8Bit("导入STL"));
	//QAction* readerOBJMenu = fileMenu->addAction(QString::fromLocal8Bit("导入OBJ"));
	//QMenu* modelingMenu = bar->addMenu(QString::fromLocal8Bit("参数化"));
	//QAction* CubeMenu = modelingMenu->addAction(QString::fromLocal8Bit("立方体"));
	//QAction*Menu = modelingMenu->addAction(QString::fromLocal8Bit("圆柱体"));
	//QAction* ShellMenu = modelingMenu->addAction(QString::fromLocal8Bit("圆锥体"));
	//QAction* ThickeningMenu = modelingMenu->addAction(QString::fromLocal8Bit("加厚"));
	//QAction* TorsionMenu = modelingMenu->addAction(QString::fromLocal8Bit("扭转"));
	//QMenu* meshMenu = bar->addMenu(QString::fromLocal8Bit("网格"));
	//QAction* FillHoleMenu = meshMenu->addAction(QString::fromLocal8Bit("补孔"));
	//QAction* SimpleMenu = meshMenu->addAction(QString::fromLocal8Bit("简化"));
	//QMenu* surfaceMenu = bar->addMenu(QString::fromLocal8Bit("曲面"));
	//QAction* SufaceFilletConstructorMenu = surfaceMenu->addAction(QString::fromLocal8Bit("倒圆"));
	//QAction* SufaceChamferConstructorMenu = surfaceMenu->addAction(QString::fromLocal8Bit("倒角"));
	//QAction* SufaceThickeningMenu = surfaceMenu->addAction(QString::fromLocal8Bit("加厚"));
	//QAction* SufaceTorsionMenu = surfaceMenu->addAction(QString::fromLocal8Bit("扭转"));
	//QMenu* toolMenu = bar->addMenu(QString::fromLocal8Bit("工具"));
	//QMenu* helpMenu = bar->addMenu(QString::fromLocal8Bit("帮助"));
	//QToolBar* tool = m_ui->toolBar;
	////this->addToolBar(tool);//构建工具栏
	//QAction* tool1 = new QAction(QString::fromLocal8Bit("打开"));
	//QAction* tool2 = new QAction(QString::fromLocal8Bit("导出"));
	//QAction* tool3 = new QAction(QString::fromLocal8Bit("后"));
	//QAction* tool4 = new QAction(QString::fromLocal8Bit("下"));
	//QAction* tool5 = new QAction(QString::fromLocal8Bit("前"));
	//QAction* tool6 = new QAction(QString::fromLocal8Bit("左"));
	//QAction* tool7 = new QAction(QString::fromLocal8Bit("右"));
	//QAction* tool8 = new QAction(QString::fromLocal8Bit("上"));
	//QAction* tool9 = new QAction(QString::fromLocal8Bit("原来"));
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
	//文件
	this->m_cmdContainer.AddNamedCommand<NewFileCommand>();
}

void MainWindow::OnResized()
{

}