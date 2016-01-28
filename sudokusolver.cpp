#include "sudokusolver.h"

SudokuSolver::SudokuSolver()
{

}

void SudokuSolver::copyGrid(int grid[N][N]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            m_board[row][col] = grid[row][col];
        }
    }
}

bool SudokuSolver::solveSudoku() {
    int row, col;

    // Wenn alle Felder besetzt sind, sind wir fertig
    if(!findUnassignedLocation(row, col))
        return true; //ERFOLG!

    // Versuche Zahlen von 1 bis 9
    for (int num = 1; num <= 9; num++) {
        // Wenn es gut aussieht
        if (isSafe(row, col, num)) {
            m_board[row][col] = num;

            if (solveSudoku())
                return true;

            // Fehler, lösche zahl und versuche es mit neuer
            m_board[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
}

bool SudokuSolver::findUnassignedLocation(int &row, int &col) {
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if(m_board[row][col] == UNASSIGNED) {
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
        if(m_board[row][col] == num)
            return true;
    }
    return false;
}

bool SudokuSolver::usedInCol(int col, int num) {
    for(int row = 0; row < N; row++) {
        if(m_board[row][col] == num)
            return true;
    }
    return false;
}

bool SudokuSolver::usedInBox(int boxStartRow, int boxStartCol, int num) {
    for(int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if(m_board[row+boxStartRow][col+boxStartCol] == num)
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
            cout << m_board[row][col];
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}
