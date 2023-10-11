#include "ModelTreeWidget.h"

ModelTreeWidget::ModelTreeWidget(QWidget *parent)
	: QWidget(parent), m_ui(new Ui_ModelTreeWidgetClass)
{
	m_ui->setupUi(this);
}

ModelTreeWidget::~ModelTreeWidget()
{}

void ModelTreeWidget::OnDocumentAdded(const DocPtr& doc)
{
	auto treeItem = this->CreateTreeItem(doc);
	m_ui->treeWidget->addTopLevelItem(treeItem);
}






QTreeWidgetItem* ModelTreeWidget::CreateTreeItem(const DocPtr& doc)
{
	QTreeWidgetItem* treeItem = new QTreeWidgetItem();
	treeItem->setText(0, QString::fromStdString(doc->Name()));
	return treeItem;
}