#ifndef YCODESET_H
#define YCODESET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Ycodeset; }
QT_END_NAMESPACE

class Ycodeset : public QWidget
{
    Q_OBJECT

public:
    Ycodeset(QWidget *parent = nullptr);
    ~Ycodeset();

private:
    Ui::Ycodeset *ui;
};
#endif // YCODESET_H
