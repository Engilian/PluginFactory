#include "iplugin.h"
using namespace psys;

#include <QVariant>

IPlugin::IPlugin()
{

}

IPlugin::~IPlugin()
{

}

bool IPlugin::versionComparer(const QString &v) const
{
    double currentVersion   = QVariant( version() ).toDouble();
    double otherVersion     = QVariant( v ).toDouble();

    return currentVersion > otherVersion;
}

ISubPlugin *IPlugin::create(const SubPluginInfo &info) const
{
    return create( info.id );
}
