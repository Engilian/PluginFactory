#pragma once
#include <QString>
#include <QMetaClassInfo>
#include <memory>

#include "sub_plugin_info.h"

namespace psys {

class ISubPlugin;
using SubPlugin = std::shared_ptr<ISubPlugin>;



///
/// \brief The ISubPlugin class
///
class ISubPlugin
{
    ///
    /// \brief Information about the sub plugin
    ///
    SubPluginInfo   _subPluginInfo;
protected:
    ISubPlugin( SubPluginInfo info );
public:
    virtual ~ISubPlugin();
public:
    ///
    /// \brief Information about the sub plugin
    ///
    SubPluginInfo subPluginInfo() const;
};

}
