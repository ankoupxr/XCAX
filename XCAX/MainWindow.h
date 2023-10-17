#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include <QGridLayout>

#include <Container.h>
#include <App.h>
#include <VtkRender.h>
#include <FileCommand.h>
#include <FeatureCommand.h>
#include "ModelTreeWidget.h"

class MainWindow  : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();

	void OnResized();
	void InitMenu();
	void InitCommands();

public slots:
	void recvModelTreeItemSignal(const QTreeWidgetItem* selectedItem);

private:
	class Ui_MainWindow* m_ui = nullptr;
	ModelTreeWidget* m_modeltree;

	AppPtr m_app;
	CommandContainer m_cmdContainer;
};
