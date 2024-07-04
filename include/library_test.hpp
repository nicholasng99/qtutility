#pragma once

#include <QObject>

class LibraryTest : public QObject
{
    Q_OBJECT
public:
    LibraryTest();

    void testFunction();

signals:
    void testTriggered();
};