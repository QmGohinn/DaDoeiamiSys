#include <QMenu>
#include <QMessageBox>
#include <QMovie>
#include <QPixmap>
#include <QThread>
#include <QTimer>

#include "userloginform.h"
#include "ui_userloginform.h"
#include <src/_APL/regiuser/regiuserform.h>

#include <src/_base/DBSetup.h>
#include <src/_base/UVGlobal.h>

#include <src/_BK/AccountEnt/AccountEnt.h>
#include <src/_BK/LogEnt/LogEnt.h>

UserLoginForm::UserLoginForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserLoginForm)
{
    ui->setupUi(this);
    this->activateWindow();
    this->setWindowIcon(QIcon(":/res/windows/people.ico"));

    /// init regiUserForm
    m_regiUserForm = new RegiUserForm(this);

    /// all new action
    m_thread = new UVThread;

    /// all connect action
    connect(m_thread, SIGNAL(UVThreadRun()), this, SLOT(showLoadingGif()));

    /// 设置三个按钮悬停时小手指针
    ui->m_LoginBtn->setCursor(QCursor(Qt::PointingHandCursor));
    ui->m_ExitBtn->setCursor(QCursor(Qt::PointingHandCursor));
    ui->m_RegisterBtn->setCursor(QCursor(Qt::PointingHandCursor));

    /// 为方便登录 预先设置好账号密码
    ui->m_AccountLineEdit->setText("wubin");
    ui->m_PasswordLineEdit->setText("221376");

    /// 设置登录界面的LabelLogo
    ui->m_LogoLabel->setPixmap(QPixmap(":/res/loading.png").scaled(243,149));

/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    m_trayIcon = new QSystemTrayIcon(this);
    /// 设置图标
    m_trayIcon->setIcon(QIcon(":/res/tp/exeunlogo.jpg"));
    /// 设置鼠标放上去显示的信息
    m_trayIcon->setToolTip(tr("优视巡检登录"));
    /// 右键菜单                                            设置托盘栏图标
    QMenu *menu = new QMenu(this);
    /// 设置右键菜单
    m_trayIcon->setContextMenu(menu);
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));
    /// 显示
    m_trayIcon->show();
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
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
        QMessageBox::critical(this, "提示", "账号和密码不能为空!", tr("确定"));
        return;
    }

    QString str_Query = QString("select from userlist where username = '%1' and password = '%2' ")
            .arg(input_Account).arg(input_Password);
    qx::QxSqlQuery query_User(str_Query);
    qx::dao::call_query(query_User);

    if(query_User.getSqlResultRowCount() > 0)
    {
        qx::QxSqlQuery _tmpQuery(QString("where username = '%1' and password = '%2'")
                                 .arg(input_Account).arg(input_Password));
        List_UserEnt _tmpUserLst;
        qx::dao::fetch_by_query(_tmpQuery, _tmpUserLst);
        UVGlobal::g_currentRole = _tmpUserLst.begin()->second->role;
        UVGlobal::g_userName = input_Account;
        UVGlobal::g_passWord = input_Password;

        m_thread->start();
        QTimer::singleShot(rand() % 2000 + 1800, this, SLOT(killAndAccept()));
    }
    else
    {
        QMessageBox::warning(this, "提示", "用户不存在或密码错误!", tr("确定"));
    }
}

/// 退出按钮绑定的槽函数
void UserLoginForm::on_m_ExitBtn_clicked()
{
    m_trayIcon->hide();
    QDialog::close();
}

/// 托盘图标的槽函数 （目前是点击托盘程序时，会置顶显示窗口）
void UserLoginForm::slotIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    /// 双击
    case QSystemTrayIcon::DoubleClick:
    /// 单击
    case QSystemTrayIcon::Trigger :
        setWindowState(Qt::WindowActive);
        activateWindow();
        break;
    default:
        break;
    }
}

void UserLoginForm::showLoadingGif()
{
    ui->m_LoginBtn->setEnabled(false);
    ui->m_RegisterBtn->setEnabled(false);
    ui->m_AccountLineEdit->setEnabled(false);
    ui->m_PasswordLineEdit->setEnabled(false);

    QMovie* _movie = new QMovie(":/res/gif/loading.gif");
    ui->m_LogoLabel->setMovie(_movie);
    _movie->start();
}

void UserLoginForm::killAndAccept()
{
    m_thread->~UVThread();
    this->hide();
    m_trayIcon->hide();

//    LogEnt::Create(SysLog, "登录 UVision 客户端");

    QDialog::accept();
}

void UserLoginForm::on_m_RegisterBtn_clicked()
{
    UVGlobal::_adminFlg = false;
    m_regiUserForm->exec();
}

void UserLoginForm::closeEvent(QCloseEvent *e)
{
    Q_UNUSED(e)
    m_trayIcon->hide();
}
