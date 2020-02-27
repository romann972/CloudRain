QT += network
QT += core

SOURCES += \
    main.cpp \
    socket/tcpclient.cpp \
    socket/tcpserver.cpp

HEADERS += \
    socket/global.h \
    socket/tcpclient.h \
    socket/tcpserver.h
