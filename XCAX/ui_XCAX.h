/********************************************************************************
** Form generated from reading UI file 'XCAX.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XCAX_H
#define UI_XCAX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XCAXClass
{
public:
    QWidget *centralWidget;
    QTreeWidget *treeWidget;
    QToolBar *toolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *XCAXClass)
    {
        if (XCAXClass->objectName().isEmpty())
            XCAXClass->setObjectName(QString::fromUtf8("XCAXClass"));
        XCAXClass->resize(1113, 560);
        centralWidget = new QWidget(XCAXClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(880, 0, 231, 521));
        XCAXClass->setCentralWidget(centralWidget);
        toolBar = new QToolBar(XCAXClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setIconSize(QSize(50, 50));
        XCAXClass->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(XCAXClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1113, 22));
        XCAXClass->setMenuBar(menuBar);

        retranslateUi(XCAXClass);

        QMetaObject::connectSlotsByName(XCAXClass);
    } // setupUi

    void retranslateUi(QMainWindow *XCAXClass)
    {
        XCAXClass->setWindowTitle(QCoreApplication::translate("XCAXClass", "XCAX", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("XCAXClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class XCAXClass: public Ui_XCAXClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XCAX_H
