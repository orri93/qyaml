#include <QString>
#include <QtTest>

class QyamltestTest : public QObject {
        Q_OBJECT

    public:
        QyamltestTest();

    private Q_SLOTS:
        void testCase1();
};

QyamltestTest::QyamltestTest() {
}

void QyamltestTest::testCase1() {
    QVERIFY2( true, "Failure" );
}

QTEST_APPLESS_MAIN( QyamltestTest )

#include "tst_qyamltesttest.moc"
