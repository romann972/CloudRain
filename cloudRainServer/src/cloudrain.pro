QT += widgets
QT += sql

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_DEBUG += -Og
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    db/management.cpp \
    db/schema.cpp \
    gui/mainwindow.cpp \
    main.cpp \
    gui/connection.cpp

HEADERS += \
    db/management.h \
    db/schema.h \
    gui/global.h \
    gui/mainwindow.h \
    gui/connection.h
