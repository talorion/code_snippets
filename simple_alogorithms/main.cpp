#include <QCoreApplication>

#include <QDebug>

#include "uuid_generator.hpp"

typedef enum mode_{
    Input = 0x0001,
    Output = 0x0002,
    InputOutput = Input | Output
}mode;

int main(int argc, char *argv[])
{
    //    QCoreApplication a(argc, argv);

    qDebug()<<generate_uuid().toString();

    mode x = Output;
    if(x & Input){
        qDebug()<<"aaaa";
    }

    if(x & Output){
        qDebug()<<"bbbb";
    }


    //    return a.exec();
    return 0;
}
