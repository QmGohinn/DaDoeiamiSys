#ifndef SELFCENTERFORM_H
#define SELFCENTERFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SelfCenterForm; }
QT_END_NAMESPACE

class SelfCenterForm : public QMainWindow
{
    Q_OBJECT

public:
    SelfCenterForm(QWidget *parent = nullptr);
    ~SelfCenterForm();

private:
    Ui::SelfCenterForm *ui;
};
#endif // SELFCENTERFORM_H
