/**
  * SudokuLoader läd eine neues Sudoku Feld aus einer Datei, dabei
  * speichert die Klasse einmal ein gelöstes und ungelöstes Array.
  *
  * Das ungelöste Array wird Dargestellt, wenn der benutzer eine Zahl eingibt
  * wird diese gegen das gelöste Array geprüft und so ermittelt ob die Zahl korrekt ist.
  *
  * @author Jerome Wirth (532939)
  */
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
