#include <QtWidgets>
#include <QFile>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

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
#include "gameoverwindow.h"
#include "randompathgenerator.h"
#include "leaderboard.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    MainWindow window;
    window.show();

//    GameOverWindow text;
//    text.show();


//    LeaderBoard board;
//    board.insertRaninking("jak", 40);
//    board.printRankings();

    return app.exec();
}
