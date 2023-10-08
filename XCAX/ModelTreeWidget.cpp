#include "ModelTreeWidget.h"

ModelTreeWidget::ModelTreeWidget(QWidget *parent)
	: QWidget(parent), m_ui(new Ui_ModelTreeWidgetClass)
{
	m_ui->setupUi(this);
}

ModelTreeWidget::~ModelTreeWidget()
{}
