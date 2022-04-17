#ifndef SYSSETTINGSFORM_H
#define SYSSETTINGSFORM_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SysSettingsForm; }
QT_END_NAMESPACE

class SysSettingsForm : public QMainWindow
{
    Q_OBJECT

public:
    SysSettingsForm(QWidget *parent = nullptr);
    ~SysSettingsForm();

private:
    Ui::SysSettingsForm *ui;
};
#endif // SYSSETTINGSFORM_H
