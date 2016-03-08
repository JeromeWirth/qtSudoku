#include "mainwindow.h"

MainWindow::MainWindow()
{
    sudoku = new SudokuWidget();

    createMenu();
    createScoreAndTimeBox();
    // createControlGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(scoreAndTimeBox);

    mainLayout->addWidget(sudoku);
    // mainLayout->addWidget(controlGroupBox);

    connect(sudoku, SIGNAL(signalCorrectNumber()), score, SLOT(slotCorrectNumber()));
    connect(sudoku, SIGNAL(signalFalseNumber()), score, SLOT(slotFalseNumber()));
    connect(timer, SIGNAL(signal5ScondsPass()), score, SLOT(slotDecreaseMultiplier()));
    connect(sudoku, SIGNAL(signalNewSudoku()), score, SLOT(slotResetScore()));
    connect(sudoku, SIGNAL(signalNewSudoku()), timer, SLOT(slotResetTimer()));
//    connect(buttonGroup, SIGNAL(buttonClicked(int)), board, SLOT(slotEnterNumber(int)));

    setLayout(mainLayout);
    setMinimumSize(550, 650);
    setMaximumSize(550, 650);
    setWindowTitle(tr("qtSudoku"));
}

void MainWindow::createMenu() {
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);

    newSudokuAction = fileMenu->addAction(tr("N&ew Sudoku"));
    exitAction = fileMenu->addAction(tr("E&xit"));

    menuBar->addMenu(fileMenu);

    connect(newSudokuAction, SIGNAL(triggered()), sudoku, SLOT(slotLoadSudoku()));
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
    buttonGroup = new QButtonGroup;
//    QPixmap bBackground(":/images/images/%1.png");

    for (int i = 0; i < 9; ++i) {
//        buttons[i] = new QPushButton(tr("%1").);
        buttons[i] = new QPushButton();
        buttons[i]->setIcon(QIcon(QPixmap(tr(":/files/images/%1button.png").arg(i+1))));
        buttons[i]->setIconSize(QSize(48, 48));
        buttons[i]->setFixedSize(QSize(48, 48));
        layout->addWidget(buttons[i]);
        buttonGroup->addButton(buttons[i]);
    }

    controlGroupBox->setLayout(layout);
}

