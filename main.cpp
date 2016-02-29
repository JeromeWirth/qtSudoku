#include <QtWidgets>

#include "boardwidget.h"
#include "scorewidget.h"
#include "timerwidget.h"
#include "mainwindow.h"
#include "sudokusolver.h"
#include "sudokuitem.h"
#include "QGraphicsView"
#include "QGraphicsScene"
#include "QTableWidget"
#include "sudokuboard.h"
#include "sudokuwidget.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);


//    BoardWidget *sudoku = new BoardWidget();
//    sudoku->show();

//    MainWindow window;
//    window.show();

//    QHBoxLayout *hjLayout = new QHBoxLayout;
//    QVBoxLayout *vLayout = new QVBoxLayout;

//    ScoreWidget *testScore = new ScoreWidget;
//    TimerWidget *testTime = new TimerWidget;

//    hjLayout->addWidget(testScore);
//    hjLayout->addWidget(testTime);

//    vLayout->addLayout(hjLayout);
//    vLayout->addWidget(sudoku);

//    QWidget *w = new QWidget();
//    w->setLayout(vLayout);
//    w->setWindowTitle("TEST");
//    w->show();

//    TimerWidget *test = new TimerWidget;
//    test->show();




//    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
//                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
//                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
//                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
//                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
//                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
//                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
//                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
//                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

//    int grid2[9][9] = {0};


//    SudokuSolver s;
//    s.copyGrid(grid2);
//    s.initPreSetSudoku();

//    if (s.solveSudoku()) {
//        s.createUnsolvedBoard();
//        s.printGrid(1);
//        s.printGrid(0);
//    } else {
//        cout << "No Solution found!" << endl;
//    }


    SudokuWidget *test = new SudokuWidget();
    test->show();

    return app.exec();
}
