#include "eiamisyswindows.h"
#include "ui_eiamisyswindows.h"

#include <QTimer>

EiamiSysWindows::EiamiSysWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EiamiSysWindows)
{
    ui->setupUi(this);

    /// 窗口最大化
    this->setWindowState(Qt::WindowMaximized);
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    /// 主界面时间主动刷新
    ui->m_TimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    ui->m_TimeEdit->setDateTime(QDateTime::currentDateTime());
    QTimer* _timer_timeEdit = new QTimer;
    connect(_timer_timeEdit, SIGNAL(timeout()), this, SLOT(slotUpdateTime()));
    _timer_timeEdit->start(1000);
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //

/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
    m_trayIcon = new QSystemTrayIcon(this);
    /// 设置图标
    m_trayIcon->setIcon(QIcon("../../../res/applogo.ico"));
    /// 设置鼠标放上去显示的信息
    m_trayIcon->setToolTip(tr("UVision"));
    /// 右键菜单                                      设置托盘栏程序图标
    QMenu *menu = new QMenu(this);
    /// 设置右键菜单
    m_trayIcon->setContextMenu(menu);
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
/// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //
}

EiamiSysWindows::~EiamiSysWindows()
{
    delete ui;
}

void EiamiSysWindows::slotIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason)
    {
    /// 单击
    case QSystemTrayIcon::Trigger:
    /// 双击
    case QSystemTrayIcon::DoubleClick:
        setWindowState(Qt::WindowActive);
        activateWindow();
        showMaximized();
        break;
    default:
        break;
    }
}

void EiamiSysWindows::slotUpdateTime()
{
    ui->m_TimeEdit->setDateTime(QDateTime::currentDateTime());
}
