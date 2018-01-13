TEMPLATE = subdirs

SUBDIRS += \
    plist


#   Installs
TEST_INSTALL_DIR = $$OUT_PWD/../../bin/

plug_list.path   = $$TEST_INSTALL_DIR
plug_list.files  = $$OUT_PWD/plist/bin/*

INSTALLS += plug_list
