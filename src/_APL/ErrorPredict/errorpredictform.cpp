#include "errorpredictform.h"
#include "ui_errorpredictform.h"

ErrorPredictForm::ErrorPredictForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ErrorPredictForm)
{
    ui->setupUi(this);

    ui->m_totalRadio->setChecked(true);
}

ErrorPredictForm::~ErrorPredictForm()
{
    delete ui;
}

