#include "eiamisyswindows.h"
#include "ui_eiamisyswindows.h"

EiamiSysWindows::EiamiSysWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EiamiSysWindows)
{
    ui->setupUi(this);
}

EiamiSysWindows::~EiamiSysWindows()
{
    delete ui;
}

