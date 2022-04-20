#ifndef TIMESET_H
#define TIMESET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class timeset; }
QT_END_NAMESPACE

class timeset : public QWidget
{
    Q_OBJECT

public:
    timeset(QWidget *parent = nullptr);
    ~timeset();

private:
    Ui::timeset *ui;
};
#endif // TIMESET_H
