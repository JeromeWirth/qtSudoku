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
#include "newgamewindow.h"


class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();

private:
    void createMenu();
    void createScoreAndTimeBox();
    void createControlGroupBox();
    void createNewGamePopup();

    QMenuBar *menuBar;
    QGroupBox *scoreAndTimeBox;
    QGroupBox *controlGroupBox;
    QButtonGroup *buttonGroup;
    QPushButton *buttons[9];

    QMenu *fileMenu;
    QAction *exitAction;
    QAction *newSudokuAction;
    NewGameWindow *newGame;

    TimerWidget *timer;
    ScoreWidget *score;
    SudokuWidget *sudoku;
    GameOverWindow *gameOver;


signals:
    void signalNewGame(QString difficult);

public slots:
    void slotFinishGame();
    void slotNewGame();
};

#endif // MAINWINDOW_H
