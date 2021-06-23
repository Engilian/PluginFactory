#pragma once
#include <memory>
#include <QString>
#include <QMetaClassInfo>

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
    QString id;

    ///
    /// \brief ID of the implementing interface
    ///
    QString interfaceId;

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
    ISubPlugin(SubPluginInfo info);
  public:
    virtual ~ISubPlugin();
  public:
    ///
    /// \brief Information about the sub plugin
    ///
    SubPluginInfo subPluginInfo() const;
  };

}
