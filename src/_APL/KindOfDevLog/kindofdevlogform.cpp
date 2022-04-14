#include "kindofdevlogform.h"
#include "ui_kindofdevlogform.h"

#include <QMessageBox>
#include <src/_BK/InspectorEnt/InspectorEnt.h>

KindOfDevLogForm::KindOfDevLogForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::KindOfDevLogForm)
{
    ui->setupUi(this);

    ui->m_devTable->horizontalHeader()->hide();
    ui->m_devTable->setColumnWidth(0, 150);
    ui->m_devTable->setColumnWidth(1, 150);
    ui->m_devTable->setColumnWidth(2, 180);
//    ui->m_devTable->setColumnWidth(3, 300);
    ui->m_devTable->setColumnHidden(4, true);

    ui->m_msgLineEdit->hide();
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

    while(ui->m_devTable->rowCount() != 0){
        ui->m_devTable->removeRow(0);
    }
    ui->m_devTable->horizontalHeader()->hide();
    ui->m_msgLineEdit->hide();
}

void KindOfDevLogForm::on_m_findButton_clicked()
{
    ui->m_msgLineEdit->hide();

    if(ui->m_numLineEdit->text().isEmpty()){
        QMessageBox::information(this, "提示", "定向筛选之前请输入设备编号!", tr("确定"));
        return;
    }

    qx_query _query(QString("select * from inspecorbaseinfo where LOWER(devserial) = LOWER('%1') order by updated_at DESC")
                    .arg(ui->m_numLineEdit->text()));
    List_InspecorEnt lst;

    qx::dao::execute_query(_query, lst);

    while(ui->m_devTable->rowCount() != 0){
        ui->m_devTable->removeRow(0);
    }

    ui->m_devTable->horizontalHeader()->show();

    int _res = 0;
    switch (ui->m_comboBox->currentIndex()) {
    case 0:
        _res = 5;
        break;
    case 1:
        _res = 1;
        break;
    case 2:
        _res = -1;
        break;
    case 3:
        _res = -2;
        break;
    case 4:
        _res = -3;
        break;
    case 5:
        _res = 0;
        break;
    }

    int i = 0;
    for(const auto& _p : lst){

        if(_res != 5){
            if(_p.second.m_res != _res){
                continue;
            }
        }

        ui->m_devTable->insertRow(i);

        ui->m_devTable->setItem(i, 0, new QTableWidgetItem(_p.second.m_devSerial));
        if(_p.second.m_devSerial.startsWith("GL")){
            ui->m_devTable->setItem(i, 1, new QTableWidgetItem("锅炉"));
        }
        if(_p.second.m_devSerial.startsWith("QJ")){
            ui->m_devTable->setItem(i, 1, new QTableWidgetItem("汽机"));
        }
        if(_p.second.m_devSerial.startsWith("PD")){
            ui->m_devTable->setItem(i, 1, new QTableWidgetItem("输煤皮带"));
        }
        if(_p.second.m_devSerial.startsWith("GD")){
            ui->m_devTable->setItem(i, 1, new QTableWidgetItem("高压管道"));
        }
        if(_p.second.m_devSerial.startsWith("BY")){
            ui->m_devTable->setItem(i, 1, new QTableWidgetItem("变压器"));
        }

        switch (_p.second.m_res) {
        case 1:
            ui->m_devTable->setItem(i, 2, new QTableWidgetItem("正常"));
            ui->m_devTable->item(i, 2)->setForeground(Qt::blue);
            break;
        case 0:
            ui->m_devTable->setItem(i, 2, new QTableWidgetItem("故障停工"));
            ui->m_devTable->item(i, 2)->setForeground(Qt::gray);
            break;
        case -1:
            ui->m_devTable->setItem(i, 2, new QTableWidgetItem("一级风险"));
            ui->m_devTable->item(i, 2)->setForeground(Qt::red);
            break;
        case -2:
            ui->m_devTable->setItem(i, 2, new QTableWidgetItem("二级风险"));
            ui->m_devTable->item(i, 2)->setForeground(Qt::red);
            break;
        case -3:
            ui->m_devTable->setItem(i, 2, new QTableWidgetItem("三级风险"));
            ui->m_devTable->item(i, 2)->setForeground(Qt::red);
            break;
        }

        ui->m_devTable->setItem(i, 3, new QTableWidgetItem(_p.second.updatedAt.toString("yyyy-MM-dd hh:mm:ss ddd")));
        ui->m_devTable->setItem(i, 4, new QTableWidgetItem(QString("%1").arg(_p.second.id)));
        ++i;
    }

}

void KindOfDevLogForm::on_m_devTable_itemClicked(QTableWidgetItem *item)
{
    InspecorEntPtr _p;
    _p.reset(new InspecorEnt());

    qx::QxSqlQuery _query(QString("where id = '%1'")
                          .arg(ui->m_devTable->item(item->row(), 4)->text().toInt()));
    qx::dao::fetch_by_query(_query, _p);

    ui->m_msgLineEdit->show();

    switch (item->column()) {
    case 0:
    case 1:
        ui->m_msgLineEdit->hide();
        break;
    case 2:
    case 3:
        ui->m_msgLineEdit->setText(QString("检员姓名:%1,检员电话:%2.").arg(_p->m_name).arg(_p->m_phone));
        break;
    }
}
