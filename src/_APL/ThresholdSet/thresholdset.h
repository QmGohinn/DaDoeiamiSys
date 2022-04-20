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

private:
    Ui::thresholdset *ui;
};
#endif // THRESHOLDSET_H
