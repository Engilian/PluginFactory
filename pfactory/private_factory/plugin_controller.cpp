#include "plugin_controller.h"
using namespace pf;

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QFileInfo>
#include <QPluginLoader>
#include <QCoreApplication>
#include <QCryptographicHash>

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



class PluginController::Loader
{
public:
  struct LoadResult
  {
    bool        ok = false;
    PluginData  data;
    QString     errorString;
  };
private:
  QString                     _pluginDirectoryPath;
  bool                        _isRecursiveLoad;
  QHash<QString, PluginData>  _plugins;
public:
  Loader()
    : _pluginDirectoryPath(
        QDir::fromNativeSeparators( QCoreApplication::applicationDirPath() + "/plug" ) )
    , _isRecursiveLoad( true )
  {

  }
  ~Loader()
  {

  }

public:
  QString pluginDirPath() const
  {
    return  _pluginDirectoryPath;
  }

  void setPluginDirPath( const QString &path )
  {
    _pluginDirectoryPath = path;

    QDir d( _pluginDirectoryPath );

    if ( !d.exists () ) {

      d.mkpath ( "." );
    }
  }

public:
  bool isRecursiveLoad() const
  {
    return _isRecursiveLoad;
  }
  void setRecursiveLoad( bool enable )
  {
    _isRecursiveLoad = enable;
  }

public:
  QList<PluginData> allPluginsList() const
  {
    QList<PluginData> plugins;

    QStringList pathes = _findPluginFiles( _pluginDirectoryPath, _isRecursiveLoad );

    for ( const QString &path: pathes ) {
      auto p  = _loadPlugin( path );

      if ( p.ok ) {
        plugins << p.data;
      }
    }

    return plugins;
  }

public:
  void loadAllPlugins()
  {
    loadPluginList ( _findPluginFiles( _pluginDirectoryPath, _isRecursiveLoad ) );
  }
  LoadResult loadPlugin(const QString &pluginPath)
  {
    auto result = _loadPlugin( pluginPath );

    if ( result.ok ) {

      // Check is loaded plugin
      if ( _plugins.contains( result.data.uid() ) ) {
        result.ok = false;
        result.errorString = "Plugin is already loaded";
      }

      // Add plugin to data
      else {
        _plugins[ result.data.uid() ] = result.data;
      }
    }

    return result;
  }
  QList<LoadResult> loadPluginList(const QStringList &pathes )
  {
    QList<LoadResult> result;
    for ( const QString &path: pathes )
      result << loadPlugin( path );
    return result;
  }
  QList<PluginData> loadedPlugins() const
  {
    return _plugins.values();
  }

public:
  void freeLoadedPlugins()
  {
    _plugins.clear();
  }
  void freePlugin( const QString &pluginId )
  {
    if ( _plugins.contains( pluginId ) ) {

      _plugins.remove( pluginId );
    }
  }

private:
  QStringList _findPluginFiles(const QString &dirPath, bool recursive) const
  {
#ifdef __unix__
    QStringList filter{ "*.so","*,SO","*.So" };
#else
    QStringList filter{ "*.dll", "*.DLL", "*.Dll" };
#endif
    QDir directory = QDir::fromNativeSeparators( dirPath );

    QStringList result;
    if ( !directory.exists() ) {

      qDebug() << "Directory " + directory.absolutePath() + " not exists";
      return result;
    }

    for ( const QString &name: directory.entryList ( filter, QDir::Files ) ) {

      result << directory.absoluteFilePath( name );
    }

    if ( recursive ) {

      for ( const QString &name: directory.entryList( QDir::Dirs ) ) {

        QString dirName = QDir::cleanPath( name );

        if ( dirName.length () >= 3 ) {

          if ( !dirName.isEmpty() && directory.exists( dirName ) ) {

            result << directory.absolutePath() + "/" + dirName;
          }

        }
      }

    }

    return result;
  }

  ///
  /// \brief Load plugin
  /// \param path plugin path
  /// \return if the pointer to the plug-in is successful, otherwise empty
  ///
  LoadResult _loadPlugin(const QString &path) const
  {
    QPluginLoader loader( path );

    LoadResult result;
    result.ok   = false;
    result.data = PluginData( Plugin(), path );

    if ( loader.load() ) {
      auto *p = qobject_cast<IPlugin *>( loader.instance() );

      if ( !!p ) {
        result.ok   = true;
        result.data = PluginData( Plugin( p ), path );
        return result;
      } else {
        result.errorString = "Error create plugin instance";
      }
    }
    else {
      result.errorString = loader.errorString();
      qDebug() << "error load plugin: " << QFileInfo( path ).fileName () << ":"
                   << loader.errorString ();
    }

    return result;
  }
};

PluginController::PluginController()
  : _loader( std::make_shared<Loader>() )
{
  _loader->loadAllPlugins();
}

PluginController::~PluginController()
{

}

QList<pf::PluginData> PluginController::plugins() const
{
  return _loader->loadedPlugins ();
}

QList<Creator> PluginController::creators(const QString &interface) const
{
  QList<pf::Creator> result;
  for ( auto data: _loader->allPluginsList() ) {
    for ( auto &creator: data.plugin()->creators() ) {
      if ( interface.compare( creator->interface() ) == 0 ) {
        result << creator;
      }
    }
  }

  return result;
}
