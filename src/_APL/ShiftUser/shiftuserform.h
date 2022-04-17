#ifndef SHIFTUSERFORM_H
#define SHIFTUSERFORM_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ShiftUserForm; }
QT_END_NAMESPACE

class ShiftUserForm : public QDialog
{
    Q_OBJECT

public:
    ShiftUserForm(QWidget *parent = nullptr);
    ~ShiftUserForm();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ShiftUserForm *ui;
};
#endif // SHIFTUSERFORM_H
