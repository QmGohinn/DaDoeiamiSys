#include "UVThread.h"
#include <QDebug>

UVThread::UVThread(){

}

UVThread::~UVThread(){

}

void UVThread::run()
{
    emit UVThreadRun();
}
