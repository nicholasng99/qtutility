#pragma once

#include <QString>
#include <QStringList>
#include <QResource>

namespace python
{
    struct Output
    {
        QString output;
        QString error;
    };

    Output run(const QResource &script, const QStringList &args = {});
}