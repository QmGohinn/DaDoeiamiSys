#include "changepwdform.h"
#include "ui_changepwdform.h"

#include <QPushButton>
#include <QMessageBox>
#include <src/_base/UVGlobal.h>
#include <src/_BK/AccountEnt/AccountEnt.h>
#include <src/_BK/UserLogEnt/UserLogEnt.h>

ChangePWDForm::ChangePWDForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChangePWDForm)
{
    ui->setupUi(this);

    QPushButton* _button = ui->buttonBox->button(QDialogButtonBox::Save);
    _button->setText("保存");
    _button = ui->buttonBox->button(QDialogButtonBox::Close);
    _button->setText("取消");
}

ChangePWDForm::~ChangePWDForm()
{
    delete ui;
}


void ChangePWDForm::on_buttonBox_accepted()
{
    QString _beforePWd = ui->m_beforePWDEdit->text();
    QString _newPWD1 = ui->m_newPWDEdit->text();
    QString _newPWD2 = ui->m_newPWDEdit2->text();

    ui->m_beforePWDEdit->clear();
    ui->m_newPWDEdit->clear();
    ui->m_newPWDEdit2->clear();

    if(_beforePWd.isEmpty() || _newPWD1.isEmpty() || _newPWD2.isEmpty()){
        QMessageBox::warning(this, "提示", "请补充完善密码信息!", tr("确定"));
        return;
    }

    if(_newPWD1.compare(_newPWD2)){
        QMessageBox::warning(this, "提示", "俩次输入密码不一致!", tr("确定"));
        return;
    }

    if(UVGlobal::g_passWord.compare(_beforePWd)){
        QMessageBox::question(this, "提示", "原密码输入错误!", tr("确定"));
        return;
    }

    if(!_beforePWd.compare(_newPWD1)){
        QMessageBox::question(this, "提示", "新密码与原密码相同!", tr("确定"));
        return;
    }

    UserEntPtr _p;
    _p.reset(new UserEnt);
    _p->id = UVGlobal::g_userID;
    _p->userName = UVGlobal::g_userName;
    _p->password = _newPWD1;
    _p->role = UVGlobal::g_currentRole;
    qx::dao::update(_p);

    UVGlobal::g_passWord = _newPWD1;

    if(0 == QMessageBox::information(this, "提示", QString("修改密码成功!"), tr("确定")))
    {
        UserLogEnt::Create(UVGlobal::g_userName, "修改密码");
        this->close();
    }
}

void ChangePWDForm::on_buttonBox_rejected()
{
    ui->m_beforePWDEdit->clear();
    ui->m_newPWDEdit->clear();
    ui->m_newPWDEdit2->clear();

    this->close();
}
