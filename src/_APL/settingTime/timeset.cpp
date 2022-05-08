#include "timeset.h"
#include "ui_timeset.h"

#include "src/_APL/main/eiamisyswindows.h"
#include "src/_base/UVGlobal.h"

timeset::timeset(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::timeset)
{
    ui->setupUi(this);

    QRegExp regx("[1-9][0-9]");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit );
    ui->lineEdit->setValidator(validator);
    ui->lineEdit->setText("5");
    QValidator *validator_2 = new QRegExpValidator(regx, ui->lineEdit_2 );
    ui->lineEdit_2->setValidator(validator_2);
    ui->lineEdit_2->setText("5");
    QValidator *validator_3 = new QRegExpValidator(regx, ui->lineEdit_3 );
    ui->lineEdit_3->setValidator(validator_3);
    ui->lineEdit_3->setText("5");
}

timeset::~timeset()
{
    delete ui;
}


void timeset::on_pushButton_clicked()
{
    hideParTab(EiamiSysWindows::getSysSetting());
}

void timeset::hideParTab(QWidget *_wid)
{
    _wid->hide();
}

void timeset::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text().compare("")){
        UVGlobal::g_mainUI->setJDHeart(ui->lineEdit->text().toInt());
    }
    if(ui->lineEdit_2->text().compare("")){
        UVGlobal::g_mainUI->setLOGHeart(ui->lineEdit_2->text().toInt());
    }
    if(ui->lineEdit_3->text().compare("")){
        UVGlobal::g_mainUI->setZLHeart(ui->lineEdit_3->text().toInt());
    }
    QMessageBox::information(this, "提示", "设置成功!", tr("确定"));
}
