#include "selfcenterform.h"
#include "ui_selfcenterform.h"

SelfCenterForm::SelfCenterForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SelfCenterForm)
{
    ui->setupUi(this);
}

SelfCenterForm::~SelfCenterForm()
{
    delete ui;
}

