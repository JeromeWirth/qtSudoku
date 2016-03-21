/**
  * In der MainWindow-Klasse kommt alles zusammen, sie besteht
  * aus einer Menüleiste, in der der Spieler ein neues Soduku starten,
  * das aktuelle Sudoku lösen oder das Programm beenden kann.
  *
  * Das Hauptfenster ist unterteilt in der Punkt und Zeitanzeige, sowie
  * dem Sudoku Feld.
  *
  * @author Jerome Wirth (532939)
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
