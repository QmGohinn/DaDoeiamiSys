/**
 *  主界面头文件
 *  继承自QMainWindows
 */

#ifndef EIAMISYSWINDOWS_H
#define EIAMISYSWINDOWS_H

#include <QMainWindow>
#include <QSystemTrayIcon>

#include <src/_APL/SimulateDataToolForm/simulatedatatoolform.h>
#include <src/_APL/regiuser/regiuserform.h>
#include <src/_APL/ErrorPredict/errorpredictform.h>
#include <src/_APL/KindOfDevLog/kindofdevlogform.h>
#include <src/_APL/ChangePWD/changepwdform.h>
#include <src/_APL/SelfCenter/selfcenterform.h>
#include <src/_APL/ShiftUser/shiftuserform.h>
#include <src/_APL/SysSettings/syssettingsform.h>

/// dynamic charts module
#include <QtCharts>
#include <QtCharts/QChartGlobal>
QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class EiamiSysWindows; }
QT_END_NAMESPACE

class EiamiSysWindows : public QMainWindow
{
    Q_OBJECT

public:
    EiamiSysWindows(QWidget *parent = nullptr);
    ~EiamiSysWindows();

    void setJDHeart(const int& _m);
    void setZLHeart(const int& _m);
    void setLOGHeart(const int& _m);

    void closeEvent(QCloseEvent* e);

    /// 系统设置Dialog
    SysSettingsForm* m_sysSetting = nullptr;
    static SysSettingsForm* m_return;
    static SysSettingsForm* getSysSetting(){
        return m_return;
    }

    /// 切换用户Dialog
    ShiftUserForm* m_shiftUser = nullptr;

    /// 个人中心Dialog
    SelfCenterForm* m_selfCenterForm = nullptr;

    /// 修改密码Dialog
    ChangePWDForm* m_changePWdForm = nullptr;

    /// 设备分类记录
    KindOfDevLogForm* m_tabKindDevLog = nullptr;

    /// 故障预测Tab
    ErrorPredictForm* m_tabErrorPre = nullptr;

    /// 设备信息总览定时器
    QTimer* m_devTotalTimer = nullptr;

    /// 工具窗口
    SimulateDataToolForm* m_toolForm = nullptr;

    /// 用户注册窗口
    RegiUserForm* _pRegi = nullptr;

    /// 鼠标悬停时显示设备数
    QLabel* m_tooltip = nullptr;
    /// 托盘栏
    QSystemTrayIcon* m_trayIcon = nullptr;

    /// 时间更新定时器
    QTimer* m_timeEditTimer = nullptr;

    /// 日志表更新定时器
    QTimer* m_logTableTimer = nullptr;

    /// 介绍文字定时器
    QTimer* m_buttomTxtTimer = nullptr;

    /// 设备进度总览图
    QChart* m_w1tab1Chart = nullptr;
    QTimer* m_w1tab1Timer = nullptr;

private:
    Ui::EiamiSysWindows *ui;

private slots:
    /// 托盘图标槽函数
    void slotIconActivated(QSystemTrayIcon::ActivationReason reason);
    /// 时间刷新函数
    void slotUpdateTime();
    /// 介绍文字刷新定时器
    void updateButtomTxt();
    /// 更新图表
    void updatew1tab1Chart();
    /// 更新设备信息总览
    void updateDevTotal();
    /// 鼠标悬停函数
    void sltTooltip(bool status, int index, QBarSet *barset);
    /// 日志表更新函数
    void updateLogTable();
    /// LogTable update Func
    void on_m_logTable_itemClicked(QTableWidgetItem *item);

    void on_action_adduser_triggered();
    void on_action_exit_triggered();
    void on_action_help_triggered();
    void on_action_simulatedata_triggered();
    void on_action_refreshTotal_triggered();
    void on_action_refreshLog_triggered();
    void on_action_about_triggered();
    void on_m_TabVec3_tabCloseRequested(int index);
    void on_actionBug_U_triggered();
    void on_action_R_triggered();
    void on_m_devTotal_itemClicked(QTableWidgetItem *item);
    void on_action_changePWD_triggered();
    void on_action_self_triggered();
    void on_action_shiftUser_triggered();
    void on_action_sysSetUp_triggered();
    void on_pushButton_6_clicked();

    void _action1Slot();
    void _action2Slot();
    void _action3Slot();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_action_addRole_triggered();
    void on_action_opensysLog_triggered();
    void on_comboBox_2_currentIndexChanged(int index);
    void on_comboBox_currentIndexChanged(int index);
};
#endif // EIAMISYSWINDOWS_H
