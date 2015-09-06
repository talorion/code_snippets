#include <QCoreApplication>

#include <QTimer>

#include "timed_thread.h"
#include "worker.h"

int main(int argc, char *argv[])
{

//    What requires a running event loop?

//    This isn't an exhaustive list, but if you have the overall picture, you should be able to guess which classes require a running event loop.

//    Widgets painting and interaction:
//              QWidget::paintEvent() will be called when delivering QPaintEvent objects,
//              which are generated both by calling QWidget::update() (i.e. internally) or by the window manager (for instance, because a hidden window was shown).
//              The same thing holds for all kinds of interaction (keyboard, mouse, etc.): the corresponding events will require an event loop to be dispatched.

//    Timers: long story short, they're fired when select(2) or similar calls time out, therefore you need to let Qt do those calls for you by returning to the event loop.

//    Networking:
//              all low-level Qt networking classes (QTcpSocket, QUdpSocket, QTcpServer, etc.) are asynchronous by design.
//              When you call read(), they just return already available data; when you call write(), they schedule the writing for later.
//              It's only when you return to the event loop the actual reading/writing takes place. Notice that they do offer synchronous methods (the waitFor* family of methods),
//              but their use is discouraged because they block the event loop while waiting. High-level classes, like QNetworkAccessManager,
//              simply do not offer any synchronous API and require an event loop.




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
