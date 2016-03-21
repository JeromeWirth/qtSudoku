TEMPLATE = app
TARGET = sudoku

QT = core gui
QT += widgets multimedia sql

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
    sudokuloader.cpp \
    gameoverwindow.cpp \
    newgamewindow.cpp \
    randompathgenerator.cpp \
    leaderboard.cpp \
    user.cpp

HEADERS += \
    scorewidget.h \
    scorelogic.h \
    timerwidget.h \
    mainwindow.h \
    sudokusolver.h \
    sudokuitem.h \
    sudokuboard.h \
    sudokuwidget.h \
    sudokuloader.h \
    gameoverwindow.h \
    newgamewindow.h \
    randompathgenerator.h \
    leaderboard.h \
    user.h

CONFIG += c++11
#CONFIG -= app_bundle

#QMAKE_CXXFLAGS += -std=c++0x

RESOURCES += \
    files.qrc
