#include "isub_plugin.h"
using namespace pfactory;

ISubPlugin::ISubPlugin(SubPluginInfo info):
    _subPluginInfo( info )
{

}

ISubPlugin::~ISubPlugin()
{

}

SubPluginInfo ISubPlugin::subPluginInfo() const
{
    return _subPluginInfo;
}
