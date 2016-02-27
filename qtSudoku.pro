TEMPLATE = app
TARGET = sudoku

QT = core gui
QT += widgets multimedia

SOURCES += \
    main.cpp \
    boardwidget.cpp \
    scorewidget.cpp \
    scorelogic.cpp \
    timerwidget.cpp \
    mainwindow.cpp \
    sudokusolver.cpp \
    sudokuitem.cpp \
    sudokuwidget.cpp

HEADERS += \
    boardwidget.h \
    scorewidget.h \
    scorelogic.h \
    timerwidget.h \
    mainwindow.h \
    sudokusolver.h \
    sudokuitem.h \
    sudokuwidget.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

RESOURCES += \
    files.qrc
