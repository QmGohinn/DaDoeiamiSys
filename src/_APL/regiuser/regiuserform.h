#ifndef REGIUSERFORM_H
#define REGIUSERFORM_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class RegiUserForm; }
QT_END_NAMESPACE

class RegiUserForm : public QDialog
{
    Q_OBJECT

public:
    RegiUserForm(QDialog *parent = nullptr);
    ~RegiUserForm();

private slots:
    void on_m_sureButton_clicked();
    void on_m_returnButton_clicked();

private:
    Ui::RegiUserForm *ui;
};
#endif // REGIUSERFORM_H
