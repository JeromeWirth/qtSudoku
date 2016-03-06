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
#include "sudokuloader.h"
#include <QFile>
#include <QDebug>

int main(int argc, char **argv) {
    QApplication app (argc, argv);


    //    BoardWidget *sudoku = new BoardWidget();
    //    sudoku->show();

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


    //    SudokuWidget *test = new SudokuWidget();
    //    test->show();

    MainWindow window;
    window.show();

//    SudokuLoader *load = new SudokuLoader("level/001.txt");
//    load->printLevel();

//    SudokuLoader load("level/001.txt");
//            load.printLevel();

//    int board[9][9];
//    int row = 0;

//    QFile file("sudoku1.txt");
//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//        cout << "Could not read file" << endl;

//    QTextStream in(&file);
//    while (!in.atEnd()) {
//        QString line = in.readLine();


//        for (int col = 0; col < 9; col++) {
//            board[row][col] = line.at(col).digitValue();
//        }

//        row++;
//        qDebug() << line;
//    }

//    for (int row = 0; row < 9; row++) {
//        for (int col = 0; col < 9; col++) {
//            qDebug() << "Row: " << row << ", Col: " << col << " Num: " << board[row][col];
//        }
//    }


    return app.exec();
}
