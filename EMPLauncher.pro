QT += core gui widgets webkitwidgets network
CONFIG += c++11

OBJECTS_DIR = obj
MOC_DIR = moc
UI_DIR = ../../include/ui

INCLUDEPATH += include

HEADERS += \
    include/globals.h \
    include/launcher.h \
    include/net/downloader.h \
    include/net/loginservice.h \
    include/sessions/session.h \
    include/sessions/sessionmanager.h \
    include/util/listitem.h \
    include/modpacks/modpack.h \
    include/modpacks/modpackmanager.h \
    include/util/jsonsettings.h \
    include/net/installer.h

SOURCES += \
    main.cpp \
    src/launcher.cpp \
    src/net/downloader.cpp \
    src/net/loginservice.cpp \
    src/sessions/session.cpp \
    src/sessions/sessionmanager.cpp \
    src/modpacks/modpack.cpp \
    src/modpacks/modpackmanager.cpp \
    src/util/listitem.cpp \
    src/util/jsonsettings.cpp \
    src/net/installer.cpp

FORMS += \
    ui/launcher.ui \
    ui/login.ui
