#include "cube_widget.h"

cube_widget::cube_widget(AppPtr app):  m_app(app)
{
	m_ui.setupUi(this);
	//QObject::connect(this,&QTreeWidget::itemSelectionChanged,this, &ModelTreeWidget::sendModelTreeItemSignalBuilder);
	QObject::connect(m_ui.confirm, SIGNAL(clicked()), this, SLOT(OnConfirm()));
}

cube_widget::~cube_widget()
{}

void cube_widget::OnConfirm() 
{
	gp_Pnt P(0, 0, 0);
	TopoDS_Shape cube = BRepPrimAPI_MakeBox(P,100,100,100).Shape();
	m_app->GetMainWin()->renderShape(cube);
}

void cube_widget::OnCancel() 
{

}