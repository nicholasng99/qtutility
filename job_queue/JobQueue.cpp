#include "JobQueue.h"

ThreadedObject::ThreadedObject() :
    m_interrupt(false),
    m_thread(new QThread)
{
    moveToThread(m_thread);
    connect(this, &ThreadedObject::jobReceived, this, &ThreadedObject::doJob, Qt::QueuedConnection);
    m_thread->start();
}

ThreadedObject::~ThreadedObject()
{
    m_interrupt = true;
    m_thread->quit();
    m_thread->wait();
}

void ThreadedObject::setInterrupt(const bool & state)
{
    if (m_interrupt == state)
        return;
    m_interrupt = state;
    if (!m_interrupt)
    {
        // resume the job if not already running
        auto lock = m_mutex.tryLock();
        if (lock)
            m_mutex.unlock();
        else
            doJob();
    }
}
