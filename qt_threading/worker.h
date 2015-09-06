#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *par = 0);
    ~Worker();

signals:
    void finished();
    void error(QString err);

public slots:
    void process();

private:
    // add your variables here
};

#endif // WORKER_H
