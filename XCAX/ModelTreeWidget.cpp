#include "ModelTreeWidget.h"

ModelTreeWidget::ModelTreeWidget(MainWindow* m) : m_mainWindow(m)
{
	this->header()->setSectionResizeMode(QHeaderView::ResizeToContents);//根据内容自动调整大小
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);//设为多选
}

ModelTreeWidget::~ModelTreeWidget()
{}


QTreeWidgetItem* ModelTreeWidget::CreateTreeItem(const DocPtr& doc)
{
	QTreeWidgetItem* treeItem = new QTreeWidgetItem();
	auto docname = doc->Name();
	treeItem->setText(0, QString::fromStdString(docname));
	return treeItem;
}

void ModelTreeWidget::recvNewFileSignal(const DocPtr& doc)
{
	static unsigned docSequenceId = 1;
	std::stringstream name;
	name << "File" << docSequenceId++;
	doc->SetName(name.str());
	auto treeItem = this->CreateTreeItem(doc);
	doc->SetRootItem(treeItem);
	m_ui->treeWidget->addTopLevelItem(treeItem);
}

void ModelTreeWidget::sendModelTreeItemSignalBuilder()
{
  auto selectedItem = m_ui->treeWidget->selectedItems().at(0);
  emit sendModelTreeItemSignal(selectedItem);
}

void ModelTreeWidget::updateModelTree() 
{
	
}