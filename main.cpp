#include <QtWidgets>
#include <QHBoxLayout>
#include "boardlogic.h"
#include "boardwidget.h"
#include "scorewidget.h"
#include "timerwidget.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    BoardWidget *sudoku = new BoardWidget();
    sudoku->show();

    return app.exec();
}
