#ifndef EIAMISYSWINDOWS_H
#define EIAMISYSWINDOWS_H

#include <QMainWindow>
#include <QSystemTrayIcon>

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

    void closeEvent(QCloseEvent* e);

    QLabel* m_tooltip = nullptr;
    /// 托盘栏
    QSystemTrayIcon* m_trayIcon;

    /// 时间更新定时器
    QTimer* m_timeEditTimer;

    /// 日志表更新定时器
    QTimer* m_logTableTimer;

    /// 介绍文字定时器
    QTimer* m_buttomTxtTimer;

    /// 图表 1
    QChart* m_w1tab1Chart;
    QTimer* m_w1tab1Timer;

    /// 图表 2
    QChart* m_w1tab2Chart;
    QTimer* m_w1tab2Timer;

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
    /// 鼠标悬停函数
    void sltTooltip(bool status, int index, QBarSet *barset);
    /// 日志表更新函数
    void updateLogTable();
    /// LogTable update Func
    void on_m_logTable_itemClicked(QTableWidgetItem *item);
};
#endif // EIAMISYSWINDOWS_H
