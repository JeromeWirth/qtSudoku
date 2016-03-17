#ifndef GAMEOVERWINDOW_H
#define GAMEOVERWINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class GameOverWindow : public QDialog
{
    Q_OBJECT

public:
    GameOverWindow();
    void setText();


private:
    QString m_name;
    int m_score;

    QHBoxLayout *buttonLayout;
    QHBoxLayout *playerLayout;
    QVBoxLayout *layout;
    QLabel      *text;
    QPushButton *endGame;
    QPushButton *newGame;
    QPushButton *okName;
    QLabel      *askName;
    QLineEdit   *insertName;

signals:
    void signalEndGame();
    void signalNewGame();

public slots:
    void slotAcceptInput();
};

#endif // GAMEOVERWINDOW_H
