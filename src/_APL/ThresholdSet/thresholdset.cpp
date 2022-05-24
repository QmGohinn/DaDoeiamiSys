#include "thresholdset.h"
#include "ui_thresholdset.h"

#include "src/_APL/main/eiamisyswindows.h"
#include "src/_BK/LogEnt/LogEnt.h"
#include "src/_base/UVGlobal.h"

thresholdset::thresholdset(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::thresholdset)
{
    ui->setupUi(this);
}

thresholdset::~thresholdset()
{
    delete ui;
}


void thresholdset::on_pushButton_6_clicked()
{
    EiamiSysWindows::getSysSetting()->hide();
}

void thresholdset::on_pushButton_5_clicked()
{
    EiamiSysWindows::getSysSetting()->hide();
}

void thresholdset::on_pushButton_2_clicked()
{
    if(0 == UVGlobal::g_currentRole){
        QMessageBox::warning(this, "警告", "您当前权限不支持该操作!", "我知道了");
        return;
    }

    if(ui->textEdit->toPlainText().compare("")){
    LogEnt::Create(SysLog, ui->textEdit->toPlainText());
    ui->textEdit->clear();
    QMessageBox::information(this, "提示", "添加成功!", tr("确定"));
}}

void thresholdset::on_pushButton_3_clicked()
{
    if(0 == UVGlobal::g_currentRole){
        QMessageBox::warning(this, "警告", "您当前权限不支持该操作!", "我知道了");
        return;
    }

    if(ui->textEdit_2->toPlainText().compare("")){
    QLOG_INFO() << ui->textEdit_2->toPlainText();
    ui->textEdit_2->clear();
    QMessageBox::information(this, "提示", "添加成功!", tr("确定"));
}}

void thresholdset::on_pushButton_clicked()
{
    ui->textEdit->clear();
}

void thresholdset::on_pushButton_4_clicked()
{
    ui->textEdit_2->clear();
}
