#ifndef IPFACTORY_PLUGIN_H
#define IPFACTORY_PLUGIN_H

#include <QString>
#include <QObject>
#include <memory>

#include "isub_plugin.h"

#define FACTORY_PLUGIN_VALID_STRING \
    "ru.engilian@gmail.com.FactoryPlugin/1.0"

namespace psys {

class IPlugin;
using Plugin = std::shared_ptr<IPlugin>;

///
/// \brief Interface Plagin for Factory
///
class IPlugin
{
protected:
    IPlugin();
public:
    virtual ~IPlugin();
public: // Plagin info

    ///
    /// \brief Plagin name
    /// \return string name
    ///
    virtual QString name() const = 0;

    ///
    /// \brief Way to logo
    /// \return way to the logo picture
    ///
    virtual QString logo() const = 0;

    ///
    /// \brief Brief information about plugin
    /// \details Use the text of the html page
    /// \return html string
    ///
    virtual QString briefInfo() const = 0;

    ///
    /// \brief Detailed information about plugin
    /// \details Use the text of the html page
    /// \return html string
    ///
    virtual QString detailedInfo() const = 0;

    ///
    /// \brief Author plugin
    /// \return string author
    ///
    virtual QString author() const = 0;

    ///
    /// \brief Plugin version
    /// \details The versions are compared in the
    /// bool IPFactoryPlugin::versionComparer( const QString & ) const method
    /// \return string version
    ///
    virtual QString version() const = 0;
public:
    ///
    /// \brief Compare versions
    /// \param v versionPlugin
    /// \return if the version of the plugin is greater than the current true,
    ///  otherwise it is false
    ///
    virtual bool versionComparer( const QString &v ) const;
public:
    ///
    /// \brief List of information implemented plugins
    /// \return list information
    ///
    virtual QList<SubPluginInfo> subPluginInfoList() const = 0;

    ///
    /// \brief Create a sub plugin
    /// \param id sub plugin id
    /// \warning If there is no sub plug-in, it returns nullptr
    /// \return sub plugin
    ///
    virtual ISubPlugin *create( const QString &id ) const = 0;

    ///
    /// \brief Create a sub plugin
    /// \param info information implemented plugin
    /// \warning If there is no sub plug-in, it returns nullptr
    /// \return sub plugin
    ///
    virtual ISubPlugin *create( const SubPluginInfo &info ) const;

};

}

Q_DECLARE_INTERFACE( psys::IPlugin, FACTORY_PLUGIN_VALID_STRING );


#endif // IPFACTORY_PLUGIN_H
