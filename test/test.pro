QT += core

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_DEBUG += -Og
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    main.cpp \
    ../core/utility.cpp \

HEADERS += \
    ../core/utility.h \
