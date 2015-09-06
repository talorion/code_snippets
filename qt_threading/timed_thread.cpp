#include "timed_thread.h"

#include <QTimer>
#include <QDebug>

timed_thread::timed_thread(QObject *par) : QThread(par)
{

}

void timed_thread::update()
{
    qDebug()<<"TICK";
}

void timed_thread::run()
{
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);


    exec();

    timer->stop();
    delete timer;
}

