#ifndef ISUB_PLUGIN_H
#define ISUB_PLUGIN_H

#include <QString>
#include <QMetaClassInfo>
#include <memory>

namespace psys {

class ISubPlugin;
using SubPlugin = std::shared_ptr<ISubPlugin>;

///
/// \brief Information about the sub plugin
///
struct SubPluginInfo {

    ////
    /// \brief Sub plugin id
    ///
    QString id;

    ///
    /// \brief ID of the implementing interface
    ///
    QString interfaceId;

    ///
    /// \brief Description of the sub plugin
    ///
    QString description;
};

///
/// \brief The ISubPlugin class
///
class ISubPlugin
{
protected:
    ISubPlugin( SubPluginInfo info );
public:
    virtual ~ISubPlugin();
public:
    ///
    /// \brief Information about the sub plugin
    ///
    SubPluginInfo subPluginInfo() const;
private:
    ///
    /// \brief Information about the sub plugin
    ///
    SubPluginInfo   _subPluginInfo;
};

}

#endif // ISUB_PLUGIN_H
