#ifndef USERLOGINFORM_H
#define USERLOGINFORM_H

#include <QDialog>
#include <QSystemTrayIcon>

#include "../../_base/UVThread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UserLoginForm; }
QT_END_NAMESPACE

class UserLoginForm : public QDialog
{
    Q_OBJECT

public:
    UserLoginForm(QWidget *parent = nullptr);
    ~UserLoginForm();

    /// 托盘图标
    QSystemTrayIcon* m_trayIcon;

    /// A new UVThread to show loading gif
    UVThread* m_thread;

private slots:
    /// 登录按钮绑定的槽函数
    void on_m_LoginBtn_clicked();
    /// 退出按钮绑定的槽函数
    void on_m_ExitBtn_clicked();
    /// 托盘图标槽函数
    void slotIconActivated(QSystemTrayIcon::ActivationReason reason);
    /// show loading gif
    void showLoadingGif();
    /// accept slot func
    void killAndAccept();
private:
    Ui::UserLoginForm *ui;
};
#endif // USERLOGINFORM_H
