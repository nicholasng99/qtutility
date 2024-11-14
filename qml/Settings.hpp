#pragma once
#include <QObject>
#include <qqml.h>
#include <QSettings>

#include <mutex>

class Settings : public QObject
{
    Q_OBJECT
    QML_SINGLETON
    QML_ELEMENT

public:
    explicit Settings();
    Q_INVOKABLE QVariant getValue(const QString &key) const;
    Q_INVOKABLE void setValue(const QString &key, const QVariant &value);

signals:
    void settingUpdated(const QString &key, const QVariant &value);

private:
    QSettings m_settings;
    mutable std::mutex m_mutex;
};
