#include "newgamewindow.h"

/**
 * @brief NewGameWindow::NewGameWindow
 * Erstellt ein Fenster, welches den Spieler nach dem Schwierigkeitsgrad fragt.
 * Je nachdem welcher Knopf gedrückt wurde, wird ein Signal mit varrierender ID
 * ausgesendet.
 */
NewGameWindow::NewGameWindow()
{
    text = new QLabel("Schwierigkeitsgrad wählen:");
    easyGame = new QPushButton("Leicht");
    normalGame = new QPushButton("Normal");
    hardGame = new QPushButton("Schwer");
    buttonGroup = new QButtonGroup();

    buttonGroup->addButton(easyGame);
    buttonGroup->addButton(normalGame);
    buttonGroup->addButton(hardGame);

    buttonLayout = new QHBoxLayout;
    layout = new QVBoxLayout;

    setWindowTitle("Neues Spiel");

    buttonLayout->addWidget(easyGame);
    buttonLayout->addWidget(normalGame);
    buttonLayout->addWidget(hardGame);

    layout->addWidget(text);
    layout->addLayout(buttonLayout);

    setLayout(layout);

    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SIGNAL(signalNewGame(int)));
    connect(buttonGroup, SIGNAL(buttonClicked(int)), this, SLOT(close()));
}


