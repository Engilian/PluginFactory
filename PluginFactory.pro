#######################################
#                                     #
#                                     #
#                                     #
#######################################

TEMPLATE    =   subdirs
CONFIG      += ordered

# Projects
SUBDIRS     +=  \
    src/libs    \
    src/plugins \
    src/tests   \
    src/tools

#src/plugins.depends = src/libs
#src/test.depends    = src/libs

# Installs
