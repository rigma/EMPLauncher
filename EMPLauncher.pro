QT += core gui widgets network
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
    include/util/settings.h \
    include/util/listitem.h

SOURCES += \
    main.cpp \
    src/launcher.cpp \
    src/net/downloader.cpp \
    src/net/loginservice.cpp \
    src/sessions/session.cpp \
    src/sessions/sessionmanager.cpp \
    src/util/settings.cpp

FORMS += \
    ui/launcher.ui
