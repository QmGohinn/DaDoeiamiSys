#include "simulatedatatoolform.h"
#include "ui_simulatedatatoolform.h"

#include "src/_base/UVGlobal.h"
#include "src/_BK/AccountEnt/AccountEnt.h"
#include "src/_BK/BoilerEnt/BoilerEnt.h"
#include "src/_BK/BeltEnt/BeltEnt.h"
#include "src/_BK/MotorEnt/MotorEnt.h"
#include "src/_BK/PipelineEnt/PipelineEnt.h"
#include "src/_BK/TransformerEnt/TransformerEnt.h"
#include "src/_BK/InspectorEnt/InspectorEnt.h"

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

/// 添加管理员
void SimulateDataToolForm::on_pushButton_7_clicked()
{
    UVGlobal::_adminFlg = true;
    if(m_addAdminForm == nullptr){
        m_addAdminForm = new RegiUserForm;
    }

    m_addAdminForm->setWindowTitle("管理员添加");
    m_addAdminForm->setDefaultTxt();

    m_addAdminForm->raise();
    m_addAdminForm->show();
    m_addAdminForm->activateWindow();
}

void SimulateDataToolForm::on_pushButton_2_clicked()
{
    if(0 == QMessageBox::warning(this, "警告", "您确定清空数据库吗?", tr("确定"), tr("取消"))){
        for(int i = 0; i < 3; ++i){
            qx_query _query(QString("delete from belt;"
                                    "delete from boiler;"
                                    "delete from inspecorbaseinfo;"
                                    "delete from motor;"
                                    "delete from pipeline;"
                                    "delete from totalshow;"
                                    "delete from transformer;"
                                    "delete from userlist;"
                                    "delete from dblog;"
                                    "delete from userlog;"));
            List_UserEnt _lst;
            qx::dao::execute_query(_query, _lst);
        }
    }
}

#include "src/_base/DBSetup.h"
void SimulateDataToolForm::on_pushButton_29_clicked()
{
    if(0 == QMessageBox::warning(this, "警告", "您确定模拟巡检吗?", tr("确定"), tr("取消"))){
        UVGlobal::g_insertFlg = true;
        DBSetup::DBInsertSimulate();
    }
}

void SimulateDataToolForm::on_pushButton_30_clicked()
{
    if(0 == QMessageBox::warning(this, "警告", "您确定模拟巡检吗?", tr("确定"), tr("取消")))
        DBSetup::DB_Boiler_Simulate();
}

void SimulateDataToolForm::on_pushButton_27_clicked()
{
    if(0 == QMessageBox::warning(this, "警告", "您确定模拟巡检吗?", tr("确定"), tr("取消")))
        DBSetup::DB_Motor_Simulate();
}

void SimulateDataToolForm::on_pushButton_28_clicked()
{
    if(0 == QMessageBox::warning(this, "警告", "您确定模拟巡检吗?", tr("确定"), tr("取消")))
        DBSetup::DB_Pipeline_Simulate();
}

void SimulateDataToolForm::on_pushButton_25_clicked()
{
    if(0 == QMessageBox::warning(this, "警告", "您确定模拟巡检吗?", tr("确定"), tr("取消")))
        DBSetup::DB_Transformer_Simulate();
}

void SimulateDataToolForm::on_pushButton_26_clicked()
{
    if(0 == QMessageBox::warning(this, "警告", "您确定模拟巡检吗?", tr("确定"), tr("取消")))
        DBSetup::DB_Belt_Simulate();
}

void SimulateDataToolForm::on_pushButton_clicked()
{
    if(ui->edit1->text().isEmpty()){
        QMessageBox::information(this, "提示", "请输入设备编号!", tr("确定"));
        return;
    }

    if(0 == QMessageBox::warning(this, "警告", "您确定模拟巡检吗?", tr("确定"), tr("取消"))){

        QString _devname = ui->edit1->text();
        _devname = _devname.toUpper();
        qx_query _query(QString("select * from inspecorbaseinfo where LOWER(devserial) = LOWER('%1') order by updated_at DESC")
                        .arg(_devname));
        List_InspecorEnt lst;
        qx::dao::execute_query(_query, lst);

        if(0 == lst.size()){
            QMessageBox::information(this, "提示", "该设备编号不存在!", tr("确定"));
            return;
        }

        PATROLRES _res;
        switch (ui->comboBox->currentIndex()) {
        case 0:
            _res = NRM;
            break;
        case 1:
            _res = QUESTION_1_LEVEL;
            break;
        case 2:
            _res = QUESTION_2_LEVEL;
            break;
        case 3:
            _res = QUESTION_3_LEVEL;
            break;
        case 4:
            _res = ERROE;
            break;
        }

        if(_devname.startsWith("GL")){
            BoilerEnt::Create(_devname,
                            InspecorEnt::Create(_res, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devname));
        }
        if(_devname.startsWith("QJ")){
            MotorEnt::Create(_devname,
                            InspecorEnt::Create(_res, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devname));
        }
        if(_devname.startsWith("PD")){
           BeltEnt::Create(_devname,
                            InspecorEnt::Create(_res, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devname));
        }
        if(_devname.startsWith("GD")){
            PipelineEnt::Create(_devname,
                            InspecorEnt::Create(_res, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devname));
        }
        if(_devname.startsWith("BY")){
            TransformerEnt::Create(_devname,
                            InspecorEnt::Create(_res, UVGlobal::g_DATETIME, "17191206623", "吴斌", _devname));
        }
    }
}
