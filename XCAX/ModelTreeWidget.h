#pragma once

#include <QWidget>
#include "ui_ModelTreeWidget.h"
#include <Document.h>

#include <memory>
#include <QTreeWidgetItem>

class MainWindow;

class ModelTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	ModelTreeWidget(MainWindow* m);
	~ModelTreeWidget();

	using BuilderPtr = std::unique_ptr<ModelTreeWidget>;


	//static DocumentTreeNode 

	QTreeWidgetItem* ModelTreeWidget::CreateTreeItem(const DocPtr& doc);
	void SetCurrentDocPtr(const DocPtr& doc) { m_currentDocPtr = doc; };
	DocPtr GetCurrentDocPtr()  const { return m_currentDocPtr; };

signals:
	void sendModelTreeItemSignal(const QTreeWidgetItem* selectedItem);

public slots:
	void recvNewFileSignal(const DocPtr& doc);
	void sendModelTreeItemSignalBuilder();

	void updateModelTree();

private:
	class Ui_ModelTreeWidgetClass* m_ui = nullptr;
	DocPtr m_currentDocPtr;
	AppPtr m_app;

	MainWindow* m_mainWindow{ nullptr };
};
