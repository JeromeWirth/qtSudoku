#include "gameoverwindow.h"

GameOverWindow::GameOverWindow()
{
    text        = new QLabel();
    endGame     = new QPushButton("Spiel Beenden");
    newGame     = new QPushButton("Neues Spiel");
    askName     = new QLabel("Name:");
    insertName  = new QLineEdit();
    okName      = new QPushButton("OK");
    leaderBoard = new LeaderBoard();
    ranking     = new QLabel;

    ranking->setWordWrap(true);

    playerLayout = new QHBoxLayout;
    buttonLayout = new QHBoxLayout;
    layout = new QVBoxLayout;

    insertName->setMaxLength(10);

    setWindowTitle("Glückwunsch");

    playerLayout->addWidget(askName);
    playerLayout->addWidget(insertName);
    playerLayout->addWidget(okName);

    buttonLayout->addWidget(newGame);
    buttonLayout->addWidget(endGame);

    layout->addLayout(playerLayout);
    layout->addWidget(text);
    layout->addWidget(ranking);
    layout->addLayout(buttonLayout);

    this->setLayout(layout);

    connect(okName, SIGNAL(clicked(bool)), this, SLOT(slotAcceptInput()));
    connect(endGame, SIGNAL(clicked(bool)), this, SIGNAL(signalEndGame()));
    connect(newGame, SIGNAL(clicked(bool)), this, SIGNAL(signalNewGame()));
    connect(newGame, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void GameOverWindow::setScore(int score)
{
    m_score = score;
}

void GameOverWindow::slotAcceptInput() {
    User users[5];
    QString rankings;

    insertName->setDisabled(true);
    okName->setDisabled(true);

    m_name = insertName->text();
    QString score = QString::number(m_score);

    QString s = "Glückwunsche " + m_name + " du hast Punkte " + score + " erreicht!";

    text->setText(s);

    leaderBoard->insertRaninking(m_name, m_score);
    leaderBoard->printRankings(users);
    leaderBoard->closeConn();

    for (int i = 0; i < 5; i++) {
        QString temp = QString("%1. Platz: %2 mit %3 Punkten!").arg(i+1).arg(users[i].getName()).arg(users[i].getScore())
                + "\n";
        rankings.append(temp);
        qDebug() << temp;
    }

    ranking->setText(rankings);
}
