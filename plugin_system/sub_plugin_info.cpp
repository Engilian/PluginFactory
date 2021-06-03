#include "sub_plugin_info.h"
using namespace psys;

SubPluginInfo::SubPluginInfo()
{

}

SubPluginInfo::SubPluginInfo(const QString &id,
                             const QString &interface,
                             const QString &desc ):
    id          ( id ),
    interfaceId ( interface ),
    description ( desc )
{

}

SubPluginInfo::SubPluginInfo(const SubPluginInfo &info):
    id          ( info.id ),
    interfaceId ( info.interfaceId ),
    description ( info.description )
{

}

bool SubPluginInfo::operator==(const SubPluginInfo &info) const
{
    if ( id.compare ( info.id ) == 0 ) {

        if ( interfaceId.compare ( info.interfaceId ) == 0 ) {

            return true;
        }
    }

    return false;
}

bool SubPluginInfo::operator==(const QString &id) const
{
    return this->id.compare ( id ) == 0;
}

bool SubPluginInfo::operator!=(const QString &id) const
{
    return this->id.compare ( id ) != 0;
}

bool SubPluginInfo::operator!=(const SubPluginInfo &info) const
{
    if ( id.compare ( info.id ) == 0 ) {

        if ( interfaceId.compare ( info.interfaceId ) == 0 ) {

            return false;
        }
    }

    return true;
}

bool SubPluginInfo::operator>(const SubPluginInfo &info) const
{
    if ( id.compare ( info.id ) == 0 ) {

        return interfaceId > info.interfaceId;
    }

    return id > info.id;
}

bool SubPluginInfo::operator<(const SubPluginInfo &info) const
{
    if ( id.compare ( info.id ) == 0 ) {

        return interfaceId < info.interfaceId;
    }

    return id < info.id;
}
