#include "gameoverwindow.h"

/**
 * @brief GameOverWindow::GameOverWindow
 * Konstruktor für die Klasse, notwendiger Speicher wir bereitgestellt.
 *
 * QLabel ranking kriegt die WordWrap Option, damit die ausgabe des Textes
 * untereinander stattfindet.
 *
 * Bei den QPushButtons endGame und newGame, werden die clicked()-Signale mit
 * den Signalen der Klasse verbunden, damit andere Widget die Information erhalten
 * ob ein Neues Spiel gestartet oder das Spiel beendet werden soll.
 */
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

/**
 * @brief GameOverWindow::setScore
 * Eine Integer Variable score wird übermittelt, damit sie später
 * im QLabel text angezeigt werden kann.
 *
 * @param score enhält die Punktzahl vom aktuellen Spiel
 */
void GameOverWindow::setScore(int score)
{
    mScore = score;
}

/**
 * @brief GameOverWindow::printText
 * Erstellt einen Text mit dem aktuellen Namen und Punkten
 */
void GameOverWindow::printText()
{
    mName = insertName->text();
    QString score = QString::number(mScore);

    QString s = "Glückwunsche " + mName + " du hast Punkte " + score + " erreicht!";

    text->setText(s);
}

/**
 * @brief GameOverWindow::printLeaderBoard
 * Erstellt eine liste der 5 Besten Spieler
 */
void GameOverWindow::printLeaderBoard()
{
    User users[5];
    QString rankings;

    leaderBoard->insertRaninking(mName, mScore);
    leaderBoard->printRankings(users);
    leaderBoard->closeConn();

    for (int i = 0; i < 5; i++) {
        QString temp = QString("%1. Platz: %2 mit %3 Punkten!").arg(i+1)
                .arg(users[i].getName())
                .arg(users[i].getScore())
                + "\n";

        rankings.append(temp);
        qDebug() << temp;
    }

    ranking->setText(rankings);
}

/**
 * @brief GameOverWindow::slotAcceptInput
 * Slot wird ausgefühlt, sobald der Spieler auf den QPushButton okName klicked.
 * Nach dem klicken, werden die Felder deaktiviert, sodass nur ein Name eingetragen kann.
 * Dannach wird ein Text angezeigt, der den Spielername und seine Punkte enthält.
 * Zudem werden die 5 Besten Spieler angezeigt.
 */
void GameOverWindow::slotAcceptInput() {


    insertName->setDisabled(true);
    okName->setDisabled(true);

    printText();
    printLeaderBoard();
}
