#include "eiamisyswindows.h"
#include "ui_eiamisyswindows.h"

EiamiSysWindows::EiamiSysWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EiamiSysWindows)
{
    ui->setupUi(this);

    m_trayIcon = new QSystemTrayIcon(this);
    //设置图标
    m_trayIcon->setIcon(QIcon("../../../res/applogo.ico"));
    //设置鼠标放上去显示的信息
    m_trayIcon->setToolTip(tr("UVision"));
    //右键菜单
    QMenu *menu = new QMenu(this);

    //设置右键菜单
    m_trayIcon->setContextMenu(menu);
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));
}

EiamiSysWindows::~EiamiSysWindows()
{
    delete ui;
}

void EiamiSysWindows::slotIconActivated(QSystemTrayIcon::ActivationReason reason)
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
