#include "plugin_list_controller.h"

#include <QCoreApplication>
#include <QDebug>

PluginListController::PluginListController(QObject *parent) : QObject(parent)
{

    startTimer ( 50 );
}

PluginListController::~PluginListController()
{

}

void PluginListController::timerEvent(QTimerEvent *)
{
    QTextStream cin(stdin);

    QString command = cin.readLine ().trimmed ();

    if ( command.isEmpty () ) {

        return;
    }
    else if ( command.compare ( "quit" ) == 0 ){

        QCoreApplication::exit ();
    }
}
