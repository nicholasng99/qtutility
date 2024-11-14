// @brief this class allows quick access to QML singletons
#pragma once

#include <QString>
#include <QQmlApplicationEngine>

class Singleton
{
public:
    static Singleton &instance()
    {
        static Singleton instance;
        return instance;
    }

    void initEngine(QQmlApplicationEngine *engine)
    {
        if (engine == nullptr)
            return;
        m_engine = engine;
        qDebug("Singleton engine is assigned, get is ready to be used");
    }

    template <typename T>
    T *get(QString module, QString name)
    {
        if (m_engine == nullptr)
        {
            qWarning() << "Engine is not assigned yet, get will return nullptr";
            return nullptr;
        }
        T *instance = m_engine->singletonInstance<T *>(module, name);
        if (!instance)
            qWarning() << "Singleton instance doesn't exist in engine (module: " << module << " name: " << name << ")";
        return instance;
    }

    template <typename T>
    T *get(QString name)
    {
        return get<T>(name, name);
    }

private:
    Singleton() { qDebug("Singleton::instance().initEngine(...); must be called before get can be used"); }
    ~Singleton() {}
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    QQmlApplicationEngine *m_engine = nullptr;
};