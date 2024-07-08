#pragma once

#include <QFileInfo>

namespace file
{
    bool create(const QFileInfo &info, const bool &override = false);
    QFileInfo getUniqueFile(const QFileInfo &info);
    QFileInfo createUnique(const QFileInfo &info);
};
