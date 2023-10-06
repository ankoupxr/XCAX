/********************************************************************************
** Form generated from reading UI file 'ModelTreeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELTREEWIDGET_H
#define UI_MODELTREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelTreeWidgetClass
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;

    void setupUi(QWidget *ModelTreeWidgetClass)
    {
        if (ModelTreeWidgetClass->objectName().isEmpty())
            ModelTreeWidgetClass->setObjectName(QString::fromUtf8("ModelTreeWidgetClass"));
        ModelTreeWidgetClass->resize(176, 467);
        gridLayout = new QGridLayout(ModelTreeWidgetClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        treeWidget = new QTreeWidget(ModelTreeWidgetClass);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);


        retranslateUi(ModelTreeWidgetClass);

        QMetaObject::connectSlotsByName(ModelTreeWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *ModelTreeWidgetClass)
    {
        ModelTreeWidgetClass->setWindowTitle(QCoreApplication::translate("ModelTreeWidgetClass", "ModelTreeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelTreeWidgetClass: public Ui_ModelTreeWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELTREEWIDGET_H
