QT += widgets
QT += sql


TRANSLATIONS += cloudrain_fr.ts
TRANSLATIONS += cloudrain_en.ts
TRANSLATIONS += cloudrain_pt.ts
TRANSLATIONS += cloudrain_ar.ts

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_DEBUG += -Og
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    db/management.cpp \
    db/schema.cpp \
    gui/loading.cpp \
    gui/mainwindow.cpp \
    main.cpp \
    gui/connection.cpp \
    gui/menu.cpp \
    gui/options.cpp \
    gui/windowanimation.cpp \

SOURCES += \
    ../../core/utility.cpp \
    ../../core/file.cpp \
    ../../core/jsonparser.cpp \
    ../../core/xmlparser.cpp \

HEADERS += \
    db/management.h \
    db/schema.h \
    gui/global.h \
    gui/loading.h \
    gui/mainwindow.h \
    gui/connection.h \
    gui/menu.h \
    gui/options.h \
    gui/windowanimation.h \

HEADERS += \
    ../../core/utility.h \
    ../../core/file.h \
    ../../core/jsonparser.h \
    ../../core/xmlparser.h \


RESOURCES += \
    db/SQLite.txt \
    ../../license.txt \
    ../../license.html \
    ../../README.md \
