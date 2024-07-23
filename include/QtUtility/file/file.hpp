#pragma once

#include <QFileInfo>

namespace QtUtility {
namespace file {

bool create(const QFileInfo &info, const bool &override = false);
QFileInfo getUniqueFile(const QFileInfo &info);
QFileInfo createUnique(const QFileInfo &info);

} // namespace file
} // namespace QtUtility