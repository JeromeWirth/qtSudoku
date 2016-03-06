TEMPLATE = app
TARGET = sudoku

QT = core gui
QT += widgets multimedia

SOURCES += \
    main.cpp \
    scorewidget.cpp \
    scorelogic.cpp \
    timerwidget.cpp \
    mainwindow.cpp \
    sudokusolver.cpp \
    sudokuitem.cpp \
    sudokuboard.cpp \
    sudokuwidget.cpp \
    sudokuloader.cpp

HEADERS += \
    scorewidget.h \
    scorelogic.h \
    timerwidget.h \
    mainwindow.h \
    sudokusolver.h \
    sudokuitem.h \
    sudokuboard.h \
    sudokuwidget.h \
    sudokuloader.h

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

RESOURCES += \
    files.qrc
