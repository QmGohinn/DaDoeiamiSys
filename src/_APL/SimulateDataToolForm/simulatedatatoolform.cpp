#include "simulatedatatoolform.h"
#include "ui_simulatedatatoolform.h"

#include "src/_base/UVGlobal.h"
#include "src/_BK/AccountEnt/AccountEnt.h"

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
    for(int i = 0; i < 3; ++i){
        qx_query _query(QString("delete from belt;"
                                "delete from boiler;"
                                "delete from inspecorbaseinfo;"
                                "delete from motor;"
                                "delete from pipeline;"
                                "delete from totalshow;"
                                "delete from transformer"
                                ";delete from userlist;"
                                "delete from dblog;"
                                "delete from userlog;"));
        List_UserEnt _lst;
        qx::dao::execute_query(_query, _lst);
    }
}
