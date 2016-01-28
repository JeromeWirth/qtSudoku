#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include <cstring>

using namespace std;

#define UNASSIGNED 0
#define N 9

class SudokuSolver
{
public:
    SudokuSolver();
    bool solveSudoku();
    void copyGrid(int grid[N][N]);
    void printGrid();

private:
    int m_board[N][N];

    bool findUnassignedLocation(int &row, int &col);
    bool isSafe(int row, int col, int num);
    bool usedInRow(int row, int num);
    bool usedInCol(int col, int num);
    bool usedInBox(int boxStartRow, int boxStartCol, int num);

};

#endif // SUDOKUSOLVER_H
