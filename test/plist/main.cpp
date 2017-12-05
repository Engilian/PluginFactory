#include <QtCore/QCoreApplication>

#include "plugin_list_controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setApplicationName ( "plist" );

    auto *pc = new PluginListController();
    Q_UNUSED ( pc );

    return a.exec ();
}
