#   Plugin system
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PluginSystem/bin/ -lPluginSystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PluginSystem/bin/ -lPluginSystem
else:unix: LIBS += -L$$OUT_PWD/../PluginSystem/bin/ -lPluginSystem

INCLUDEPATH += $$PWD/PluginSystem
DEPENDPATH += $$PWD/PluginSystem

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/libPluginSystem.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/libPluginSystem.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/PluginSystem.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/PluginSystem.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../PluginSystem/bin/libPluginSystem.a

