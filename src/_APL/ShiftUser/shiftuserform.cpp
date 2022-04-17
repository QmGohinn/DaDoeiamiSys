#include "shiftuserform.h"
#include "ui_shiftuserform.h"

ShiftUserForm::ShiftUserForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShiftUserForm)
{
    ui->setupUi(this);
}

ShiftUserForm::~ShiftUserForm()
{
    delete ui;
}

