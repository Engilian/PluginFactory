#   Factory plugin library
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../FactoryPlugin/bin/ -lFactoryPlugin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../FactoryPlugin/bin/ -lFactoryPlugin
else:unix: LIBS += -L$$OUT_PWD/../FactoryPlugin/bin/ -lFactoryPlugin

INCLUDEPATH += $$PWD/FactoryPlugin
DEPENDPATH += $$PWD/FactoryPlugin

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/libFactoryPlugin.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/libFactoryPlugin.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/FactoryPlugin.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/FactoryPlugin.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../FactoryPlugin/bin/libFactoryPlugin.a
