#include "XCAX.h"
#include <BRepPrimAPI_MakeBox.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepAlgoAPI_Cut.hxx>


XCAX::XCAX(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

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
	//this->setCentralWidget(qvtkWidget);
	ui.vtlayout->addWidget(qvtkWidget);
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

	QMenu* modelingMenu = bar->addMenu(QString::fromLocal8Bit("����"));
	QAction* BooleanMenu = modelingMenu->addAction(QString::fromLocal8Bit("��������"));
	QAction* FilletConstructorMenu = modelingMenu->addAction(QString::fromLocal8Bit("��Բ"));
	QAction* ChamferConstructorMenu = modelingMenu->addAction(QString::fromLocal8Bit("����"));

	QMenu* renderMenu = bar->addMenu(QString::fromLocal8Bit("��Ⱦ"));
	
	QMenu* viewMenu = bar->addMenu(QString::fromLocal8Bit("��ͼ"));

	QMenu* toolMenu = bar->addMenu(QString::fromLocal8Bit("����"));

	QMenu* helpMenu = bar->addMenu(QString::fromLocal8Bit("����"));

	connect(readerSTPMenu, &QAction::triggered, this, [=]() {
		//shapes = XStepReader::ReadStep();


		//for (int i = 0; i < shapes->Length(); i++)
		//{
		//	vtkNew<IVtkTools_ShapeDataSource> occSource; //����һ�����Ա�VTKʹ�õ�OCC����Դ
		//	occSource->SetShape(new IVtkOCC_Shape(shapes->Value(i))); //��shape��ӵ�����Դ��

		//	// ӳ�䡢��ͼ��
		//	vtkSmartPointer<vtkOpenGLPolyDataMapper> mapper =
		//		vtkSmartPointer<vtkOpenGLPolyDataMapper>::New();
		//	mapper->SetInputConnection(occSource->GetOutputPort());    // ����ӳ�����Ⱦ����

		//	// ��Ա
		//	vtkSmartPointer<vtkActor> actor =
		//		vtkSmartPointer<vtkActor>::New();
		//	actor->SetMapper(mapper);


		//	// �����Ա
		//	renderer->AddActor(actor);
		//}

		BRepPrimAPI_MakeBox box(2, 2, 2);
		const TopoDS_Shape& shape1 = box.Shape();

		BRepPrimAPI_MakeSphere box2(2);
		const TopoDS_Shape& shape2 = box2.Shape();

		TopoDS_Shape shape = BRepAlgoAPI_Cut(shape1, shape2);

		vtkNew<IVtkTools_ShapeDataSource> occSource; //����һ�����Ա�VTKʹ�õ�OCC����Դ
		occSource->SetShape(new IVtkOCC_Shape(shape)); //��shape��ӵ�����Դ��

		// ӳ�䡢��ͼ��
		vtkSmartPointer<vtkOpenGLPolyDataMapper> mapper =
			vtkSmartPointer<vtkOpenGLPolyDataMapper>::New();
		mapper->SetInputConnection(occSource->GetOutputPort());    // ����ӳ�����Ⱦ����

		// ��Ա
		vtkSmartPointer<vtkActor> actor =
			vtkSmartPointer<vtkActor>::New();
		actor->SetMapper(mapper);

		// �����Ա
		renderer->AddActor(actor);
	});
}