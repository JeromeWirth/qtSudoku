/**
 * qtSudoku, is a simple Sudoku Game, written in C++ and the Qt-Framework.
 * After the Programm is started, the User can solve his first Sudoku Baord,
 * or start a new game, where he can choose the difficulty.
 *
 * There are 3 difficultys, easy, normal and hard.
 *
 * The rules of Suduoku are fairly easy, one must insert numbers, so that
 * in each, row, column and box the number is presented once.
 *
 * When the users finishes the board, the user can add his name and score
 * to the database, when he got enough points, he will be displayed in the
 * top 5 players ranking.
 *
 * @author Jerome Wirth
 * Matrikel-Nr.: 582939
 */

#include "mainwindow.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
