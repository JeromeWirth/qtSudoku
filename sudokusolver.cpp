#include "sudokusolver.h"

SudokuSolver::SudokuSolver(int grid[9][9])
{
    solveSudoku(grid[9][9]);
}

void SudokuSolver::copyGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            m_solvedBoard[row][col] = grid[row][col];
        }
    }
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
            m_solvedBoard[row][col] = num;

            if (solveSudoku(grid[9][9])) {
                return true;
            }

            // Fehler, lösche zahl und versuche es mit neuer
            m_solvedBoard[row][col] = 0;
        }
    }
    return false; // this triggers backtracking
}

bool SudokuSolver::findUnassignedLocation(int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if(m_solvedBoard[row][col] == UNASSIGNED) {
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
    for(int col = 0; col < N; col++) {
        if(m_solvedBoard[row][col] == num)
            return true;
    }
    return false;
}

bool SudokuSolver::usedInCol(int col, int num) {
    for(int row = 0; row < N; row++) {
        if(m_solvedBoard[row][col] == num)
            return true;
    }
    return false;
}

bool SudokuSolver::usedInBox(int boxStartRow, int boxStartCol, int num) {
    for(int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if(m_solvedBoard[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }

    return false;
}


int SudokuSolver::countNumbers() {
    int count = 0;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if(m_unsolvedBoard[row][col] != 0) {
                count++;
            }
        }
    }

    return count;
}

void SudokuSolver::emptyUnsolvedBoard() {
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            m_unsolvedBoard[row][col] = 0;
        }
    }
}

void SudokuSolver::printGrid(int i) {
    cout << "---------------------------------" << endl;
    for (int row = 0; row < 9; row++) {
        if (row%3 == 0 && row != 0) {
            cout << endl;
        }
        for(int col = 0; col < 9; col++) {
            if (col%3 == 0 && col != 0) {
                cout << " ";
            }
            if (i == 1) {
                cout << m_solvedBoard[row][col];
            } else {
               cout << m_unsolvedBoard[row][col];
            }
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}
