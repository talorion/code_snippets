#ifndef TIMED_THREAD_H
#define TIMED_THREAD_H

#include <QObject>
#include <QThread>

class timed_thread : public QThread
{
    Q_OBJECT
public:
    explicit timed_thread(QObject *par = 0);

signals:

public slots:

private slots:
    void update();

protected:
    virtual void run();

};

#endif // TIMED_THREAD_H
