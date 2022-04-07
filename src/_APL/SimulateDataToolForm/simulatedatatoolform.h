#ifndef SIMULATEDATATOOLFORM_H
#define SIMULATEDATATOOLFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SimulateDataToolForm; }
QT_END_NAMESPACE

class SimulateDataToolForm : public QMainWindow
{
    Q_OBJECT

public:
    SimulateDataToolForm(QWidget *parent = nullptr);
    ~SimulateDataToolForm();

private:
    Ui::SimulateDataToolForm *ui;
};
#endif // SIMULATEDATATOOLFORM_H
