#pragma once

#include <queue>
#include <functional>

#include <QObject>
#include <QMutex>
#include <QThread>

class QThread;

class ThreadedObject : public QObject
{
    Q_OBJECT
public:
    ThreadedObject();
    virtual ~ThreadedObject();
    void setInterrupt(const bool& state);

signals:
    void jobReceived();

protected slots:
    virtual void doJob() = 0;

protected:
    bool m_interrupt;
    QMutex m_mutex;
    QThread* m_thread;
};

template <class T>
class JobQueue : public ThreadedObject
{
public:
    JobQueue(std::function<void(const T& job)> doFunction);
    ~JobQueue();
    void queueJob(const T& job);

protected:
    virtual void doJob() override;

    std::queue<T*> m_jobs;
    std::function<void(const T& job)> m_doFunction;
};

#include "JobQueue.tpp"