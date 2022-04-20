#include "selfcenterform.h"
#include "ui_selfcenterform.h"

#include <src/_base/UVGlobal.h>
#include <src/_BK/UserLogEnt/UserLogEnt.h>

SelfCenterForm::SelfCenterForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SelfCenterForm)
{
    ui->setupUi(this);
}

SelfCenterForm::~SelfCenterForm()
{
    delete ui;
}

void SelfCenterForm::init()
{
    if(UVGlobal::g_currentRole){
        ui->statusbar->showMessage(QString("%1,您现在拥有管理员权限!").arg(UVGlobal::g_userName));
    }
    else{
        ui->statusbar->showMessage(QString("%1,您现在是普通权限,可联系管理员进行权限提升!")
                                .arg(UVGlobal::g_userName));
    }

    while(ui->m_logTable->rowCount() != 0){
        ui->m_logTable->removeRow(0);
    }

    qx_query _query(QString("select * from userlog where name = '%1' order by updated_at DESC").arg(UVGlobal::g_userName));
    List_UserLogEnt _lst;
    qx::dao::execute_query(_query, _lst);


    int i = 0;
    for(const auto& loop_UserLog : _lst){

        ui->m_logTable->insertRow(i);

        ui->m_logTable->setItem(i, 0, new QTableWidgetItem(loop_UserLog.second->m_msg));
        ui->m_logTable->setItem(i, 1, new QTableWidgetItem(loop_UserLog.second->updatedAt.toString("yyyy-MM-dd hh:mm:ss ddd")));
        ++i;
    }
}

