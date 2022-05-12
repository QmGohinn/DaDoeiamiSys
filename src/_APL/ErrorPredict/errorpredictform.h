#ifndef ERRORPREDICTFORM_H
#define ERRORPREDICTFORM_H

#include <QWidget>
#include "3rd/QXlsx/header/xlsxdocument.h"
using namespace QXlsx;

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

    /// 预测结果插入数据
    void insertRes(const QString&, const QString&, const QString&, const QString&, const QString&);


    /// 导出 excel 文件
    void excelCrt(Document* _doc);

private slots:
    void on_m_sureButton_clicked();

private:
    Ui::ErrorPredictForm *ui;
};
#endif // ERRORPREDICTFORM_H
