#include <QTimer>

#include "eiamisyswindows.h"
#include "ui_eiamisyswindows.h"

#include <src/_APL/regiuser/regiuserform.h>
#include <src/_APL/SimulateDataToolForm/simulatedatatoolform.h>
#include <src/_APL/ErrorPredict/errorpredictform.h>
#include <src/_APL/KindOfDevLog/kindofdevlogform.h>

#include <src/_base/UVGlobal.h>
#include <src/_BK/TotalShow/TotalShow.h>

#include <src/_BK/LogEnt/LogEnt.h>

#include <src/_BK/BeltEnt/BeltEnt.h>
#include <src/_BK/BoilerEnt/BoilerEnt.h>
#include <src/_BK/InspectorEnt/InspectorEnt.h>
#include <src/_BK/MotorEnt/MotorEnt.h>
#include <src/_BK/PipelineEnt/PipelineEnt.h>
#include <src/_BK/TransformerEnt/TransformerEnt.h>

EiamiSysWindows::EiamiSysWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EiamiSysWindows)
{
/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    ui->setupUi(this);
    /// 窗口最大化
    this->setWindowState(Qt::WindowMaximized);
    this->show();
    this->raise();
    this->activateWindow();
//    this->setWindowFlag(Qt::FramelessWindowHint);
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    m_tabKindDevLog = new KindOfDevLogForm;
    ui->m_TabVec3->insertTab(0, m_tabKindDevLog, tr("定向巡检记录"));

    m_tabErrorPre = new ErrorPredictForm;
    ui->m_TabVec3->insertTab(1, m_tabErrorPre, tr("故障预测"));
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
    /// 设备信息总览
    ui->m_devTotal->horizontalHeader()->show();
    ui->m_devTotal->setColumnWidth(0, 130);
    ui->m_devTotal->setColumnWidth(1, 130);
    ui->m_devTotal->setColumnWidth(2, 130);
    ui->m_devTotal->setColumnWidth(3, 200);
//    ui->m_devTotal->setColumnWidth(4, 285);
    ui->m_devTotal->hideColumn(5);
    ui->m_peopleInfoEdit->hide();
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //

/// -▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼-▼ //
/// 日志窗口初始化操作
    ui->m_logTable->verticalHeader()->setHidden(true);
    ui->m_logTable->hideColumn(2);
    ui->m_mmsgLineEdit->hide();
    ui->m_logTable->setColumnWidth(0, 320);
//    ui->m_logTable->setColumnWidth(1, 320);
/// -▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲-▲ //

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

    updateLogTable();
    m_logTableTimer = new QTimer;
    connect(m_logTableTimer, SIGNAL(timeout()), this, SLOT(updateLogTable()));
    m_logTableTimer->start(1000);

    updateDevTotal();
    m_devTotalTimer = new QTimer;
    connect(m_devTotalTimer, SIGNAL(timeout()), this, SLOT(updateDevTotal()));
//    m_devTotalTimer->start(1000);
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
    m_trayIcon->setIcon(QIcon(":/res/tp/exelogo.ico"));
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
        QLOG_INFO() << "    退出系统";
//        LogEnt::Create(SysLog, "退出优视客户端");
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
    if(lst.size() < 0){
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
    m_w1tab1Chart->setTitle("设备巡检进度");
    m_w1tab1Chart->setTitleFont(QFont("宋体", 10));
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
        m_tooltip = new QLabel(ui->m_w1tab1Chart);
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

void EiamiSysWindows::updateLogTable()
{
    int _currrentLogNum = qx::dao::count<LogEnt>();
    if(_currrentLogNum == UVGlobal::g_logNum){
        return;
    }

    UVGlobal::g_logNum = _currrentLogNum;

    List_LogEnt _logLst;
    qx::QxSqlQuery _query(QString("order by created_at DESC limit 300"));

    qx::dao::fetch_by_query(_query, _logLst);

//    ui->m_logTable->clear();

    while(ui->m_logTable->rowCount() != 0){
        ui->m_logTable->removeRow(0);
    }

    int i = 0;
    for(const auto& loop_Log : _logLst)
    {
        ui->m_logTable->insertRow(i);

        ui->m_logTable->setItem(i, 0, new QTableWidgetItem(loop_Log.second->createdAt.toString("yyyy-MM-dd hh:mm:ss ddd")));
        ui->m_logTable->setItem(i, 1, new QTableWidgetItem(loop_Log.second->m_msg));
        ui->m_logTable->setItem(i, 2, new QTableWidgetItem(QString("%1").arg(loop_Log.second->id)));
        ++i;
    }
}

void EiamiSysWindows::on_m_logTable_itemClicked(QTableWidgetItem *item)
{
    LogEntPtr _tmpLogEntPtr;
    _tmpLogEntPtr.reset(new LogEnt());

    qx::QxSqlQuery _query(QString("where id = '%1'")
                          .arg(ui->m_logTable->item(item->row(), 2)->text().toInt()));
    qx::dao::fetch_by_query(_query, _tmpLogEntPtr);

    ui->m_mmsgLineEdit->show();

    if(item->column() == 0){
        ui->m_mmsgLineEdit->hide();
    }
    else{
        if(_tmpLogEntPtr->m_mmsg == ""){
            ui->m_mmsgLineEdit->setText("无更多明细内容!");
        }
        else{
            ui->m_mmsgLineEdit->setText(_tmpLogEntPtr->m_mmsg);
        }
    }
}

void EiamiSysWindows::on_action_adduser_triggered()
{
    if(_pRegi == nullptr){
        _pRegi = new RegiUserForm;
    }

    _pRegi->show();
    _pRegi->raise();
    _pRegi->activateWindow();
}

void EiamiSysWindows::on_action_exit_triggered()
{
    if(0 == QMessageBox::information(this, "提示", "您确定退出优视巡检吗?", tr("确定"), tr("取消")))
    {
        this->~EiamiSysWindows();
        QLOG_INFO() << "    退出系统";
    }
    else
    {
        ;;
    }
}

void EiamiSysWindows::on_action_help_triggered()
{
    QMessageBox::information(this, "提示", "帮助文档请等待吴斌后续接入!", tr("确定"));
}

void EiamiSysWindows::on_action_simulatedata_triggered()
{
    if(UVGlobal::g_currentRole != 1){
        QMessageBox::warning(this, "说明", "该工具仅限管理员使用,请联系管理员进行权限升级!", tr("确定"));
        return;
    }
    else{
        if(m_toolForm == nullptr){
            m_toolForm = new SimulateDataToolForm;
        }
        m_toolForm->show();
        m_toolForm->raise();
        m_toolForm->activateWindow();
    }
}

void EiamiSysWindows::on_action_refreshTotal_triggered()
{
    updatew1tab1Chart();
}

void EiamiSysWindows::on_action_refreshLog_triggered()
{
    updateLogTable();
}

void EiamiSysWindows::on_action_about_triggered()
{
    QDesktopServices::openUrl(QUrl("https://github.com/QmGohinn/DaDoeiamiSys"));
}

void EiamiSysWindows::updateDevTotal()
{
    while(ui->m_devTotal->rowCount() != 0){
        ui->m_devTotal->removeRow(0);
    }

    qx_query _query("select DISTINCT ON(devserial) * from inspecorbaseinfo order by devserial DESC");
    List_InspecorEnt lst;

    qx::dao::execute_query(_query, lst);
    int i = 0;
    for(const auto& _p : lst){

        ui->m_devTotal->insertRow(i);

        ui->m_devTotal->setItem(i, 0, new QTableWidgetItem(_p.second.m_devSerial));
        if(_p.second.m_devSerial.startsWith("GL")){
            ui->m_devTotal->setItem(i, 1, new QTableWidgetItem("锅炉"));
        }
        if(_p.second.m_devSerial.startsWith("QJ")){
            ui->m_devTotal->setItem(i, 1, new QTableWidgetItem("汽机"));
        }
        if(_p.second.m_devSerial.startsWith("PD")){
            ui->m_devTotal->setItem(i, 1, new QTableWidgetItem("输煤皮带"));
        }
        if(_p.second.m_devSerial.startsWith("GD")){
            ui->m_devTotal->setItem(i, 1, new QTableWidgetItem("高压管道"));
        }
        if(_p.second.m_devSerial.startsWith("BY")){
            ui->m_devTotal->setItem(i, 1, new QTableWidgetItem("变压器"));
        }

        ui->m_devTotal->setItem(i, 2, new QTableWidgetItem("未知地点"));

        switch (_p.second.m_res) {
        case 1:
            ui->m_devTotal->setItem(i, 3, new QTableWidgetItem("正常"));
            break;
        case 0:
            ui->m_devTotal->setItem(i, 3, new QTableWidgetItem("故障停工"));
            break;
        case -1:
            ui->m_devTotal->setItem(i, 3, new QTableWidgetItem("一级风险"));
            break;
        case -2:
            ui->m_devTotal->setItem(i, 3, new QTableWidgetItem("二级风险"));
            break;
        case -3:
            ui->m_devTotal->setItem(i, 3, new QTableWidgetItem("三级风险"));
            break;
        }

        ui->m_devTotal->setItem(i, 4, new QTableWidgetItem(_p.second.updatedAt.toString("yyyy-MM-dd hh:mm:ss ddd")));
        ui->m_devTotal->setItem(i, 5, new QTableWidgetItem(QString("%1").arg(_p.second.id)));
        ++i;
    }

}

void EiamiSysWindows::on_m_TabVec3_tabCloseRequested(int index)
{
    ui->m_TabVec3->removeTab(index);
}

void EiamiSysWindows::on_actionBug_U_triggered()
{
     QDesktopServices::openUrl(QUrl("https://github.com/QmGohinn/DaDoeiamiSys/issues"));
}

void EiamiSysWindows::on_action_R_triggered()
{
    QDesktopServices::openUrl(QUrl("https://mail.google.com/mail/u/0/#inbox?compose=CllgCJTJFflLdkbqnRbhNhHHzjVkzSDpkRtLPjpDffqzmrBxNLrzszKvvCJJhhxsFsJwZlcmrXV"));
}

void EiamiSysWindows::on_m_devTotal_itemClicked(QTableWidgetItem *item)
{
    InspecorEntPtr _p;
    _p.reset(new InspecorEnt());

    qx::QxSqlQuery _query(QString("where id = '%1'")
                          .arg(ui->m_devTotal->item(item->row(), 5)->text().toInt()));
    qx::dao::fetch_by_query(_query, _p);

    ui->m_peopleInfoEdit->show();

    switch (item->column()) {
    case 0:
    case 1:
    case 3:
        ui->m_peopleInfoEdit->hide();
        break;
    case 2:
        ui->m_peopleInfoEdit->setText("设备具体地点暂未接入该版本优视,点击特性请求或尝试更新!");
        break;
    case 4:
        ui->m_peopleInfoEdit->setText(QString("检员姓名:%1,检员电话:%2.").arg(_p->m_name).arg(_p->m_phone));
        break;
    }
}
