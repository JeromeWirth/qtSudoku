#include <QtWidgets>
#include <QHBoxLayout>
#include "boardlogic.h"
#include "boardwidget.h"
#include "scorewidget.h"
#include "timerwidget.h"
#include "mainwindow.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    BoardWidget *sudoku = new BoardWidget();
    sudoku->show();

    MainWindow window;
    window.show();

    return app.exec();
}
