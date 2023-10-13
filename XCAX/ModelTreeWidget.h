#pragma once

#include <QWidget>
#include "ui_ModelTreeWidget.h"
#include <Document.h>

#include <memory>

class ModelTreeWidget : public QWidget
{
	Q_OBJECT

public:
	ModelTreeWidget(QWidget *parent = nullptr);
	~ModelTreeWidget();

	using BuilderPtr = std::unique_ptr<ModelTreeWidget>;


	//static DocumentTreeNode 

	QTreeWidgetItem* ModelTreeWidget::CreateTreeItem(const DocPtr& doc);


signals:
	void sendModelTreeItemSignal(const QTreeWidgetItem* selectedItem);

public slots:
	void recvNewFileSignal(const DocPtr& doc);
	void sendModelTreeItemSignalBuilder();


private:
	class Ui_ModelTreeWidgetClass* m_ui = nullptr;
};
