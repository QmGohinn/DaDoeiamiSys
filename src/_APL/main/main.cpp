#include "eiamisyswindows.h"

#include <QApplication>

#include "QxDao/QxDao.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EiamiSysWindows w;
    w.show();
    return a.exec();
}
