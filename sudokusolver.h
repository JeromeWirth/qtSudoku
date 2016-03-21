/**
  * Löst ein Sudoku mittels Backtracking-Algorithmus
  *
  * @author Jerome Wirth (532939)
  */
#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include <cstring>
#include <random>

using namespace std;

class SudokuSolver
{
public:
    SudokuSolver(int grid[9][9]);
    bool solveSudoku(int grid[9][9]);
    void printGrid();
    int getNumber(int row, int col);

private:
    int mBoard[9][9];

    bool findUnassignedLocation(int &row, int &col);
    bool isSafe(int row, int col, int num);
    bool usedInRow(int row, int num);
    bool usedInCol(int col, int num);
    bool usedInBox(int boxStartRow, int boxStartCol, int num);

};

#endif // SUDOKUSOLVER_H
