/*
 * In the MainWindow everything comes together, it has a MenuBar,
 * in which the user can start a new sudoku, solve the current one or
 * exit the game.
 *
 * The MainWindow has two sections: The Timer and Score Box and the SudokuBoard
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 582939
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QMenuBar>
#include <QGroupBox>
#include <QMediaPlayer>

#include "sudokuwidget.h"
#include "timerwidget.h"
#include "scorewidget.h"
#include "gameoverwindow.h"
#include "newgamewindow.h"


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();

private:
    void createMenu();
    void createScoreAndTimeBox();
    void createNewGamePopup();

    QMenuBar        *menuBar;
    QGroupBox       *scoreAndTimeBox;
    QGroupBox       *controlGroupBox;

    QMenu           *fileMenu;
    QAction         *exitAction;
    QAction         *newSudokuAction;
    QAction         *solveSudokuAction;
    QMediaPlayer    *mediaPlayer;

    TimerWidget     *timer;
    ScoreWidget     *score;
    SudokuWidget    *sudoku;
    NewGameWindow   *newGame;
    GameOverWindow  *gameOver;


signals:
    void signalNewGame(QString difficult);

public slots:
    void slotFinishGame();
    void slotNewGame();
    void slotSuccessSound();
    void slotFailSound();
};

#endif // MAINWINDOW_H
