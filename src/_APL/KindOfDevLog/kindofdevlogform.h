#ifndef KINDOFDEVLOGFORM_H
#define KINDOFDEVLOGFORM_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class KindOfDevLogForm; }
QT_END_NAMESPACE

class KindOfDevLogForm : public QWidget
{
    Q_OBJECT

public:
    KindOfDevLogForm(QWidget *parent = nullptr);
    ~KindOfDevLogForm();

private slots:
    void on_m_clearButton_clicked();

private:
    Ui::KindOfDevLogForm *ui;
};
#endif // KINDOFDEVLOGFORM_H
