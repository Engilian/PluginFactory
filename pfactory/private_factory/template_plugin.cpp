#include "template_plugin.h"
using namespace pf;
using namespace pf;

TemplatePlugin::TemplatePlugin()
  : IPlugin()
{
}

TemplatePlugin::~TemplatePlugin()
{
}

QList<Creator> TemplatePlugin::creators() const
{
  return m_creators;
}
