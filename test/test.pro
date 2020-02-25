QT += core

QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_DEBUG += -Og
QMAKE_CXXFLAGS += -std=c++17

SOURCES += \
    main.cpp \
    ../core/utility.cpp \
    ../core/xmlparser.cpp \
    ../core/jsonparser.cpp \
    ../core/file.cpp \

HEADERS += \
    ../core/utility.h \
    ../core/xmlparser.h \
    ../core/jsonparser.h \
    ../core/file.h \
