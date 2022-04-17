#ifndef CHANGEPWDFORM_H
#define CHANGEPWDFORM_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ChangePWDForm; }
QT_END_NAMESPACE

class ChangePWDForm : public QDialog
{
    Q_OBJECT

public:
    ChangePWDForm(QWidget *parent = nullptr);
    ~ChangePWDForm();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ChangePWDForm *ui;
};
#endif // CHANGEPWDFORM_H
