#include "ModelTreeWidget.h"

ModelTreeWidget::ModelTreeWidget(MainWindow* m) 
{
	this->header()->setSectionResizeMode(QHeaderView::ResizeToContents);//根据内容自动调整大小
	this->setSelectionMode(QAbstractItemView::ExtendedSelection);//设为多选

	m_mainWindow = m;
	this->setHeaderHidden(true);
	m_root = new QTreeWidgetItem(this, 1);
	m_root->setText(0,tr("Shape"));
	m_root->setIcon(0, QIcon(":/images/view-front.svg"));
	this->addTopLevelItem(m_root);
	m_root->setExpanded(true);

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
	m_root->takeChildren();
	removeItemWidget(m_root, 0);
	delete m_root;
	m_root = new QTreeWidgetItem(this, 1);
	m_root->setText(0, tr("Geo"));
	m_root->setIcon(0, QIcon(":/images/view-front.svg"));
	this->addTopLevelItem(m_root);
	m_root->setExpanded(true);

	const int n = m_geoManager->GetGeoShapeListCount();
	for (int i = 0; i < n; ++i)
	{
		GeoShape* geoshape = m_geoManager->GetShapeById(i);
		QString name = geoshape->getName();
		name += QString("(%1)").arg(geoshape->getIdentify());
		Qt::CheckState isvisable = Qt::Unchecked;
		QTreeWidgetItem* item = new QTreeWidgetItem(m_root, 2);
		item->setCheckState(0, isvisable);
		item->setText(0, name);
		item->setIcon(0, QIcon(":/images/view-front.svg"));
	}
}