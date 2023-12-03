#ifndef DOCKWIDGET_H
#define DOCKWIDGET_H

#include <QDockWidget>

class MainWindow;

class DockWidget : public QDockWidget
{
	Q_OBJECT
public:
	DockWidget(MainWindow* mainwindow);
	~DockWidget();

private:

};

#endif