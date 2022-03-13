#include "../_APL/main/eiamisyswindows.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EiamiSysWindows w;
    w.show();
    return a.exec();
}
