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
