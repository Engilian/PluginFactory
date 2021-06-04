#pragma once
#include <QString>

namespace psys
{

  ///
  /// \brief Information about the sub plugin
  ///
  struct SubPluginInfo final
  {
    ////
    /// \brief Sub plugin id
    ///
    const QString id;

    ///
    /// \brief ID of the implementing interface
    ///
    const QString interfaceId;

    // constructs
    SubPluginInfo();
    SubPluginInfo(const QString &id,
                   const QString &interface);
    SubPluginInfo(const SubPluginInfo &info);

    // methods
    bool isValid() const;

    // Operators
    bool operator==(const QString &id) const;
    bool operator!=(const QString &id) const;

    bool operator==(const SubPluginInfo &info) const;
    bool operator!=(const SubPluginInfo &info) const;

    bool operator>(const SubPluginInfo &info) const;
    bool operator<(const SubPluginInfo &info) const;
  };

}
