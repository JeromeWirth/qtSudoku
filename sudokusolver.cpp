#include "sudokusolver.h"

SudokuSolver::SudokuSolver()
{
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            m_solvedBoard[row][col] = 0;
            m_unsolvedBoard[row][col] = 0;
        }
    }
}

void SudokuSolver::copyGrid(int grid[N][N]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            m_solvedBoard[row][col] = grid[row][col];
        }
    }
}

void SudokuSolver::initPreSetSudoku() {
    m_solvedBoard[0][6] = 9;
    m_solvedBoard[1][4] = 3;
    m_solvedBoard[1][5] = 4;
    m_solvedBoard[1][7] = 2;
    m_solvedBoard[1][8] = 8;
    m_solvedBoard[2][0] = 1;
    m_solvedBoard[2][3] = 7;
    m_solvedBoard[2][6] = 6;
    m_solvedBoard[3][2] = 4;
    m_solvedBoard[3][5] = 8;
    m_solvedBoard[3][7] = 7;
    m_solvedBoard[4][0] = 2;
    m_solvedBoard[5][0] = 7;
    m_solvedBoard[5][3] = 1;
    m_solvedBoard[5][5] = 5;
    m_solvedBoard[6][0] = 9;
    m_solvedBoard[6][1] = 6;
    m_solvedBoard[6][3] = 5;
    m_solvedBoard[6][5] = 1;
    m_solvedBoard[7][5] = 6;
    m_solvedBoard[8][4] = 9;
    m_solvedBoard[8][6] = 4;
    m_solvedBoard[8][8] = 3;
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
            m_solvedBoard[row][col] = num;

            if (solveSudoku()) {
                return true;
            }

            // Fehler, lösche zahl und versuche es mit neuer
            m_solvedBoard[row][col] = UNASSIGNED;
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

void SudokuSolver::createUnsolvedBoard() {
    int count = 1;

    emptyUnsolvedBoard();

    while(count!=30) {
        random_device rd;
        mt19937 rng(rd());
        uniform_int_distribution<int> uni(0,8);

        auto row = uni(rng);
        auto col = uni(rng);

        m_unsolvedBoard[row][col] = m_solvedBoard[row][col];
        count++;
    }
}

bool SudokuSolver::checkEnteredNumber(int row, int col, int num) {
    if (m_solvedBoard[row][col] == num) {
        return true;
    } else {
        return false;
    }
}

void SudokuSolver::setNumber(int row, int col) {
    m_unsolvedBoard[row][col] = m_solvedBoard[row][col];
}

int SudokuSolver::getNumber(int row, int col, bool solved) {
    if (solved) {
        return m_solvedBoard[row][col];
    } else {
        return m_unsolvedBoard[row][col];
    }
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
