QT += widgets

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_DEBUG += -Og
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    gui/mainwindow.cpp \
    main.cpp \
    gui/connection.cpp

HEADERS += \
    gui/global.h \
    gui/mainwindow.h \
    gui/connection.h
