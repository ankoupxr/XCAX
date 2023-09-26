#include "XCAX.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XCAX w;
    w.show();
    return a.exec();
}
