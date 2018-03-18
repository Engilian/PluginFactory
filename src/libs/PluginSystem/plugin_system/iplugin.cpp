#include "iplugin.h"
using namespace psys;

#include <QVariant>

IPlugin::IPlugin()
{

}

IPlugin::~IPlugin()
{

}

QString IPlugin::id() const {
    return name () + " " + version () + "(" + author () + ")";
}

QString IPlugin::logo() const
{
    return "";
}

QString IPlugin::detailedInfo() const
{
    return "";
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
