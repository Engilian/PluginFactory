#ifndef SUB_PLUGIN_CREATOR_H
#define SUB_PLUGIN_CREATOR_H

#include <plugin_system/isub_plugin.h>
#include "object_creator.h"

namespace pf {

struct SubPluginCreator
{
    const psys::SubPluginInfo info;
protected:
    SubPluginCreator( const psys::SubPluginInfo &info );
public:
    virtual ~SubPluginCreator();
public:
    virtual psys::ISubPlugin *create() = 0;
};


template<class Interface, class Obj>
class TemplateSubPluginCreator: public SubPluginCreator
{
public:
    TemplateSubPluginCreator( const psys::SubPluginInfo &info ):
        SubPluginCreator( info )
    {}
    ~TemplateSubPluginCreator(){}
public:

    psys::ISubPlugin *create()
    {
        return new ObjectCreator<Interface, Obj>( info );
    }
};

}



#endif // SUB_PLUGIN_CREATOR_H
