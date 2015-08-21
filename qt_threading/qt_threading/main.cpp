#include <QCoreApplication>

#include <QTimer>

#include "timed_thread.h"
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    timed_thread* tme_thd = new timed_thread(&a);
    //QObject::connect(&main_window,SIGNAL(destroyed()), com_thrd, SLOT(quit()));
    QObject::connect(&a,SIGNAL(aboutToQuit()), tme_thd, SLOT(quit()));
    tme_thd->start();


    QThread* thread = new QThread;
    Worker* worker = new Worker();
    worker->moveToThread(thread);
    //connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    QObject::connect(thread, SIGNAL(started()), worker, SLOT(process()));
    QObject::connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    QObject::connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();

    QTimer::singleShot(10000,&a,SLOT(quit()));
    return a.exec();
}
