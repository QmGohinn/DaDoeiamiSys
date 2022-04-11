#include "kindofdevlogform.h"
#include "ui_kindofdevlogform.h"

KindOfDevLogForm::KindOfDevLogForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KindOfDevLogForm)
{
    ui->setupUi(this);
    ui->m_dateTime->setDate(QDate::currentDate());
}

KindOfDevLogForm::~KindOfDevLogForm()
{
    delete ui;
}

void KindOfDevLogForm::on_m_clearButton_clicked()
{
    ui->m_comboBox->hidePopup();
    ui->m_comboBox->setCurrentIndex(0);
    ui->m_numLineEdit->clear();
    ui->m_dateTime->setDate(QDate::currentDate());
}
