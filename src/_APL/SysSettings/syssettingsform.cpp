#include "syssettingsform.h"
#include "ui_syssettingsform.h"

SysSettingsForm::SysSettingsForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SysSettingsForm)
{
    ui->setupUi(this);
}

SysSettingsForm::~SysSettingsForm()
{
    delete ui;
}

