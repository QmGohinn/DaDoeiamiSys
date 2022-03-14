#include "userloginform.h"
#include "ui_userloginform.h"

#include <QMenu>

UserLoginForm::UserLoginForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserLoginForm)
{
    ui->setupUi(this);

    m_trayIcon = new QSystemTrayIcon(this);
    //设置图标
    m_trayIcon->setIcon(QIcon("../../../res/loginlogo.ico"));
    //设置鼠标放上去显示的信息
    m_trayIcon->setToolTip(tr("优视巡检登录"));
    //右键菜单
    QMenu *menu = new QMenu(this);

    //设置右键菜单
    m_trayIcon->setContextMenu(menu);
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));
    //显示
    m_trayIcon->show();
}

UserLoginForm::~UserLoginForm()
{
    delete ui;
}

/// 登录界面的登录按钮槽函数
void UserLoginForm::on_m_LoginBtn_clicked()
{
    m_trayIcon->hide();

//   QThread::sleep(2);
   QDialog::accept();
}

/// 退出按钮绑定的槽函数
void UserLoginForm::on_m_ExitBtn_clicked()
{
    exit(0);
}

void UserLoginForm::slotIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    case QSystemTrayIcon::Trigger :
        setWindowState(Qt::WindowActive);
        activateWindow();
        break;
    default:
        break;
    }
}
