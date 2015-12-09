TEMPLATE = app
TARGET = sudoku

QT = core gui
QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    board.cpp \
    boardwidget.cpp \
    boardlogic.cpp

HEADERS += \
    window.h \
    board.h \
    boardwidget.h \
    boardlogic.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x
