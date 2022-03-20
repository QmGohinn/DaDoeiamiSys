#ifndef EIAMISYSWINDOWS_H
#define EIAMISYSWINDOWS_H

#include <QMainWindow>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui { class EiamiSysWindows; }
QT_END_NAMESPACE

class EiamiSysWindows : public QMainWindow
{
    Q_OBJECT

public:
    EiamiSysWindows(QWidget *parent = nullptr);
    ~EiamiSysWindows();

    /// 托盘栏
    QSystemTrayIcon* m_trayIcon;

private:
    Ui::EiamiSysWindows *ui;

private slots:
    /// 托盘图标槽函数
    void slotIconActivated(QSystemTrayIcon::ActivationReason reason);
    /// 时间刷新函数
    void slotUpdateTime();
};
#endif // EIAMISYSWINDOWS_H
