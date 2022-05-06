#ifndef THRESHOLDSET_H
#define THRESHOLDSET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class thresholdset; }
QT_END_NAMESPACE

class thresholdset : public QWidget
{
    Q_OBJECT

public:
    thresholdset(QWidget *parent = nullptr);
    ~thresholdset();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::thresholdset *ui;
};
#endif // THRESHOLDSET_H
