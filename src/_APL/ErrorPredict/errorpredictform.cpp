#include "errorpredictform.h"
#include "ui_errorpredictform.h"

ErrorPredictForm::ErrorPredictForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ErrorPredictForm)
{
    ui->setupUi(this);
}

ErrorPredictForm::~ErrorPredictForm()
{
    delete ui;
}

