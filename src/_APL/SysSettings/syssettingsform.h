#ifndef SYSSETTINGSFORM_H
#define SYSSETTINGSFORM_H

#include <QMainWindow>
#include <src/_APL/settingTime/timeset.h>
#include <src/_APL/settingYCode/ycodeset.h>
#include <src/_APL/ThresholdSet/thresholdset.h>

QT_BEGIN_NAMESPACE
namespace Ui { class SysSettingsForm; }
QT_END_NAMESPACE

class SysSettingsForm : public QMainWindow
{
    Q_OBJECT

public:
    SysSettingsForm(QWidget *parent = nullptr);
    ~SysSettingsForm();

    timeset* m_timeSet = nullptr;
    Ycodeset* m_ycodeSet = nullptr;
    thresholdset* m_thresholdset = nullptr;

    void setIndex(int _index);

private:
    Ui::SysSettingsForm *ui;
};
#endif // SYSSETTINGSFORM_H
