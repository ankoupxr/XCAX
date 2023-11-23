#pragma once

#include <QDockWidget>

class MainWindow;
class ModelTreeWidget;

class ControlPanel  : public QDockWidget
{
	Q_OBJECT

public:
	ControlPanel(MainWindow* mainwindow);
	~ControlPanel();

	void updateControlPanel();
	void clearPropWidget();//������Դ���
protected:
	ModelTreeWidget* m_modelTreeWidget;


};
