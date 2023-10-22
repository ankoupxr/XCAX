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
	gp_Pnt P(m_ui.coordX->text().toDouble(), m_ui.coordY->text().toDouble(), m_ui.coordZ->text().toDouble());
	TopoDS_Shape cube = BRepPrimAPI_MakeBox(P, m_ui.cubesizeX->text().toDouble(), m_ui.cubesizeY->text().toDouble(),
		m_ui.cubesizeZ->text().toDouble()).Shape();
	m_app->GetMainWin()->renderShape(cube);
}

void cube_widget::OnCancel() 
{

}