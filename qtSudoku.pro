TEMPLATE = app
TARGET = sudoku

QT = core gui
QT += widgets

SOURCES += \
    main.cpp \
    boardwidget.cpp \
    boardlogic.cpp \
    scorewidget.cpp \
    scorelogic.cpp \
    timerwidget.cpp \
    mainwindow.cpp

HEADERS += \
    boardwidget.h \
    boardlogic.h \
    scorewidget.h \
    scorelogic.h \
    timerwidget.h \
    mainwindow.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x
