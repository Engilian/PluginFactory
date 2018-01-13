TEMPLATE = subdirs

SUBDIRS += \
    TestPlugin


#   Installs
PLUG_INSTALL_DIR = $$OUT_PWD/../../bin/plug

test.path   = $$PLUG_INSTALL_DIR
test.files  = $$OUT_PWD/TestPlugin/bin/*

INSTALLS += test
