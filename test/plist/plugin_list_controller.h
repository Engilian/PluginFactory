#ifndef PLUGIN_LIST_CONTROLLER_H
#define PLUGIN_LIST_CONTROLLER_H

#include <QtCore/QObject>

class PluginListController : public QObject
{
    Q_OBJECT
public:
    explicit PluginListController(QObject *parent = nullptr);
    ~PluginListController();
protected:
    void timerEvent( QTimerEvent * );
public:

signals:

public slots:
};

#endif // PLUGIN_LIST_CONTROLLER_H
