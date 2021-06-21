#include "template_plugin.h"
using namespace pf;
using namespace psys;

TemplatePlugin::TemplatePlugin()
  : IPlugin()
{

}

TemplatePlugin::~TemplatePlugin()
{
  QList<SubPluginCreator *> list = creators.values ();
  creators.clear ();

  while ( !list.isEmpty () ) {
    delete list.takeFirst ();
  }
}


QList<SubPluginInfo> pf::TemplatePlugin::subPluginInfoList() const
{
  QList<SubPluginInfo> result;

  for ( auto *s: creators )
    result << s->info;

  return result;
}

ISubPlugin *pf::TemplatePlugin::create(const QString &id) const
{
  return creators.contains ( id ) ? creators[ id ]->create(): nullptr;
}
