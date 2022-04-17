#include "simulatedatatoolform.h"
#include "ui_simulatedatatoolform.h"

#include "src/_base/UVGlobal.h"

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
