QT += core gui widgets network
CONFIG += c++11

INCLUDEPATH += include

HEADERS += \
    include/settings.h \
    include/globals.h \
    include/downloader.h \
    include/loginservice.h \
    include/session.h \
    include/sessionmanager.h

SOURCES += \
    src/settings.cpp \
    main.cpp \
    src/downloader.cpp \
    src/session.cpp \
    src/sessionmanager.cpp \
    src/loginservice.cpp
