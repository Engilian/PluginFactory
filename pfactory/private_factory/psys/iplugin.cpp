#include "iplugin.h"
using namespace psys;

#include <QVariant>

IPlugin::IPlugin()
{

}

IPlugin::~IPlugin()
{

}

ISubPlugin *IPlugin::create(const SubPluginInfo &info) const
{
  return create( info.id );
}
