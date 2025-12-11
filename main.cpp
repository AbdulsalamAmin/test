#include "threadmanager.h"

#include <iostream>
#include <limits>

#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ThreadManager newThread;

    int totalWork;


    while (true){

    qDebug() << "Enter Number Between 1000 too 100,000;";

    std::cin >>     totalWork;

    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        qDebug() << "number invalid. try again";
        continue;
    }

    if (totalWork< 1000){
        qDebug() << "number less than 1000. try again";
        continue;
    }
    if (totalWork > 100000){
        qDebug() << "number greater than 100,000. try again";
        continue;
    }
    // valid number and break
    break;

    }

    auto threads = newThread.startThreads(totalWork);
    newThread.saveJsonData(threads,"data.json");

    return a.exec();
}
