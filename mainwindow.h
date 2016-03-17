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
#include "gameoverwindow.h"


class MainWindow : public QDialog
{
    Q_OBJECT

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
    GameOverWindow *gameOver;


signals:

public slots:
    void slotFinishGame();
};

#endif // MAINWINDOW_H
