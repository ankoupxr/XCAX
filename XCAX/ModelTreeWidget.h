#pragma once

#include <QWidget>
#include "ui_ModelTreeWidget.h"
#include <Document.h>
#include <GeoManager.h>

#include <memory>
#include <QTreeWidgetItem>

class MainWindow;

class ModelTreeWidget : public QTreeWidget
{
	Q_OBJECT

public:
	ModelTreeWidget(MainWindow* m,QWidget* parent = nullptr);
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

	void updateModelTree();//更新模型树
	void singleClicked(QTreeWidgetItem*, int);//鼠标点击事件

private:
	class Ui_ModelTreeWidgetClass* m_ui = nullptr;
	DocPtr m_currentDocPtr;
	AppPtr m_app;

	MainWindow* m_mainWindow{ nullptr };
	QTreeWidgetItem* m_root = nullptr;
	GeoManager* m_geoManager = nullptr;
};
