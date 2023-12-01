template <class T>
JobQueue<T>::JobQueue(std::function<void(const T& job)> doFunction) :
    m_doFunction(doFunction),
    ThreadedObject()
{
}

template <class T>
JobQueue<T>::~JobQueue()
{
    m_interrupt = true;
    while (!m_jobs.empty())
    {
        delete  m_jobs.front();
        m_jobs.pop();
    }
}

template <class T>
void JobQueue<T>::queueJob(const T & job)
{
    m_jobs.push(new T(job));
    emit jobReceived();
}

template <class T>
void JobQueue<T>::doJob()
{
    QMutexLocker locker(&m_mutex);
    if (m_interrupt)
        return;

    auto job = m_jobs.front();
    m_doFunction(*job);
    delete job;
    m_jobs.pop();
}