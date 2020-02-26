QT += widgets
QT += sql


TRANSLATIONS += cloudrain_fr.ts
TRANSLATIONS += cloudrain_en.ts

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_DEBUG += -Og
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    db/management.cpp \
    db/schema.cpp \
    gui/mainwindow.cpp \
    main.cpp \
    gui/connection.cpp \
    gui/menu.cpp \
    gui/options.cpp

HEADERS += \
    db/management.h \
    db/schema.h \
    gui/global.h \
    gui/mainwindow.h \
    gui/connection.h \
    gui/menu.h \
    gui/options.h
