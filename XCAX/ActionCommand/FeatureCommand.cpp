#include <FeatureCommand.h>

ChamferCommand::ChamferCommand(AppPtr app) :Command(app)
{
	auto action = new QAction(this);
	action->setText(QString::fromLocal8Bit("µ¹½Ç"));
	this->SetAction(action);

	m_doc = app->GetCurrentDocPtr();
}

void ChamferCommand::Execute()
{
	vtkSmartPointer<IVtkTools_ShapePicker> aPicker = vtkSmartPointer<IVtkTools_ShapePicker>::New();
	aPicker->SetRenderer(m_app->GetMainWin()->GetRenderer());
	aPicker->SetSelectionMode(SM_Shape);
	aPicker->Pick(0,0,0, m_app->GetMainWin()->GetRenderer());
	vtkActorCollection* anActorCollection = aPicker->GetPickedActors();
	vtkActor* firstActor = vtkActor::SafeDownCast(anActorCollection->GetItemAsObject(0));
	IVtkOCC_Shape::Handle occShape = IVtkTools_ShapeObject::GetOccShape(firstActor);
	auto shape = occShape->GetShape();

	BRepFilletAPI_MakeFillet MF(shape);
	TopExp_Explorer ex(shape, TopAbs_EDGE);
	while (ex.More())
	{
		MF.Add(10, TopoDS::Edge(ex.Current()));
		ex.Next();
	}

	m_app->GetMainWin()->renderShape(MF.Shape());
}