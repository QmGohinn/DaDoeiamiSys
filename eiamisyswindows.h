#ifndef EIAMISYSWINDOWS_H
#define EIAMISYSWINDOWS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EiamiSysWindows; }
QT_END_NAMESPACE

class EiamiSysWindows : public QMainWindow
{
    Q_OBJECT

public:
    EiamiSysWindows(QWidget *parent = nullptr);
    ~EiamiSysWindows();

private:
    Ui::EiamiSysWindows *ui;
};
#endif // EIAMISYSWINDOWS_H
