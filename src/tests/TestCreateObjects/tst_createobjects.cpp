#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include <QDir>
#include <pfactory/pfactory.h>

class CreateObjectsTest : public QObject
{
    Q_OBJECT

public:
    CreateObjectsTest();

private Q_SLOTS:
    void loadTestPlugin();
    void creatorsCount();
    void loadCrators();
    void createObjects();
    void testDefaultCreator();
    void testCreateUncorrectObject();
};

CreateObjectsTest::CreateObjectsTest()
{
    auto *f = pf::Factory::inst ();

    f->controller ()->setPluginsDirectory ( "../../../bin/plug" );
    pf::Factory::inst ()->add<QObject>( "QObject" );
}

void CreateObjectsTest::loadTestPlugin()
{
    auto *f = pf::Factory::inst ();

    const QString pluginName = "PFactory plugin for unit test";

    bool isFind = false;

    for ( auto p: f->controller ()->plugins () ) {

        if ( pluginName.compare ( p->name () ) == 0 ) {

            isFind = true;
            break;
        }
    }

    QVERIFY ( isFind );
}

void CreateObjectsTest::creatorsCount()
{
    auto *f = pf::Factory::inst ();
    QVERIFY ( f->creatorsName<QObject>().count() == 4 );
}

void CreateObjectsTest::loadCrators()
{
    QStringList creators {
        "QObject",
        "QTcpServer",
        "QTcpSocket",
        "QNetworkAccessManager" };

    auto *f = pf::Factory::inst ();

    for ( auto &creatorName: creators ) {

        bool isFind = false;

        for ( auto &c: f->creatorsName<QObject>() ) {

            if ( creatorName.compare ( c ) == 0 ) {

                isFind = true;
                break;
            }
        }

        QVERIFY ( isFind );
    }
}

void CreateObjectsTest::createObjects()
{
    auto *f = pf::Factory::inst ();

    // Test all creators
    for ( auto &id: f->creatorsName<QObject>() ) {

        auto *obj = f->create<QObject>( id );

        QVERIFY ( obj != nullptr );
        if ( obj ) {

            QCOMPARE( id, QString( obj->metaObject ()->className () ) );

            delete obj;
        }
    }
}

void CreateObjectsTest::testDefaultCreator()
{
    auto *f = pf::Factory::inst ();

    // Test default creator
    auto *obj = f->create<QObject>();
    QCOMPARE( f->defaultCreator<QObject>(), QString( obj->metaObject ()->className () ) );
    delete obj;
}

void CreateObjectsTest::testCreateUncorrectObject()
{
    auto *f = pf::Factory::inst ();

    auto *obj = f->create<QObject>( "error_creator" );
    QVERIFY ( obj == nullptr );
}

QTEST_MAIN(CreateObjectsTest)

#include "tst_createobjects.moc"
