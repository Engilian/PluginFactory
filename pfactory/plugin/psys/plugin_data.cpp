#include "plugin_data.h"
using namespace psys;

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QCryptographicHash>

#include "iplugin.h"

namespace
{

#ifndef QT_CRYPTOGRAPHICHASH_ONLY_SHA1
#define DEFAULT_UID_ALGORITM QCryptographicHash::Algorithm::Md5
#else
#define DEFAULT_UID_ALGORITM QCryptographicHash::Algorithm::Sha1
#endif

  inline QString fileChecksum(const QString &fileName,
                              QCryptographicHash::Algorithm hashAlgorithm = DEFAULT_UID_ALGORITM )
  {
    QFile f(fileName);
    if (f.open(QFile::ReadOnly)) {
      QCryptographicHash hash(hashAlgorithm);
      if (hash.addData(&f)) {

        return QString( hash.result().toHex () );
      }
    }
    return "";
  }

#undef DEFAULT_UID_ALGORITM

}

PluginData::PluginData()
  : m_uid()
  , m_path ()
  , m_plugin ()
{

}

PluginData::PluginData(std::shared_ptr<IPlugin> plugin, const QString &path)
  : m_uid ( fileChecksum ( path ) )
  , m_path ( path )
  , m_plugin ( plugin )
{

}

PluginData::PluginData(const PluginData &info)
  : m_uid ( info.m_uid )
  , m_path ( info.m_path )
  , m_plugin ( info.m_plugin )
{

}

PluginData::~PluginData()
{

}

QString PluginData::uid() const
{
  return m_uid;
}

QString PluginData::fileName() const
{
  return QFileInfo( m_path ).baseName ();
}

QString PluginData::absoluteFilePath() const
{
  return QFileInfo( m_path ).absoluteFilePath ();
}

std::shared_ptr<IPlugin> PluginData::plugin() const
{
  return m_plugin;
}
