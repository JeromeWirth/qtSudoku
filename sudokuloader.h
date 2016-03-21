#ifndef SUDOKULOADER_H
#define SUDOKULOADER_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QTextStream>

#include "sudokusolver.h"

class SudokuLoader
{
public:
    SudokuLoader(QString fileName);
    void printLevel();
    void loadLevel(QString fileName);
    int getNumber(int row, int col, bool solved);
    int getSudoku();

private:
    int mUnsovledBoard[9][9];
    int mSolvedBoard[9][9];

    void solveSudoku();
};

#endif // SUDOKULOADER_H
