#include "syssettingsform.h"
#include "ui_syssettingsform.h"

SysSettingsForm::SysSettingsForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SysSettingsForm)
{
    ui->setupUi(this);

    m_timeSet = new timeset;
    ui->m_tabWidget->insertTab(0, m_timeSet, tr("时间设置"));

    m_ycodeSet = new Ycodeset;
    ui->m_tabWidget->insertTab(1, m_ycodeSet, tr("预测属性"));

    m_thresholdset = new thresholdset;
    ui->m_tabWidget->insertTab(2, m_thresholdset, tr("阈值设定"));

}

SysSettingsForm::~SysSettingsForm()
{
    delete ui;
}

