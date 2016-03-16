#include <QtWidgets>
#include <QFile>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>

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

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    MainWindow window;
    window.show();

//    GameOverWindow text;
//    text.show();

//    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
//    db.setHostName("db.f4.htw-berlin.de");
//    db.setDatabaseName("_s0532939__qtsudokuleaderboard");
//    db.setUserName("s0532939");
//    db.setPassword("sn#582jW");

//    bool ok = db.open();


//    if (ok) {
//        QSqlQuery query(db);
//        query.exec("SELECT * FROM Scores");

//        while (query.next()) {
//            QString name = query.value(0).toString();
//            int score = query.value(1).toInt();
//            qDebug() << "Name: " << name << ", Punkte: " << score;
//        }
//    } else {
//        qDebug() << "ERROR DB";
//    }

    return app.exec();
}
