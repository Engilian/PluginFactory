#include <QtCore/QCoreApplication>

#include <QDir>
#include <QDebug>

#include <pfactory/pfactory.h>

using namespace pf;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setApplicationName ( "plist" );

    Factory::instance ();
    Factory::instance ()->controller ()->setPluginsDirectory (
                QDir::fromNativeSeparators ( QCoreApplication::applicationDirPath () +
                                             "/plug" ) );

    qDebug() << "--- Plugin list application ---";
    qDebug() << "plugin interface: "
             << FACTORY_PLUGIN_VALID_STRING;

    printf ( "\n" );
    printf ( "Avalaible plugins:" "\n\n" );

    int pluginNumber = 1;
    for ( auto p: Factory::instance ()->controller ()->pluginsInfo () ) {

        printf ( "%d. %s v%s\n(f: %s uid: [%s])\n",
                 pluginNumber++,
                 p.plugin ()->name ().toStdString ().c_str (),
                 p.plugin ()->version ().toStdString ().c_str (),
                 p.fileName ().toStdString ().c_str (),
                 p.uid ().toStdString ().c_str () );

        printf ( "author:   %s \n"
                 "brief:    %s \n"
                 "details:  %s \n"
                 "subs: \n",
                 p.plugin ()->author ().toStdString ().c_str (),
                 p.plugin ()->briefInfo ().toStdString ().c_str (),
                 p.plugin ()->detailedInfo ().toStdString ().c_str () );

        int subPluginNumver = 1;
        for ( auto &info: p.plugin ()->subPluginInfoList () ) {

            printf ( "\t %d. id: %s interface: %s\n",
                     subPluginNumver++,
                     info.id.toStdString ().c_str (),
                     info.interfaceId.toStdString ().c_str () );
            printf ( "\t " "   desc: %s\n\n", info.description.toStdString ().c_str () );
        }

        printf ( "\n" );
    }

    printf ( "\n\n" );
    return 0;
}
