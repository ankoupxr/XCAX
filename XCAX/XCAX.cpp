#include "XCAX.h"
#include <BRepPrimAPI_MakeBox.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepAlgoAPI_Cut.hxx>


XCAX::XCAX(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	//创建菜单
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
	//this->setCentralWidget(qvtkWidget);
	ui.vtlayout->addWidget(qvtkWidget);
}

XCAX::~XCAX()
{}

void XCAX::InitMenu()
{
	//创建菜单
	QMenuBar* bar = menuBar();
	this->setMenuBar(bar);
	QMenu* fileMenu = bar->addMenu(QString::fromLocal8Bit("文件"));
	QAction* readerSTPMenu = fileMenu->addAction(QString::fromLocal8Bit("导入STEP"));
	QAction* readerSTLMenu = fileMenu->addAction(QString::fromLocal8Bit("导入STL"));
	QAction* readerOBJMenu = fileMenu->addAction(QString::fromLocal8Bit("导入OBJ"));

	QMenu* modelingMenu = bar->addMenu(QString::fromLocal8Bit("造型"));
	QAction* BooleanMenu = modelingMenu->addAction(QString::fromLocal8Bit("布尔运算"));
	QAction* FilletConstructorMenu = modelingMenu->addAction(QString::fromLocal8Bit("倒圆"));
	QAction* ChamferConstructorMenu = modelingMenu->addAction(QString::fromLocal8Bit("倒角"));

	QMenu* renderMenu = bar->addMenu(QString::fromLocal8Bit("渲染"));
	
	QMenu* viewMenu = bar->addMenu(QString::fromLocal8Bit("视图"));

	QMenu* toolMenu = bar->addMenu(QString::fromLocal8Bit("工具"));

	QMenu* helpMenu = bar->addMenu(QString::fromLocal8Bit("帮助"));

	connect(readerSTPMenu, &QAction::triggered, this, [=]() {
		//shapes = XStepReader::ReadStep();


		//for (int i = 0; i < shapes->Length(); i++)
		//{
		//	vtkNew<IVtkTools_ShapeDataSource> occSource; //创建一个可以被VTK使用的OCC数据源
		//	occSource->SetShape(new IVtkOCC_Shape(shapes->Value(i))); //将shape添加到数据源中

		//	// 映射、制图人
		//	vtkSmartPointer<vtkOpenGLPolyDataMapper> mapper =
		//		vtkSmartPointer<vtkOpenGLPolyDataMapper>::New();
		//	mapper->SetInputConnection(occSource->GetOutputPort());    // 设置映射的渲染数据

		//	// 演员
		//	vtkSmartPointer<vtkActor> actor =
		//		vtkSmartPointer<vtkActor>::New();
		//	actor->SetMapper(mapper);


		//	// 添加演员
		//	renderer->AddActor(actor);
		//}

		BRepPrimAPI_MakeBox box(2, 2, 2);
		const TopoDS_Shape& shape1 = box.Shape();

		BRepPrimAPI_MakeSphere box2(2);
		const TopoDS_Shape& shape2 = box2.Shape();

		TopoDS_Shape shape = BRepAlgoAPI_Cut(shape1, shape2);

		vtkNew<IVtkTools_ShapeDataSource> occSource; //创建一个可以被VTK使用的OCC数据源
		occSource->SetShape(new IVtkOCC_Shape(shape)); //将shape添加到数据源中

		// 映射、制图人
		vtkSmartPointer<vtkOpenGLPolyDataMapper> mapper =
			vtkSmartPointer<vtkOpenGLPolyDataMapper>::New();
		mapper->SetInputConnection(occSource->GetOutputPort());    // 设置映射的渲染数据

		// 演员
		vtkSmartPointer<vtkActor> actor =
			vtkSmartPointer<vtkActor>::New();
		actor->SetMapper(mapper);

		// 添加演员
		renderer->AddActor(actor);
	});
}