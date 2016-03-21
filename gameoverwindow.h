/**
  * GameOverWinow wird angezeigt, nachdem das Sudoku beendet wurde.
  * Dabei ist es nicht wichtig, ob der Spieler das spiel selber gelöst hat,
  * oder er es vom Computer hat lösen lassen.
  *
  * Das Fenster fragt den Spieler nach seinem Namen, bei Eingabe wird
  * der Name des Spielers, sowie seine Punktzahl angezeigt, darunter
  * werden die 5 besten Spieler angezeigt.
  *
  * Der Spieler hat dann die möglichkeit ein neues Sudoku zu starten,
  * oder das Programm zu beenden.
  *
  * @author Jerome Wirth (532939)
  */
#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include "leaderboard.h"
#include "user.h"

class GameOverWindow : public QDialog
{
    Q_OBJECT

public:
    GameOverWindow();
    void setScore(int score);

private:
    QString mName;
    int mScore;

    QHBoxLayout *buttonLayout;
    QHBoxLayout *playerLayout;
    QVBoxLayout *layout;
    QLabel      *text;
    QLabel      *ranking;
    QPushButton *endGame;
    QPushButton *newGame;
    QPushButton *okName;
    QLabel      *askName;
    QLineEdit   *insertName;
    LeaderBoard *leaderBoard;

    void printText();
    void printLeaderBoard();

signals:
    void signalEndGame();
    void signalNewGame();

public slots:
    void slotAcceptInput();
};

#endif // GAMEOVERWINDOW_H
