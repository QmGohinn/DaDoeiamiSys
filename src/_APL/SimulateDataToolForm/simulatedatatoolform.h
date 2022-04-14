#ifndef SIMULATEDATATOOLFORM_H
#define SIMULATEDATATOOLFORM_H

#include <QMainWindow>
#include <src/_APL/regiuser/regiuserform.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SimulateDataToolForm; }
QT_END_NAMESPACE

class SimulateDataToolForm : public QMainWindow
{
    Q_OBJECT

public:
    SimulateDataToolForm(QWidget *parent = nullptr);
    ~SimulateDataToolForm();

    /// 注册窗口
    RegiUserForm* m_addAdminForm = nullptr;

private slots:
    void on_pushButton_7_clicked();

private:
    Ui::SimulateDataToolForm *ui;
};
#endif // SIMULATEDATATOOLFORM_H
