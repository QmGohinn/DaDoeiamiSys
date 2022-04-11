#ifndef ERRORPREDICTFORM_H
#define ERRORPREDICTFORM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ErrorPredictForm; }
QT_END_NAMESPACE

class ErrorPredictForm : public QWidget
{
    Q_OBJECT

public:
    ErrorPredictForm(QWidget *parent = nullptr);
    ~ErrorPredictForm();

private:
    Ui::ErrorPredictForm *ui;
};
#endif // ERRORPREDICTFORM_H
