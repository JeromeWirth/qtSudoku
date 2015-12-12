TEMPLATE = app
TARGET = sudoku

QT = core gui
QT += widgets

SOURCES += \
    main.cpp \
    boardwidget.cpp \
    boardlogic.cpp \
    timer.cpp

HEADERS += \
    boardwidget.h \
    boardlogic.h \
    timer.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x
