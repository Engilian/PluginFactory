#include "ipfactory_plugin_controller.h"
using namespace pfactory;

IPFactoryPluginController::IPFactoryPluginController(const QString &id, const QString &desc):
    ISubPlugin( { id, "pfactory::IPFactoryPluginController", desc } )
{

}

IPFactoryPluginController::~IPFactoryPluginController()
{

}
