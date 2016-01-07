#include <QtWidgets>
#include <QHBoxLayout>
#include "boardlogic.h"
#include "boardwidget.h"
#include "timer.h"
#include "scorewidget.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    BoardWidget *sudoku = new BoardWidget();
    sudoku->show();

    ScoreWidget *test = new ScoreWidget();
    test->show();

    return app.exec();
}
