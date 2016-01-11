#include <QtWidgets>
#include <QHBoxLayout>
#include "boardlogic.h"
#include "boardwidget.h"
#include "scorewidget.h"
#include "timerwidget.h"
#include "mainwindow.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

//    BoardWidget *sudoku = new BoardWidget();
//    sudoku->show();

    MainWindow window;
    window.show();

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

    return app.exec();
}
