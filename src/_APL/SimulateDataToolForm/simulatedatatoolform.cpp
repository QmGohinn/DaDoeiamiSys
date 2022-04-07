#include "simulatedatatoolform.h"
#include "ui_simulatedatatoolform.h"

SimulateDataToolForm::SimulateDataToolForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SimulateDataToolForm)
{
    ui->setupUi(this);
}

SimulateDataToolForm::~SimulateDataToolForm()
{
    delete ui;
}

