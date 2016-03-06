#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QMenuBar>
#include <QGroupBox>

#include "sudokuwidget.h"
#include "timerwidget.h"
#include "scorewidget.h"

class MainWindow : public QDialog
{
public:
    MainWindow();

private:
    void createMenu();
    void createScoreAndTimeBox();
    void createControlGroupBox();

    QMenuBar *menuBar;
    QGroupBox *scoreAndTimeBox;
    QGroupBox *controlGroupBox;
    QButtonGroup *buttonGroup;
    QPushButton *buttons[9];

    QMenu *fileMenu;
    QAction *exitAction;
    QAction *newSudokuAction;
    TimerWidget *timer;
    ScoreWidget *score;
    SudokuWidget *sudoku;


signals:

public slots:
};

#endif // MAINWINDOW_H
