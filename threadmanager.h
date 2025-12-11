#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <QObject>
#include <QThread>
#include<QString>
#include <QJsonDocument>
#include <QJsonObject>
class ThreadManager : public QThread
{
    Q_OBJECT
public:
    explicit ThreadManager(QObject *parent = nullptr,int id = 0,int startIndex = 0,int endIndex = 0);
    static QVector<ThreadManager*> startThreads(int totalWork);
    QString getThreadId() const {return threadId;}
    void run() override;

    QJsonObject saveToJson() const;
    static void saveJsonData(const QVector<ThreadManager*> &threads,const QString &fileName);

private:
    int startIndex;
    int endIndex;
    QString threadId;
    QString generateThreadId(int index);
    QVector<int> generateData;




signals:


};

#endif // THREADMANAGER_H
