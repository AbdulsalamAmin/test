#include "threadmanager.h"

#include <QThread>
#include <QString>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QJsonDocument>

ThreadManager::ThreadManager(QObject *parent,int id,int startIndex,int endIndex)
    : QThread{parent},startIndex(startIndex), endIndex(endIndex),threadId(generateThreadId(id))
{}

QString ThreadManager::generateThreadId(int index)
{
    int totalLetters = 26;
    int firstCharIndex = index  / totalLetters;
    int secondCharIndex = index % totalLetters;

    QChar letterA = 'A' + firstCharIndex;
    QChar letterB = 'a' + secondCharIndex;

    QString result = QString(letterA) + QString(letterB);
    return result;
}

void ThreadManager::run()
{
    QVector<int> numbers;

    for (int i = startIndex;i < endIndex;i++){
        int result = i * 1000;
        numbers.push_back(result);
    }
}

QVector<ThreadManager*> ThreadManager::startThreads(int totalWork)
{
    int chunkSize = 1000;
    int threadCount = totalWork / chunkSize;

    if (threadCount <= 0) {
        qWarning() << "Invalid thread count:" << threadCount;
    }

    static QVector<ThreadManager*> threads;

    for (int j = 0;j < threadCount;j++ ){
        int start  = j * chunkSize;
        int end = (j + 1) * chunkSize;
        ThreadManager* t = new ThreadManager(nullptr,j,start,end);
        threads.append(t);

        QObject::connect(t,&QThread::finished,t,&QObject::deleteLater);
    }
    for(ThreadManager * t: threads){
        t->start();
        qDebug() << "Started Thread"<< t->getThreadId();
    }

    for(ThreadManager* t: threads){
        t->wait();
        qDebug() << "Thread"<< t->getThreadId() << "Completed";
    }

    return threads;
    qDebug() << "All threads finished";

}

QJsonObject ThreadManager::saveToJson() const
{
    QJsonObject threadObject;
    threadObject["id"] = threadId;
    threadObject["startIndex"] = startIndex;
    threadObject["endIndex"] = endIndex;

    QJsonArray dataArray;

    for(int value: generateData){
        dataArray.append(value);
    }
    threadObject["generatedData"] = dataArray;

    return threadObject;
}

void ThreadManager::saveJsonData(const QVector<ThreadManager *> &threads, const QString &fileName)
{
    QJsonObject rootObject;
    QJsonArray threadArray;

    // int totalCount = 0;
    for(const ThreadManager* t: threads){
        threadArray.append(t->saveToJson());
    }
    rootObject["threads"] = threadArray;

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(rootObject);
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
        qDebug() << "Data saved to" << fileName;
    } else {
        qWarning() << "Failed to save data to" << fileName;
    }

}

