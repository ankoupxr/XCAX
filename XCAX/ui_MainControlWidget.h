/********************************************************************************
** Form generated from reading UI file 'MainControlWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCONTROLWIDGET_H
#define UI_MAINCONTROLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListView>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainControlWidgetClass
{
public:
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter_Main;
    QWidget *widget_Left;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_LeftContents;
    QVBoxLayout *verticalLayout_5;
    QStackedWidget *stack_LeftContents;
    QWidget *page_ModelTree;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter_ModelTree;
    QWidget *page_OpenedDocuments;
    QVBoxLayout *verticalLayout_6;
    QListView *listView_OpenedDocuments;
    QWidget *page_FileSystem;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_Right;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stack_GuiDocuments;

    void setupUi(QWidget *MainControlWidgetClass)
    {
        if (MainControlWidgetClass->objectName().isEmpty())
            MainControlWidgetClass->setObjectName(QString::fromUtf8("MainControlWidgetClass"));
        MainControlWidgetClass->resize(947, 560);
        verticalLayout_4 = new QVBoxLayout(MainControlWidgetClass);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter_Main = new QSplitter(MainControlWidgetClass);
        splitter_Main->setObjectName(QString::fromUtf8("splitter_Main"));
        splitter_Main->setOrientation(Qt::Horizontal);
        splitter_Main->setChildrenCollapsible(false);
        widget_Left = new QWidget(splitter_Main);
        widget_Left->setObjectName(QString::fromUtf8("widget_Left"));
        horizontalLayout_3 = new QHBoxLayout(widget_Left);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_LeftContents = new QWidget(widget_Left);
        widget_LeftContents->setObjectName(QString::fromUtf8("widget_LeftContents"));
        verticalLayout_5 = new QVBoxLayout(widget_LeftContents);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        stack_LeftContents = new QStackedWidget(widget_LeftContents);
        stack_LeftContents->setObjectName(QString::fromUtf8("stack_LeftContents"));
        page_ModelTree = new QWidget();
        page_ModelTree->setObjectName(QString::fromUtf8("page_ModelTree"));
        verticalLayout_2 = new QVBoxLayout(page_ModelTree);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        splitter_ModelTree = new QSplitter(page_ModelTree);
        splitter_ModelTree->setObjectName(QString::fromUtf8("splitter_ModelTree"));
        splitter_ModelTree->setOrientation(Qt::Vertical);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);

        verticalLayout_2->addWidget(splitter_ModelTree);

        stack_LeftContents->addWidget(page_ModelTree);
        page_OpenedDocuments = new QWidget();
        page_OpenedDocuments->setObjectName(QString::fromUtf8("page_OpenedDocuments"));
        verticalLayout_6 = new QVBoxLayout(page_OpenedDocuments);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        listView_OpenedDocuments = new QListView(page_OpenedDocuments);
        listView_OpenedDocuments->setObjectName(QString::fromUtf8("listView_OpenedDocuments"));
        listView_OpenedDocuments->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listView_OpenedDocuments->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView_OpenedDocuments->setTextElideMode(Qt::ElideMiddle);

        verticalLayout_6->addWidget(listView_OpenedDocuments);

        stack_LeftContents->addWidget(page_OpenedDocuments);
        page_FileSystem = new QWidget();
        page_FileSystem->setObjectName(QString::fromUtf8("page_FileSystem"));
        verticalLayout_3 = new QVBoxLayout(page_FileSystem);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);


        stack_LeftContents->addWidget(page_FileSystem);

        verticalLayout_5->addWidget(stack_LeftContents);


        horizontalLayout_3->addWidget(widget_LeftContents);

        splitter_Main->addWidget(widget_Left);
        widget_Right = new QWidget(splitter_Main);
        widget_Right->setObjectName(QString::fromUtf8("widget_Right"));
        verticalLayout = new QVBoxLayout(widget_Right);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 0, 0, 1);
        stack_GuiDocuments = new QStackedWidget(widget_Right);
        stack_GuiDocuments->setObjectName(QString::fromUtf8("stack_GuiDocuments"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stack_GuiDocuments->sizePolicy().hasHeightForWidth());
        stack_GuiDocuments->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(stack_GuiDocuments);

        splitter_Main->addWidget(widget_Right);

        verticalLayout_4->addWidget(splitter_Main);


        retranslateUi(MainControlWidgetClass);

        stack_LeftContents->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainControlWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MainControlWidgetClass)
    {
        MainControlWidgetClass->setWindowTitle(QCoreApplication::translate("MainControlWidgetClass", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainControlWidgetClass: public Ui_MainControlWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCONTROLWIDGET_H
