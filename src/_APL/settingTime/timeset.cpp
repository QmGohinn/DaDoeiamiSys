#include "timeset.h"
#include "ui_timeset.h"

#include "src/_APL/main/eiamisyswindows.h"

timeset::timeset(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::timeset)
{
    ui->setupUi(this);
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
