#pragma once

#include <QEvent>
#include <QMainWindow>
#include <QMdiArea>

#include <MDIView.h>

class MainWindow  : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QObject *parent = nullptr);
	~MainWindow();

	void AddDocWindow(MDIView* view);

	void RemoveDocWindow(MDIView* view);

	QList<QWidget*> DocWindows(QMdiArea::WindowOrder order = QMdiArea::CreationOrder) const;

	MDIView* CurrentWindow();

	void ChangedTab();
};
