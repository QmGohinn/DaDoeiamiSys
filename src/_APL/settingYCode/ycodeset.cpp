#include "ycodeset.h"
#include "ui_ycodeset.h"

#include "src/_APL/main/eiamisyswindows.h"

Ycodeset::Ycodeset(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ycodeset)
{
    ui->setupUi(this);
}

Ycodeset::~Ycodeset()
{
    delete ui;
}


void Ycodeset::on_pushButton_2_clicked()
{
    EiamiSysWindows::getSysSetting()->hide();
}

void Ycodeset::on_pushButton_clicked()
{
    QMessageBox::information(this, "提示", "设置成功!", tr("确定"));
}
