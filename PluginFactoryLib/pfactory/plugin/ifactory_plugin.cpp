#include "ifactory_plugin.h"
using namespace pfactory;

#include <QVariant>

IFactoryPlugin::IFactoryPlugin()
{

}

IFactoryPlugin::~IFactoryPlugin()
{

}

bool IFactoryPlugin::versionComparer(const QString &v) const
{
    double currentVersion   = QVariant( version() ).toDouble();
    double otherVersion     = QVariant( v ).toDouble();

    return currentVersion > otherVersion;
}

ISubPlugin *IFactoryPlugin::create(const SubPluginInfo &info) const
{
    return create( info.id );
}
