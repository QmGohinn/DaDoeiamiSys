#include "thresholdset.h"
#include "ui_thresholdset.h"

thresholdset::thresholdset(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::thresholdset)
{
    ui->setupUi(this);
}

thresholdset::~thresholdset()
{
    delete ui;
}

