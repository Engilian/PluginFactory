#include "plugin_info.h"
using namespace psys;

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QCryptographicHash>

#include "iplugin.h"

namespace  {

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

PluginInfo::PluginInfo():
    _uid(),
    _path (),

    _plugin ()
{

}

PluginInfo::PluginInfo(std::shared_ptr<IPlugin> plugin, const QString &path):
//    _uid ( "{" + plugin->name () + ":[" + fileChecksum ( path ) + "]}" ),
    _uid ( fileChecksum ( path ) ),
    _path ( path ),

    _plugin ( plugin )
{

}

PluginInfo::PluginInfo(const PluginInfo &info):
    _uid ( info._uid ),
    _path ( info._path ),

    _plugin ( info._plugin )
{

}

PluginInfo::~PluginInfo()
{

}

QString PluginInfo::uid() const
{
    return _uid;
}

QString PluginInfo::fileName() const
{
    return QFileInfo( _path ).baseName ();
}

QString PluginInfo::absoluteFilePath() const
{
    return QFileInfo( _path ).absoluteFilePath ();
}

std::shared_ptr<IPlugin> PluginInfo::plugin() const
{
    return _plugin;
}
