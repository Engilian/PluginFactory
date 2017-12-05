#ifndef ICONSOLE_CONTROLLER_H
#define ICONSOLE_CONTROLLER_H

#include <QtCore/QObject>

///
/// \brief Application Behavior Management
///
class IConsoleController : public QObject
{
    Q_OBJECT
protected:
    explicit IConsoleController(QObject *parent = nullptr);
public:
    virtual ~IConsoleController();
public:
    ///
    /// \brief Command handler
    /// \param command entered in the console command line
    ///
    virtual void handler( const QString &command ) = 0;

    ///
    /// \brief Processing the selection of this object
    ///
    virtual void onSeleceted() = 0;

    ///
    /// \brief Processing cancellation of the selection of this object
    ///
    virtual void onUnselect() = 0;
signals:
    ///
    /// \brief Transition signal
    /// \param controllerId identifier
    ///
    void GotoView( const QString &controllerId );
};

#endif // ICONSOLE_CONTROLLER_H
