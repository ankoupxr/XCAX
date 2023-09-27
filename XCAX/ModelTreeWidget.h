#pragma once

#include <QWidget>
#include "ui_ModelTreeWidget.h"

class ModelTreeWidget : public QWidget
{
	Q_OBJECT

public:
	ModelTreeWidget(QWidget *parent = nullptr);
	~ModelTreeWidget();

private:
	Ui::ModelTreeWidgetClass ui;
};
