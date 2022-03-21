#ifndef UVTHREAD_H
#define UVTHREAD_H

#include <QThread>

class UVThread : public QThread
{
    Q_OBJECT

public:
    UVThread();
    ~UVThread();

signals:
    void UVThreadRun();

protected:
    virtual void run() override;
};

#endif // UVTHREAD_H
