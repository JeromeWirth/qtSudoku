#include "mainwindow.h"

MainWindow::MainWindow()
{
    board = new BoardWidget();

    createMenu();
    createScoreAndTimeBox();
    createControlGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(scoreAndTimeBox);

    mainLayout->addWidget(board);
    mainLayout->addWidget(controlGroupBox);

    connect(board, SIGNAL(signalCorrectNumber()), score, SLOT(slotCorrectNumber()));
    connect(board, SIGNAL(signalFalseNumber()), score, SLOT(slotFalseNumber()));
    connect(timer, SIGNAL(signal5ScondsPass()), score, SLOT(slotDecreaseMultiplier()));
    connect(board, SIGNAL(signalNewSudoku()), score, SLOT(slotResetScore()));
    connect(board, SIGNAL(signalNewSudoku()), timer, SLOT(slotResetTimer()));

    setLayout(mainLayout);
    setWindowTitle(tr("qtSudoku"));
}

void MainWindow::createMenu() {
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);

    exitAction = fileMenu->addAction(tr("E&xit"));
    newSudokuAction = fileMenu->addAction(tr("N&ew Sudoku"));

    menuBar->addMenu(fileMenu);

    connect(newSudokuAction, SIGNAL(triggered()), board, SLOT(slotCreateNewSudoku()));
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

