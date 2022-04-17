#include "shiftuserform.h"
#include "ui_shiftuserform.h"

#include <QPushButton>
#include <QMessageBox>

#include <src/_BK/AccountEnt/AccountEnt.h>
#include <src/_base/UVGlobal.h>

ShiftUserForm::ShiftUserForm(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShiftUserForm)
{
    ui->setupUi(this);

    ui->m_usernameEdit->clear();
    ui->m_pwdEdit->clear();

    QPushButton* _p = ui->buttonBox->button(QDialogButtonBox::Save);
    _p->setText("登录");
    _p = ui->buttonBox->button(QDialogButtonBox::Close);
    _p->setText("取消");
}

ShiftUserForm::~ShiftUserForm()
{
    delete ui;
}

void ShiftUserForm::on_buttonBox_accepted()
{
    QString _username = ui->m_usernameEdit->text().trimmed();
    QString _pwd = ui->m_pwdEdit->text();

    ui->m_usernameEdit->clear();
    ui->m_pwdEdit->clear();

    if(_username == "" || _pwd == "")
    {
        QMessageBox::critical(this, "提示", "账号和密码不能为空!", tr("确定"));
        return;
    }

    if(!_username.compare(UVGlobal::g_userName) && !_pwd.compare(UVGlobal::g_passWord)){
        QMessageBox::information(this, "提示", "您已登录此账号!", tr("确定"));
        return;
    }

    QString str_Query = QString("select from userlist where username = '%1' and password = '%2' ")
            .arg(_username).arg(_pwd);
    qx::QxSqlQuery query_User(str_Query);
    qx::dao::call_query(query_User);

    if(query_User.getSqlResultRowCount() > 0)
    {
        qx::QxSqlQuery _tmpQuery(QString("where username = '%1' and password = '%2'")
                                 .arg(_username).arg(_pwd));
        List_UserEnt _tmpUserLst;
        qx::dao::fetch_by_query(_tmpQuery, _tmpUserLst);
        UVGlobal::g_currentRole = _tmpUserLst.begin()->second->role;
        UVGlobal::g_userName = _username;
        UVGlobal::g_passWord = _pwd;
        UVGlobal::g_userID = _tmpUserLst.begin()->second->id;

        if(0 == QMessageBox::information(this, "提示", "更换用户成功!", tr("确定"))){
            this->close();
        }
    }
    else
    {
        QMessageBox::warning(this, "提示", "用户不存在或密码错误!", tr("确定"));
        return;
    }
}

void ShiftUserForm::on_buttonBox_rejected()
{
    ui->m_usernameEdit->clear();
    ui->m_pwdEdit->clear();
    this->close();
}
