#pragma once
#include <QMap>
#include "iplugin.h"


namespace pf
{
  class TemplatePlugin
      : public pf::IPlugin
  {
    QList<Creator> m_creators;
  protected:
    TemplatePlugin();
  public:
    virtual ~TemplatePlugin();

  protected:
    template<class Interface, class Obj>
    bool regCreator(const QString &id, const QString &interface)
    {
      for ( auto &c: m_creators )
        if ( c->id() == id && c->interface() == interface )
          return false;

      m_creators.append( std::make_shared<ObjectCreator<Interface, Obj>(id, interface)>() );
      return true;
    }

    // IPlugin interface
  public:
    virtual QList<Creator> creators() const override;
  };

}
