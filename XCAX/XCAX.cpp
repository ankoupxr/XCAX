#include "XCAX.h"
#include <BRepPrimAPI_MakeBox.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepAlgoAPI_Cut.hxx>


XCAX::XCAX(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->setWindowIcon(QIcon(":/images/windowIcon.jpg"));
	//�����˵�
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
	this->setCentralWidget(qvtkWidget);
	//ui.vtlayout->addWidget(qvtkWidget);
}

XCAX::~XCAX()
{}

void XCAX::InitMenu()
{
	//�����˵�
	QMenuBar* bar = menuBar();
	this->setMenuBar(bar);
	QMenu* fileMenu = bar->addMenu(QString::fromLocal8Bit("�ļ�"));
	QAction* readerSTPMenu = fileMenu->addAction(QString::fromLocal8Bit("����STEP"));
	QAction* readerSTLMenu = fileMenu->addAction(QString::fromLocal8Bit("����STL"));
	QAction* readerOBJMenu = fileMenu->addAction(QString::fromLocal8Bit("����OBJ"));
	QMenu* modelingMenu = bar->addMenu(QString::fromLocal8Bit("ʵ��"));
	QAction* FilletConstructorMenu = modelingMenu->addAction(QString::fromLocal8Bit("��Բ"));
	QAction* ChamferConstructorMenu = modelingMenu->addAction(QString::fromLocal8Bit("����"));
	QAction* ShellMenu = modelingMenu->addAction(QString::fromLocal8Bit("����"));
	QAction* ThickeningMenu = modelingMenu->addAction(QString::fromLocal8Bit("�Ӻ�"));
	QAction* TorsionMenu = modelingMenu->addAction(QString::fromLocal8Bit("Ťת"));
	QMenu* meshMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	QAction* FillHoleMenu = meshMenu->addAction(QString::fromLocal8Bit("����"));
	QAction* SimpleMenu = meshMenu->addAction(QString::fromLocal8Bit("��"));
	QMenu* surfaceMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	QAction* SufaceFilletConstructorMenu = surfaceMenu->addAction(QString::fromLocal8Bit("��Բ"));
	QAction* SufaceChamferConstructorMenu = surfaceMenu->addAction(QString::fromLocal8Bit("����"));
	QAction* SufaceThickeningMenu = surfaceMenu->addAction(QString::fromLocal8Bit("�Ӻ�"));
	QAction* SufaceTorsionMenu = surfaceMenu->addAction(QString::fromLocal8Bit("Ťת"));
	QMenu* toolMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	QMenu* helpMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	QToolBar* tool = new QToolBar(this);
	this->addToolBar(tool);//����������
	QAction* tool1 = new QAction(QString::fromLocal8Bit("��"));
	QAction* tool2 = new QAction(QString::fromLocal8Bit("����"));
	QAction* tool3 = new QAction(QString::fromLocal8Bit("��"));
	QAction* tool4 = new QAction(QString::fromLocal8Bit("��"));
	QAction* tool5 = new QAction(QString::fromLocal8Bit("ǰ"));
	QAction* tool6 = new QAction(QString::fromLocal8Bit("��"));
	QAction* tool7 = new QAction(QString::fromLocal8Bit("��"));
	QAction* tool8 = new QAction(QString::fromLocal8Bit("��"));
	QAction* tool9 = new QAction(QString::fromLocal8Bit("ԭ��"));
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

void XCAX::OnResized() 
{
	
}