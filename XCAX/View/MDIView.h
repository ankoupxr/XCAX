#pragma once


#include <QMainWindow>
#include <Document.h>


class MDIView : public QMainWindow
{
public:
	MDIView(Document* currentDocument,QWidget* parent);
	~MDIView();

private:

};
