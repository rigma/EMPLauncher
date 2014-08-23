QT += core gui widgets network
CONFIG += c++11
UI_DIR = include\ui

INCLUDEPATH += include

HEADERS += \
    include/globals.h \
    include/sessionmanager.h \
    include/launcher.h \
    include/net/downloader.h \
    include/net/loginservice.h \
    include/sessions/session.h \
    include/sessions/sessionmanager.h \
    include/util/settings.h

SOURCES += \
    src/settings.cpp \
    main.cpp \
    src/session.cpp \
    src/sessionmanager.cpp \
    src/loginservice.cpp \
    src/launcher.cpp \
    src/net/downloader.cpp \
    src/net/loginservice.cpp \
    src/sessions/session.cpp \
    src/sessions/sessionmanager.cpp \
    src/util/settings.cpp

FORMS += \
    ui/launcher.ui
