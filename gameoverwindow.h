/*
 * GameOverWindow will be displayed, after the game is finished.
 * It is not important, if the User has finished it, or he choosed
 * to let it solve by the CPU.
 *
 * the GameOverWindow will ask the User for his name, and afte he entered
 * his name, his score will be displayed, and the top 5 players.
 *
 * After that, the user can choose to play a new game, or quit the game.
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 532939
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
    QString m_name;
    int m_score;

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

signals:
    void signalEndGame();
    void signalNewGame();

public slots:
    void slotAcceptInput();
};

#endif // GAMEOVERWINDOW_H
