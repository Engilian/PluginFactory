#pragma once
#include <QMap>
#include "psys/iplugin.h"
#include "sub_plugin_creator.h"


namespace pf
{
  class TemplatePlugin
      : public pf::IPlugin
  {
    QMap<QString, SubPluginCreator *> creators;
  protected:
    TemplatePlugin();
  public:
    virtual ~TemplatePlugin();
  public:
    virtual QList<pf::SubPluginInfo> subPluginInfoList() const Q_DECL_OVERRIDE;
    virtual pf::ISubPlugin *create(const QString &id) const Q_DECL_OVERRIDE;

  protected:
    template<class Interface, class Obj>
    bool regCreator(const pf::SubPluginInfo &info)
    {
      if ( creators.contains ( info.id ) ) {
        return false;
      }

      creators[ info.id ] = new TemplateSubPluginCreator<Interface, Obj>( info );
      return true;
    }

    template<class Interface, class Obj>
    bool regCreator(const QString &id, const QString &interface)
    {
      pf::SubPluginInfo pInfo ( id, interface );
      return regCreator<Interface, Obj>( pInfo );
    }
  };

}
