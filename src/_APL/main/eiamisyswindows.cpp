#include <QTimer>

#include "eiamisyswindows.h"
#include "ui_eiamisyswindows.h"

#include "../../_base/UVGlobal.h"
#include "../../_BK/TotalShow/TotalShow.h"

EiamiSysWindows::EiamiSysWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EiamiSysWindows)
{
    ui->setupUi(this);

    /// 窗口最大化
    this->setWindowState(Qt::WindowMaximized);

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    updatew1tab1Chart();
    m_w1tab1Timer = new QTimer;
    connect(m_w1tab1Timer, SIGNAL(timeout()), this, SLOT(updatew1tab1Chart()));
    m_w1tab1Timer->start(10000);

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
    m_trayIcon->setIcon(QIcon(":/res/tp/logo.png"));
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
        this->~EiamiSysWindows();
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
    UVGlobal::g_DATETIME = QDateTime::currentDateTime();
    ui->m_TimeEdit->setDateTime(UVGlobal::g_DATETIME);
}

void EiamiSysWindows::updateButtomTxt()
{
    int _mark = rand() % 5 + 1;
    ui->statusbar->showMessage(UVGlobal::g_mapIntQStr[_mark], 10000);
}

void EiamiSysWindows::updatew1tab1Chart()
{
    List_TotalShowEntPtr lst;
    qx::dao::fetch_all(lst);
    if(lst.size() <= 0){
        return;
    }

    int _maxNum = 0;

    /// DB data into charts
    QStringList _devTypeLst;
    QBarSet* _setTotalNum = new QBarSet("设备总数");
    QBarSet* _setReadNum = new QBarSet("已检设备数");
    QBarSet* _setQuestionNum = new QBarSet("风险设备数");
    QBarSet* _setErrorNum = new QBarSet("故障设备数");
///                                                                     循环获取到库里的模拟数据
    /// loop func to change data into charts
    for(const auto& loop_TotalInfo : lst){
        _devTypeLst << loop_TotalInfo.second.devType;
        (*_setTotalNum) << loop_TotalInfo.second.totalDevNum;
        (*_setReadNum) << loop_TotalInfo.second.realDevNum;
        (*_setQuestionNum) << loop_TotalInfo.second.questionDevNum;
        (*_setErrorNum) << loop_TotalInfo.second.errorDevNum;

        if(loop_TotalInfo.second.totalDevNum > _maxNum){
            _maxNum = loop_TotalInfo.second.totalDevNum;
        }
    }

/// - * - * - * - * - *- * - * - * -* - * -* - * -
///                                                                 设置实际图形
    QBarSeries* _series = new QBarSeries();
    _series->append(_setTotalNum);
    _series->append(_setReadNum);
    _series->append(_setQuestionNum);
    _series->append(_setErrorNum);

    _series->setBarWidth(0.65);
//    _series->setLabelsVisible(true);
    connect(_series, SIGNAL(hovered(bool, int, QBarSet*)), this, SLOT(sltTooltip(bool, int, QBarSet*)));
/// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

/// - * - * - * - * - *- * - * - * -* - * -* - * -
///                                                                 设置x坐标轴
    QBarCategoryAxis* _axis = new QBarCategoryAxis();
    _axis->append(_devTypeLst);
/// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

/// - * - * - * - * - *- * - * - * -* - * -* - * -
///                                                                 设置图表
    m_w1tab1Chart = new QChart();
    m_w1tab1Chart->addSeries(_series);
    m_w1tab1Chart->setTitle("各设备巡检进度");
    m_w1tab1Chart->setAnimationOptions(QChart::AllAnimations);
    m_w1tab1Chart->createDefaultAxes();
    m_w1tab1Chart->setAxisX(_axis);

    m_w1tab1Chart->axisY()->setRange(0, _maxNum + 18);
    m_w1tab1Chart->legend()->setVisible(true);
    m_w1tab1Chart->legend()->setAlignment(Qt::AlignBottom);

    ui->m_w1tab1Chart->setChart(m_w1tab1Chart);
/// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

}

void EiamiSysWindows::sltTooltip(bool status, int index, QBarSet *barset)
{
    //鼠标指向图表柱时提示数值文本
    QChart* pchart = ui->m_w1tab1Chart->chart();
    if(m_tooltip == nullptr)
    {
        /// 头文件中的定义
        /// 柱状体鼠标提示信息
        m_tooltip = new  QLabel(ui->m_w1tab1Chart);
        m_tooltip->setStyleSheet("background: rgba(95,166,250,185);color: rgb(248, 248, 255);"
                                 "border:0px groove gray;border-radius:10px;padding:2px 4px;"
                                 "border:2px groove gray;border-radius:10px;padding:2px 4px");
        m_tooltip->setVisible(false);
    }
    if (status)
    {
        double val = barset->at(index);
        QPointF point(index, barset->at(index));
        QPointF pointLabel = pchart->mapToPosition(point);
        QString sText = QString("%1台").arg(val);

        m_tooltip->setText(sText);
        m_tooltip->move(pointLabel.x(), pointLabel.y() - m_tooltip->height() * 1.5);
        m_tooltip->show();
    }
    else
    {
        m_tooltip->hide();
    }
}
