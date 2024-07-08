#include "file/file.hpp"

#include <QDir>

bool file::create(const QFileInfo &info, const bool &override)
{
    QFile file(info.filePath());
    if (file.exists())
    {
        if (override)
            return file.resize(0);
        else
            return true;
    }
    info.absoluteDir().mkpath(".");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;
    file.close();
    return true;
}

QFileInfo file::getUniqueFile(const QFileInfo &info)
{
    QFileInfo result = info;
    int counter = 1;
    while (result.exists())
        result = QFileInfo(info.dir(), QString("%1 (%2).%3").arg(info.baseName()).arg(++counter).arg(info.completeSuffix()));
    return result;
}

QFileInfo file::createUnique(const QFileInfo &info)
{
    QFileInfo result = getUniqueFile(info);
    QFile file(result.filePath());
    info.absoluteDir().mkpath(".");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return QFileInfo();
    file.close();
    return result;
}