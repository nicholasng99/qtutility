#include "Settings.hpp"
#include "Constants.hpp"

namespace
{
    const std::map<QString, QVariant> DEFAULT_VALUES = {
        {"Language", "English"},
        {"Developer Mode", false},
        {"Dark Mode", true},
    };
}

Settings::Settings()
    : m_settings(constants::ORGANIZATION_NAME, constants::APPLICATION_NAME)
{
    // init the default values if they don't exist
    for (auto pair : DEFAULT_VALUES)
        if (!m_settings.contains(pair.first))
            m_settings.setValue(pair.first, pair.second);
    qDebug() << "init settings";
}

QVariant Settings::getValue(const QString &key) const
{
    std::lock_guard<std::mutex> lock(m_mutex);
    if (DEFAULT_VALUES.count(key) > 0)
        return m_settings.value(key, DEFAULT_VALUES.at(key));
    return m_settings.value(key);
}

void Settings::setValue(const QString &key, const QVariant &value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    m_settings.setValue(key, value);
    emit settingUpdated(key, value);
}