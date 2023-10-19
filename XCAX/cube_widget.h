#pragma once
#include <QWidget>
#include "ui_cube_widget.h"

class cube_widget : public QWidget
{
	Q_OBJECT
public:
	cube_widget(QWidget* parent = nullptr);
	~cube_widget();
};