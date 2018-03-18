#ifndef FACTORY_PLUGIN_H
#define FACTORY_PLUGIN_H

#include <QMap>
#include <plugin_system/iplugin.h>
#include "sub_plugin_creator.h"


namespace pf
{
class FactoryPlugin: public psys::IPlugin
{
    QMap<QString, SubPluginCreator *> creators;
protected:
    FactoryPlugin();
public:
    virtual ~FactoryPlugin();
public:
    virtual QList<psys::SubPluginInfo> subPluginInfoList() const Q_DECL_OVERRIDE;
    virtual psys::ISubPlugin *create(const QString &id) const Q_DECL_OVERRIDE;
public:
    template<class Interface, class Obj>
    bool regCreator( const psys::SubPluginInfo &info )
    {

        if ( creators.contains ( info.id ) ) {

            return false;
        }

        creators[ info.id ] = new TemplateSubPluginCreator<Interface, Obj>( info );
        return true;
    }

    template<class Interface, class Obj>
    bool regCreator( const QString &id, const QString &interface, const QString &info = 0 )
    {

        psys::SubPluginInfo pInfo ( id, interface, info );

        return regCreator<Interface, Obj>( pInfo );
    }
};

}



#endif // FACTORY_PLUGIN_H
