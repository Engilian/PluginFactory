#include "factory_plugin.h"
using namespace pf;
using namespace psys;

FactoryPlugin::FactoryPlugin():
    IPlugin()
{

}

FactoryPlugin::~FactoryPlugin()
{
    QList<SubPluginCreator *> list = creators.values ();
    creators.clear ();

    while ( !list.isEmpty () ) {
        delete list.takeFirst ();
    }
}


QList<SubPluginInfo> pf::FactoryPlugin::subPluginInfoList() const
{
    QList<SubPluginInfo> result;

    for ( auto *s: creators )  result << s->info;

    return result;
}

ISubPlugin *pf::FactoryPlugin::create(const QString &id) const
{
    return creators.contains ( id ) ? creators[ id ]->create(): nullptr;
}
