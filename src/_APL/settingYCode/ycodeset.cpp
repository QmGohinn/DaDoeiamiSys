#include "ycodeset.h"
#include "ui_ycodeset.h"

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

