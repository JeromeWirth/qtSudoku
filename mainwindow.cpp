#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    createMenu();
    createScoreAndTimeBox();
    createControlGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(scoreAndTimeBox);

    board = new BoardWidget();

    mainLayout->addWidget(board);
    mainLayout->addWidget(controlGroupBox);

    setLayout(mainLayout);
    setWindowTitle(tr("qtSudoku"));

    connect(newSudokuAction, SIGNAL(triggered()), board, SLOT(slotCreateNewSudoku()));
}

void MainWindow::createMenu() {
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);

    exitAction = fileMenu->addAction(tr("E&xit"));
    newSudokuAction = fileMenu->addAction(tr("New Sudoku"));

    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void MainWindow::createScoreAndTimeBox() {
    scoreAndTimeBox = new QGroupBox(tr("Score and Time"));
    QHBoxLayout *layout = new QHBoxLayout;

    score = new ScoreWidget();
    timer = new TimerWidget();

    layout->addWidget(score);
    layout->addWidget(timer);

    scoreAndTimeBox->setLayout(layout);
}

void MainWindow::createControlGroupBox() {
    controlGroupBox = new QGroupBox(tr("Controls"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < 9; ++i) {
        buttons[i] = new QPushButton(tr("%1").arg(i+1));
        layout->addWidget(buttons[i]);
    }

    controlGroupBox->setLayout(layout);
}

