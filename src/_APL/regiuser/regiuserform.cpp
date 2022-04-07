#include "regiuserform.h"
#include "ui_regiuserform.h"

#include <QMessageBox>
#include "../../_BK/AccountEnt/AccountEnt.h"

RegiUserForm::RegiUserForm(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::RegiUserForm)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/res/windows/people.ico"));

    ui->m_nameEdit->clear();
    ui->m_password1Edit->clear();
    ui->m_password2Edit->clear();
}

RegiUserForm::~RegiUserForm()
{
    delete ui;
}

void RegiUserForm::on_m_sureButton_clicked()
{
    QString _name = ui->m_nameEdit->text();
    QString _pwd1 = ui->m_password1Edit->text();
    QString _pwd2 = ui->m_password2Edit->text();

    if(_name.isEmpty() || _pwd1.isEmpty() || _pwd2.isEmpty()){
        QMessageBox::critical(this, "提示", "账号和密码不能为空!", tr("确定"));
        return;
    }

    if(_pwd1.compare(_pwd2)){
        QMessageBox::critical(this, "提示", "俩次输入密码不一致!", tr("确定"));
        return;
    }

    QString str_Query = QString("select from userlist where username = '%1'")
            .arg(_name);
    qx::QxSqlQuery query_User(str_Query);
    qx::dao::call_query(query_User);

    if(query_User.getSqlResultRowCount() > 0){
        QMessageBox::critical(this, "提示", "该用户已存在!!", tr("确定"));
        return;
    }
    else{
        UserEnt::Create(_name, _pwd1, 0);

        if(0 == QMessageBox::information(this, "提示", QString("%1, 恭喜您注册成功!").arg(_name), tr("返回上级"), tr("继续注册")))
        {
            QDialog::accept();
        }
    }
}

void RegiUserForm::on_m_returnButton_clicked()
{
    QDialog::accept();
}
