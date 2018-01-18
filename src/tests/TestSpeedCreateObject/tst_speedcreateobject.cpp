#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include <pfactory/pfactory.h>

class SpeedCreateObject : public QObject
{
    Q_OBJECT

public:
    SpeedCreateObject();

    static const int iterationsCount = 10000;
public:
    void createQObjects();
    void createUseFactory1();
    void createUseFactory2();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();

    void testCreateObjects_data();
    void testCreateObjects();
};

SpeedCreateObject::SpeedCreateObject()
{
}

void SpeedCreateObject::createQObjects()
{
    for ( int i = 0; i < iterationsCount; ++i ) {

        auto *obj = new QObject();
        delete obj;
    }
}

void SpeedCreateObject::createUseFactory1()
{
    for ( int i = 0; i < iterationsCount; ++i ) {

        auto *obj = pf::Factory::inst ()->create<QObject>();
        delete obj;
    }
}

void SpeedCreateObject::createUseFactory2()
{
    auto *f = pf::Factory::inst ();

    for ( int i = 0; i < iterationsCount; ++i ) {

        auto *obj = f->create<QObject>();
        delete obj;
    }
}

void SpeedCreateObject::initTestCase()
{
    auto *f = pf::Factory::inst ();

    f->controller ()->setPluginsDirectory ( "../../../bin/plug" );
    f->add<QObject>( "QObject" );
    f->setDefault<QObject>( "QObject" );
}

void SpeedCreateObject::cleanupTestCase()
{
    pf::Factory::destroy ();
}

void SpeedCreateObject::testCreateObjects_data()
{
    QTest::addColumn<QString>("data");

    QTest::newRow("base") << QString( "0" );
    QTest::newRow("factory1") << QString( "1" );
    QTest::newRow("factory2") << QString( "2");
}

void SpeedCreateObject::testCreateObjects()
{
    QFETCH(QString, data);

    if ( data == "0" ) {

        QBENCHMARK {

            createQObjects ();
        }
    }
    else if ( data == "1" ) {

        QBENCHMARK {

            createUseFactory1 ();
        }
    }
    else if ( data == "2" ) {

        QBENCHMARK {

            createUseFactory1 ();
        }
    }
}

QTEST_MAIN(SpeedCreateObject)

#include "tst_speedcreateobject.moc"
