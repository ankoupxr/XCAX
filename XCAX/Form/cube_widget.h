#pragma once
#include <QWidget>
#include "ui_cube_widget.h"
#include <Ptr.h>
#include <App.h>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeBox.hxx>

class cube_widget : public QDialog
{
	Q_OBJECT
public:
	cube_widget(AppPtr app);
	~cube_widget();

	Ui::CubeDialog m_ui;
protected:
	AppPtr m_app = nullptr;
private slots:
	void OnConfirm();
	void OnCancel();
};