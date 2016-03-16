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
    int m_unsolvedBoard[9][9];
    int m_solvedBoard[9][9];

    void solveSudoku();
};

#endif // SUDOKULOADER_H
