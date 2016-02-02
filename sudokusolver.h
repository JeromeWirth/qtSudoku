#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <iostream>
#include <cstring>
#include <random>

using namespace std;

#define UNASSIGNED 0
#define N 9

class SudokuSolver
{
public:
    SudokuSolver();
    bool solveSudoku();
    void copyGrid(int grid[N][N]);
    void initPreSetSudoku();
    void printGrid(int i);
    int getNumber(int row, int col, bool solved);
    void createUnsolvedBoard();
    bool checkEnteredNumber(int row, int col, int num);
    void setNumber(int row, int col);
    int countNumbers();

private:
    int m_solvedBoard[N][N];
    int m_unsolvedBoard[N][N];

    bool findUnassignedLocation(int &row, int &col);
    bool isSafe(int row, int col, int num);
    bool usedInRow(int row, int num);
    bool usedInCol(int col, int num);
    bool usedInBox(int boxStartRow, int boxStartCol, int num);
    void emptyUnsolvedBoard();

};

#endif // SUDOKUSOLVER_H
