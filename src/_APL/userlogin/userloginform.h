#ifndef USERLOGINFORM_H
#define USERLOGINFORM_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class UserLoginForm; }
QT_END_NAMESPACE

class UserLoginForm : public QDialog
{
    Q_OBJECT

public:
    UserLoginForm(QWidget *parent = nullptr);
    ~UserLoginForm();

private:
    Ui::UserLoginForm *ui;
};
#endif // USERLOGINFORM_H
