#ifndef SUDOKULOADER_H
#define SUDOKULOADER_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QTextStream>

class SudokuLoader
{
public:
    SudokuLoader(QString fileName);
    void printLevel();
    int getNumber(int row, int col);

private:
    int m_board[9][9];
};

#endif // SUDOKULOADER_H
