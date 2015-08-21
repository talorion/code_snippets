#ifndef REUSABLE_THREAD_H
#define REUSABLE_THREAD_H

#include <QObject>

class reusable_thread : public QObject
{
    Q_OBJECT
public:
    explicit reusable_thread(QObject *parent = 0);

signals:

public slots:
};

#endif // REUSABLE_THREAD_H
