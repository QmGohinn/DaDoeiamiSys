#include "errorpredictform.h"
#include "ui_errorpredictform.h"

#include <QMap>
#include <QPair>
#include <QMessageBox>

#include <src/_BK/BoilerEnt/BoilerEnt.h>
#include <src/_BK/BeltEnt/BeltEnt.h>

#include <src/_base/UVGlobal.h>

QVector<QString> ErrorPredictForm::m_devSerial;
QMap<QString, QPair<QPair<QString, QString>, QPair<QString, QString>>> ErrorPredictForm::m_predictRes;

ErrorPredictForm::ErrorPredictForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ErrorPredictForm)
{
    ui->setupUi(this);

    ui->m_totalRadio->setChecked(true);
    ui->m_devTable->horizontalHeader()->show();
    ErrorPredictForm::m_devSerial.clear();
    ErrorPredictForm::m_predictRes.clear();

    ui->m_devTable->horizontalHeader()->hide();
}

ErrorPredictForm::~ErrorPredictForm()
{
    delete ui;
}

void ErrorPredictForm::getPredictByInputSerial()
{
    if(!ErrorPredictForm::m_devSerial.size()){
        return;
    }

    ErrorPredictForm::m_predictRes.clear();

    for(const auto& _devStr : ErrorPredictForm::m_devSerial){

        qx_query _query(QString("select * from inspecorbaseinfo "
                                "where LOWER(devserial) = LOWER('%1') "
                                "order by updated_at DESC")
                        .arg(_devStr));

        List_InspecorEnt lst;
        lst.clear();
        qx::dao::execute_query(_query, lst);

        if(!lst.size()){
            QMessageBox::information(this, "提示", "该设备编号不存在或该设备还未进行巡检!", tr("确定"));
            return;
        }

        int _num = lst.size() < 10 ? lst.size() : 10;

        if(lst.size() > 3){
            if(lst.getByIndex(2).m_res == 0){
                if(lst.getByIndex(1).m_res == 0){
                    if(lst.getByIndex(0).m_res == 0){
                        this->insertRes(_devStr, "故障停工", "82.5%", "正常运行", "17.5%"); continue;
                    }
                    else{
                        this->insertRes(_devStr, UVGlobal::gFunc_PatrolRes2Str(lst.getByIndex(0).m_res), "99%", "", ""); continue;
                    }
                }
            }
        }

        int _totalRes = 0;
        for(int i = 0; i < _num; i++){
            _totalRes += lst.getByIndex(i).m_res;
        }

        int _averageRes = _totalRes / _num;
        switch (_averageRes) {
        case 1:
            this->insertRes(_devStr, "正常运行", "98.8%", "Ⅰ级风险", "1.2%");
            break;
        case 0:
            this->insertRes(_devStr, "正常运行", "86.2%", "Ⅰ级或Ⅱ级风险", "13.7%");
            break;
        case -1:
            this->insertRes(_devStr, "Ⅰ级风险", "62.5%", "Ⅱ级风险", "36.5%");
            break;
        case -2:
            this->insertRes(_devStr, "Ⅱ级风险", "88.8%", "Ⅰ级或Ⅲ级风险", "11.1%");
            break;
        case -3:
            this->insertRes(_devStr, "Ⅲ级风险", "90.9%", "故障停工", "9.0%");
            break;
        }
    }
}


void ErrorPredictForm::on_m_sureButton_clicked()
{
    m_devSerial.clear();

    while(ui->m_devTable->rowCount() != 0){
        ui->m_devTable->removeRow(0);
    }
    ui->m_devTable->horizontalHeader()->hide();

    if(ui->m_totalRadio->isChecked()){
        qx_query _query("select DISTINCT ON(devserial) * from inspecorbaseinfo");
        List_InspecorEnt lst;
        qx::dao::execute_query(_query, lst);

        for(const auto& _p : lst){
            m_devSerial.push_back(_p.second.m_devSerial);
        }
    }
    else if(ui->m_devSerialRadio->isChecked()){
        if(ui->m_devSerialLineEdit->text().isEmpty()){
            QMessageBox::information(this, "提示", "故障预测之前请输入设备编号!", tr("确定"));
            return;
        }
        m_devSerial.push_back(ui->m_devSerialLineEdit->text());
    }
    else if(ui->m_kindRadio->isChecked()){
        qx_query _query;/*("select DISTINCT ON(devserial) * from inspecorbaseinfo")*/
        switch (ui->m_kindComboBox->currentIndex()) {
        /// 锅炉
        case 0:
            _query.query("select DISTINCT ON(devserial) * from boiler");
            break;
        /// 汽机
        case 1:
            _query.query("select DISTINCT ON(devserial) * from motor");
            break;
        /// 变压器
        case 2:
            _query.query("select DISTINCT ON(devserial) * from transformer");
            break;
        /// 高压管道
        case 3:
            _query.query("select DISTINCT ON(devserial) * from pipeline");
            break;
        /// 输煤皮带
        case 4:
            _query.query("select DISTINCT ON(devserial) * from belt");
            break;
        }

        List_InspecorEnt lst;
        qx::dao::execute_query(_query, lst);

        for(const auto& _p : lst){
            m_devSerial.push_back(_p.second.m_devSerial);
        }
    }

    /// 根据用户选项智能生成预测的设备编号数组
    getPredictByInputSerial();

    if(m_predictRes.size())
    {   /// 插入数据到表格中
        ui->m_devTable->horizontalHeader()->show();

        while(ui->m_devTable->rowCount() != 0){
            ui->m_devTable->removeRow(0);
        }

        int i = 0;
        for(auto it = m_predictRes.begin(); it != m_predictRes.end(); it++){
            ui->m_devTable->insertRow(i);
            ui->m_devTable->setItem(i, 0, new QTableWidgetItem(it.key()));
            ui->m_devTable->setItem(i, 1, new QTableWidgetItem(it.value().first.second));
            if(it.value().first.second.contains("正常运行")){
                ui->m_devTable->item(i, 1)->setForeground(Qt::blue);
            }
            else if(it.value().first.second.contains("风险")){
                ui->m_devTable->item(i, 1)->setForeground(Qt::red);
            }
            else if(it.value().first.second.contains("故障停工")){
                ui->m_devTable->item(i, 1)->setForeground(Qt::gray);
            }
            ui->m_devTable->setItem(i, 2, new QTableWidgetItem(it.value().first.first));
            ui->m_devTable->setItem(i, 3, new QTableWidgetItem(it.value().second.second));
            if(it.value().second.second.contains("正常运行")){
                ui->m_devTable->item(i, 3)->setForeground(Qt::blue);
            }
            else if(it.value().second.second.contains("风险")){
                ui->m_devTable->item(i, 3)->setForeground(Qt::red);
            }
            else if(it.value().second.second.contains("故障停工")){
                ui->m_devTable->item(i, 3)->setForeground(Qt::gray);
            }
            ui->m_devTable->setItem(i, 4, new QTableWidgetItem(it.value().second.first));
        }
        i++;
    }
}

void ErrorPredictForm::insertRes(const QString& _devStr,const QString& _res1, const QString& _num1, const QString& _res2, const QString& _num2)
{
    ErrorPredictForm::m_predictRes.insert(_devStr,
                                          QPair<QPair<QString, QString>, QPair<QString, QString>>
                                          (QPair<QString, QString>(_num1, _res1), QPair<QString, QString>(_num2, _res2)));
}


void ErrorPredictForm::excelCrt(Document *_doc)
{
    if(ui->m_devTable->rowCount()){

        _doc->addSheet("故障预测统计表");
        _doc->selectSheet("故障预测统计表");
        _doc->setColumnWidth(2, 20);
        _doc->setColumnWidth(3, 20);
        _doc->setColumnWidth(4, 40);
        _doc->setColumnWidth(5, 40);
        _doc->setColumnWidth(6, 40);
        _doc->write("B2", "设备编号");
        _doc->write("C2", "预测结果Ⅰ");
        _doc->write("D2", "结果Ⅰ概率");
        _doc->write("E2", "预测结果Ⅱ");
        _doc->write("F2", "结果Ⅱ概率");

        QString column = "B";
        QString column1 = "C";
        QString column2 = "D";
        QString column3 = "E";
        QString column4 = "F";

        int row = 3;
        for(int i = 0; i < ui->m_devTable->rowCount(); ++i){
            QString _tmpCell = column + QString("%1").arg(row);
            QString _tmpCell1 = column1 + QString("%1").arg(row);
            QString _tmpCell2 = column2 + QString("%1").arg(row);
            QString _tmpCell3 = column3 + QString("%1").arg(row);
            QString _tmpCell4 = column4 + QString("%1").arg(row);

            _doc->write(_tmpCell, ui->m_devTable->item(i, 0)->text());
            _doc->write(_tmpCell1, ui->m_devTable->item(i, 1)->text());
            _doc->write(_tmpCell2, ui->m_devTable->item(i, 2)->text());
            _doc->write(_tmpCell3, ui->m_devTable->item(i, 3)->text());
            _doc->write(_tmpCell4, ui->m_devTable->item(i, 4)->text());

            row += 1;
        }
        _doc->selectSheet("设备运行总览表");
    }
}
