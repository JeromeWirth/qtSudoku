#include "sudokusolver.h"

SudokuSolver::SudokuSolver(int grid[][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            mBoard[row][col] = grid[row][col];
        }
    }

    solveSudoku(mBoard);
}

bool SudokuSolver::solveSudoku(int grid[9][9]) {
    int row, col;

    // Wenn alle Felder besetzt sind, sind wir fertig
    if(!findUnassignedLocation(row, col))
        return true; //ERFOLG!

    // Versuche Zahlen von 1 bis 9
    for (int num = 1; num <= 9; num++) {
        // Wenn es gut aussieht
        if (isSafe(row, col, num)) {
            mBoard[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            // Fehler, lösche zahl und versuche es mit neuer
            mBoard[row][col] = 0;
        }
    }
    return false; // this triggers backtracking
}

bool SudokuSolver::findUnassignedLocation(int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if(mBoard[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool SudokuSolver::isSafe(int row, int col, int num) {
    return !usedInRow(row, num) &&
           !usedInCol(col, num) &&
           !usedInBox(row - row%3, col - col%3, num);
}

bool SudokuSolver::usedInRow(int row, int num) {
    for(int col = 0; col < 9; col++) {
        if(mBoard[row][col] == num)
            return true;
    }
    return false;
}

bool SudokuSolver::usedInCol(int col, int num) {
    for(int row = 0; row < 9; row++) {
        if(mBoard[row][col] == num)
            return true;
    }
    return false;
}

bool SudokuSolver::usedInBox(int boxStartRow, int boxStartCol, int num) {
    for(int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if(mBoard[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }

    return false;
}

void SudokuSolver::printGrid() {
    cout << "---------------------------------" << endl;
    for (int row = 0; row < 9; row++) {
        if (row%3 == 0 && row != 0) {
            cout << endl;
        }
        for(int col = 0; col < 9; col++) {
            if (col%3 == 0 && col != 0) {
                cout << " ";
            }
                cout << mBoard[row][col];

        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

int SudokuSolver::getNumber(int row, int col)
{
    return mBoard[row][col];
}
