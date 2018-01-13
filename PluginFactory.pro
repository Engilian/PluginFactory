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
    src/test \

#src/plugins.depends = src/libs
#src/test.depends    = src/libs

# Installs
