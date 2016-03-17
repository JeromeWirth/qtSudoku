#include "gameoverwindow.h"

GameOverWindow::GameOverWindow()
{
    text = new QLabel();
    endGame = new QPushButton("Spiel Beenden");
    newGame = new QPushButton("Neues Spiel");
    askName = new QLabel("Name:");
    insertName = new QLineEdit();
    okName = new QPushButton("OK");

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
    layout->addLayout(buttonLayout);

    this->setLayout(layout);

    connect(okName, SIGNAL(clicked(bool)), this, SLOT(slotAcceptInput()));
    connect(endGame, SIGNAL(clicked(bool)), this, SIGNAL(signalEndGame()));
    connect(newGame, SIGNAL(clicked(bool)), this, SIGNAL(signalNewGame()));
    connect(newGame, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void GameOverWindow::setText() {
    QString a = "Glückwunsche " + m_name + " du hast " + QString::number(m_score) + " Punkte erreicht!";

    text->setText(a);
}

void GameOverWindow::slotAcceptInput() {
    insertName->setDisabled(true);

    m_name = insertName->text();

    QString s = "Glückwunsche " + m_name + " du hast Punkte erreicht!";

    text->setText(s);
}
