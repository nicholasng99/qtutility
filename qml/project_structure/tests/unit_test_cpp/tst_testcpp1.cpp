#include <QtTest>

// add necessary includes here
#include "../../modules/FirstPlugin/myitem.h"

class TestCpp1 : public QObject
{
    Q_OBJECT

public:
    TestCpp1();
    ~TestCpp1();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

TestCpp1::TestCpp1()
{

}

TestCpp1::~TestCpp1()
{

}

void TestCpp1::initTestCase()
{

}

void TestCpp1::cleanupTestCase()
{

}

void TestCpp1::test_case1()
{
    MyItem item;
    item.onItemClicked();

    QVERIFY(true);
}

QTEST_APPLESS_MAIN(TestCpp1)

#include "tst_testcpp1.moc"
