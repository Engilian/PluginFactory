#pragma once
#include <QString>

namespace psys {

///
/// \brief Information about the sub plugin
///
struct SubPluginInfo final {

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

    // constructs
    SubPluginInfo();
    SubPluginInfo( const QString &id,
                   const QString &interface,
                   const QString &desc = 0 );
    SubPluginInfo( const SubPluginInfo &info );

    // Operators

    bool operator==( const QString &id ) const;
    bool operator!=( const QString &id ) const;

    bool operator==( const SubPluginInfo &info ) const;
    bool operator!=( const SubPluginInfo &info ) const;

    bool operator>( const SubPluginInfo &info ) const;
    bool operator<( const SubPluginInfo &info ) const;
};

}
