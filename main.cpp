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

//    QGraphicsView test;
//    QGraphicsScene *scene = new QGraphicsScene();
//    QPixmap p(":/files/images/sudokuboard.jpg");

//    // Abstand der Buttons ist 44 Pixel
//    QGraphicsPixmapItem *oneButton = new QGraphicsPixmapItem(QPixmap(":/files/images/1button.png"));
//    oneButton->setScale(0.5);
//    oneButton->setX(3);
//    oneButton->setY(3);

//    QGraphicsPixmapItem *twoButton = new QGraphicsPixmapItem(QPixmap(":/files/images/2button.png"));
//    twoButton->setScale(0.5);
//    twoButton->setX(47);
//    twoButton->setY(3);

//    QGraphicsPixmapItem *threeButton = new QGraphicsPixmapItem(QPixmap(":/files/images/3button.png"));
//    threeButton->setScale(0.5);
//    threeButton->setX(91);
//    threeButton->setY(137);
//    threeButton->setFlags(QGraphicsItem::ItemIsMovable);

//    QGraphicsTextItem *textTest = new QGraphicsTextItem("5");
//    textTest->setX(3);
//    textTest->setY(47);
//    textTest->setScale(4);
//    textTest->setTextInteractionFlags(Qt::TextEditable);

//    scene->setSceneRect(0, 0, 400, 400);
//    scene->setBackgroundBrush(p.scaled(400, 400, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));

//    scene->addItem(oneButton);
//    scene->addItem(twoButton);
//    scene->addItem(threeButton);
//    scene->addItem(textTest);

//    test.setScene(scene);
//    test.show();


    QGraphicsView *view = new QGraphicsView;
    QGraphicsScene *scene = new QGraphicsScene();

    SudokuWidget *sudoku = new SudokuWidget();
    SudokuItem *item1 = new SudokuItem();
    SudokuItem *item2 = new SudokuItem();
    SudokuItem *item3 = new SudokuItem();

    item2->setX(55);
    item3->setX(110);

    scene->addItem(item1);
//    scene->addItem(item2);
//    scene->addItem(item3);

//    scene->addItem(sudoku);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->show();

    return app.exec();
}
