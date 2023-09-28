#pragma once

#include <QWidget>
#include "ui_MainControlWidget.h"

class MainControlWidget : public QWidget
{
	Q_OBJECT

public:
	MainControlWidget(QWidget *parent = nullptr);
	~MainControlWidget();

private:
	Ui::MainControlWidgetClass ui;
};
