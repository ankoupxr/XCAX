#include "ModelTreeWidget.h"

ModelTreeWidget::ModelTreeWidget(QWidget *parent)
	: QWidget(parent), m_ui(new Ui_ModelTreeWidgetClass)
{
	m_ui->setupUi(this);
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
	m_ui->treeWidget->addTopLevelItem(treeItem);
}