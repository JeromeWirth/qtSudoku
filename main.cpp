#include <QtWidgets>

#include "boardlogic.h"
#include "boardwidget.h"
#include "scorewidget.h"
#include "timerwidget.h"
#include "mainwindow.h"
#include "sudokucreator.h"
#include "sudokusolver.h"

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

//    SudokuCreator s;
////    s.initPreSetSudoku();
//    s.printSudoku();

//    if (s.solveSudoku()) {
//        cout << "Lösung Gefunden!!!!!!!!!!!" << endl;
//        s.printSudoku();
//    } else {
//        cout << "Leider keine Lösung gefunden :(" << endl;
//    }

    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                     {5, 2, 0, 0, 0, 0, 0, 0, 0},
                     {0, 8, 7, 0, 0, 0, 0, 3, 1},
                     {0, 0, 3, 0, 1, 0, 0, 8, 0},
                     {9, 0, 0, 8, 6, 3, 0, 0, 5},
                     {0, 5, 0, 0, 9, 0, 6, 0, 0},
                     {1, 3, 0, 0, 0, 0, 2, 5, 0},
                     {0, 0, 0, 0, 0, 0, 0, 7, 4},
                     {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    int grid2[9][9] = {0};


    SudokuSolver s;
    s.copyGrid(grid2);

    if (s.solveSudoku()) {
        s.printGrid();
    } else {
        cout << "No Solution found!" << endl;
    }

    return app.exec();
}
