#include "mainwindow.h"

MainWindow::MainWindow()
{
    sudoku = new SudokuWidget();
    gameOver = new GameOverWindow();
    newGame = new NewGameWindow();

    createMenu();
    createScoreAndTimeBox();
    // createControlGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(scoreAndTimeBox);

    mainLayout->addWidget(sudoku);

    connect(sudoku, SIGNAL(signalCorrectNumber()), score, SLOT(slotCorrectNumber()));
    connect(sudoku, SIGNAL(signalFalseNumber()), score, SLOT(slotFalseNumber()));
    connect(sudoku, SIGNAL(signalNewSudoku()), score, SLOT(slotResetScore()));
    connect(sudoku, SIGNAL(signalNewSudoku()), timer, SLOT(slotResetTimer()));
    connect(sudoku, SIGNAL(signalFinishedGame()), this, SLOT(slotFinishGame()));
    connect(timer, SIGNAL(signal5ScondsPass()), score, SLOT(slotDecreaseMultiplier()));
    connect(gameOver, SIGNAL(signalEndGame()), qApp, SLOT(quit()));
    connect(gameOver, SIGNAL(signalNewGame()), this, SLOT(slotNewGame()));
    connect(newGame, SIGNAL(signalNewGame(int)), sudoku, SLOT(slotLoadSudoku(int)));

    setLayout(mainLayout);
    setMinimumSize(550, 650);
    setMaximumSize(550, 650);
    setWindowTitle(tr("qtSudoku"));
}

void MainWindow::createMenu() {
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);

    newSudokuAction = fileMenu->addAction(tr("Neus Sudoku"));
    solveSudokuAction = fileMenu->addAction(tr("Sudoku Lösen"));
    exitAction = fileMenu->addAction(tr("Beenden"));

    menuBar->addMenu(fileMenu);

    connect(newSudokuAction, SIGNAL(triggered()), this, SLOT(slotNewGame()));
    connect(solveSudokuAction, SIGNAL(triggered()), sudoku, SLOT(slotSolveSudoku()));
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

void MainWindow::slotFinishGame() {
    qDebug() << "FinishGame Score: " << score->getScore();
    gameOver->setScore(score->getScore());
    gameOver->exec();
}

void MainWindow::slotNewGame()
{
    newGame->exec();
}

