#include <QMenu>
#include <QMessageBox>

#include "userloginform.h"
#include "ui_userloginform.h"
#include "../../_base/DBSetup.h"

UserLoginForm::UserLoginForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserLoginForm)
{
    ui->setupUi(this);

    /// 为方便登录
    ui->m_AccountLineEdit->setText("qm");
    ui->m_PasswordLineEdit->setText("qm");

    m_trayIcon = new QSystemTrayIcon(this);
    /// 设置图标
    m_trayIcon->setIcon(QIcon("../../../res/loginlogo.ico"));
    /// 设置鼠标放上去显示的信息
    m_trayIcon->setToolTip(tr("优视巡检登录"));
    /// 右键菜单
    QMenu *menu = new QMenu(this);

    /// 设置右键菜单
    m_trayIcon->setContextMenu(menu);
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));
    /// 显示
    m_trayIcon->show();
}

UserLoginForm::~UserLoginForm()
{
    delete ui;
}

/// 登录界面的登录按钮槽函数
void UserLoginForm::on_m_LoginBtn_clicked()
{

    QString input_Account = ui->m_AccountLineEdit->text().trimmed();
    QString input_Password = ui->m_PasswordLineEdit->text();

    if(input_Account == "" || input_Password == "")
    {
        QMessageBox::critical(this, " ", "账号和密码不能为空!", QMessageBox::Yes);
        return;
    }

    QString str_Query = QString("select from userlist where username = '%1' and password = '%2' ")
            .arg(input_Account).arg(input_Password);
    qx::QxSqlQuery query_User(str_Query);
    qx::dao::call_query(query_User);

    if(query_User.getSqlResultRowCount() > 0)
    {
        m_trayIcon->hide();

        // QThread::sleep(2);

        // ui->m_LoginBtn->setEnabled(0);
        // ui->m_LoginBtn->setText("登录中...");

        QDialog::accept();
        return;
    }
    else
    {
        QMessageBox::warning(this, " ", "用户不存在或密码错误!", QMessageBox::Yes);
    }
}

/// 退出按钮绑定的槽函数
void UserLoginForm::on_m_ExitBtn_clicked()
{
    QDialog::close();
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
