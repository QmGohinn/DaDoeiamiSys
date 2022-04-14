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

    /// 存储生成预测结果的设备编号
    static QVector<QString> m_devSerial;
    /// 存储预测结果
    static QMap<QString, QPair<QPair<QString, QString>, QPair<QString, QString>>> m_predictRes;

    /// 传入设备编号获取到预测结果
    void getPredictByInputSerial();

private slots:
    void on_m_sureButton_clicked();

private:
    Ui::ErrorPredictForm *ui;
};
#endif // ERRORPREDICTFORM_H
