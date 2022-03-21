#include "eiamisyswindows.h"
#include "ui_eiamisyswindows.h"

#include "../../_base/UVGlobal.h"

#include <QTimer>

EiamiSysWindows::EiamiSysWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EiamiSysWindows)
{
    ui->setupUi(this);

    /// 窗口最大化
    this->setWindowState(Qt::WindowMaximized);

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    m_w1tab1Timer = new QTimer;
    connect(m_w1tab1Timer, SIGNAL(timeout()), this, SLOT(updatew1tab1Chart()));
    m_w1tab1Timer->start(1000);

    updateButtomTxt();
    m_buttomTxtTimer = new QTimer;
    connect(m_buttomTxtTimer, SIGNAL(timeout()), this, SLOT(updateButtomTxt()));
    m_buttomTxtTimer->start(12000);
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    /// 主界面时间主动刷新
    ui->m_TimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss ddd");
    ui->m_TimeEdit->setDateTime(QDateTime::currentDateTime());
    m_timeEditTimer = new QTimer;
    connect(m_timeEditTimer, SIGNAL(timeout()), this, SLOT(slotUpdateTime()));
    m_timeEditTimer->start(1000);
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    m_trayIcon = new QSystemTrayIcon(this);
    /// 设置图标
    m_trayIcon->setIcon(QIcon("../../../res/logo.png"));
    /// 设置鼠标放上去显示的信息
    m_trayIcon->setToolTip(tr("UVision"));
    /// 右键菜单                                      设置托盘栏程序图标
    QMenu *menu = new QMenu(this);
    /// 设置右键菜单
    m_trayIcon->setContextMenu(menu);
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(slotIconActivated(QSystemTrayIcon::ActivationReason)));
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //
}

EiamiSysWindows::~EiamiSysWindows()
{
    delete ui;
}

void EiamiSysWindows::closeEvent(QCloseEvent *e)
{
    if(0 == QMessageBox::information(this, "提示", "您确定退出优视巡检吗?", tr("确定"), tr("取消")))
    {
        e->accept();
    }
    else
    {
        e->ignore();
    }
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

void EiamiSysWindows::updatew1tab1Chart()
{
    static int num = 0;
    static int num2 = 100;

    m_w1tab1Chart = new QChart();

    QLineSeries* _lineSeries = new QLineSeries;
    *_lineSeries << QPointF(11, 9) << QPointF(12, --num2) << QPointF(17, 6) << QPointF(18, ++num) << QPointF(20, 2);

    m_w1tab1Chart->legend()->hide();
    m_w1tab1Chart->addSeries(_lineSeries);
    m_w1tab1Chart->createDefaultAxes();
    m_w1tab1Chart->setTitle("设备巡检总览");

    ui->m_w1tab1Chart->setChart(m_w1tab1Chart);
    ui->m_w1tab1Chart->setRenderHint(QPainter::Antialiasing);
}

void EiamiSysWindows::updateButtomTxt()
{
    int _mark = rand() % 5 + 1;
    ui->statusbar->showMessage(UVGlobal::g_mapIntQStr[_mark], 10000);
}
