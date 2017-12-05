#ifndef MAIN_CONSOLE_VIEW_H
#define MAIN_CONSOLE_VIEW_H

#include "iconsole_controller.h"

class MainConsoleView : public IConsoleController
{
    Q_OBJECT
public:
    explicit MainConsoleView(QObject *parent = nullptr);
    ~MainConsoleView();
public:
    void handler( const QString &command );
    void onSeleceted();
    void onUnselect();
signals:

public slots:
};

#endif // MAIN_CONSOLE_VIEW_H
