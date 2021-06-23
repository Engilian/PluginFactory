#pragma once
#include "psys/isub_plugin.h"
#include "object_creator.h"

namespace pf
{
  struct SubPluginCreator
  {
    const pf::SubPluginInfo info;
  protected:
    SubPluginCreator(const pf::SubPluginInfo &info);
  public:
    virtual ~SubPluginCreator();
  public:
    virtual pf::ISubPlugin *create() = 0;
  };


  template<class Interface, class Obj>
  class TemplateSubPluginCreator
      : public SubPluginCreator
  {
  public:
    TemplateSubPluginCreator( const pf::SubPluginInfo &info )
      : SubPluginCreator( info )
    {

    }
    ~TemplateSubPluginCreator()
    {

    }

  public:
    pf::ISubPlugin *create()
    {
      return new ObjectCreator<Interface, Obj>( info );
    }
  };
}
