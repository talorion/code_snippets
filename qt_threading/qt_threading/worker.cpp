#include "worker.h"
#include <QThread>

Worker::Worker(QObject *par) : QObject(par)
{
    // you could copy data from constructor arguments to internal variables here.
}

Worker::~Worker()
{
    // free resources
}

void Worker::process()
{
    // allocate resources using new here

    //Do work
    qDebug("Hello World!");
    QThread::sleep ( 3 );

    qDebug("finished");
    emit finished();
}

