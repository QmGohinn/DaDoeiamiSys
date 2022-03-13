#include "userloginform.h"
#include "ui_userloginform.h"

UserLoginForm::UserLoginForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::UserLoginForm)
{
    ui->setupUi(this);
}

UserLoginForm::~UserLoginForm()
{
    delete ui;
}

