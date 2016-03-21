#include "sudokusolver.h"

/**
 * @brief SudokuSolver::SudokuSolver
 * Ein 2D-Array wird der Klasse übergeben, und mittels Backtracking gelöst.
 *
 * @param grid Das zu lösende Sudoku
 */
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
        return true;

    // Versuche Zahlen von 1 bis 9
    for (int num = 1; num <= 9; num++) {
        // Wenn die Zahl an der Stelle erlaubt ist, setzte sie ein
        if (isSafe(row, col, num)) {
            mBoard[row][col] = num;

            // Rekursiver Aufruf der funktion für das nächste Feld
            if (solveSudoku(grid)) {
                return true;
            }

            // Fehler, lösche zahl und versuche es mit neuer
            mBoard[row][col] = 0;
        }
    }
    return false;
}

/**
 * @brief SudokuSolver::findUnassignedLocation
 * Prüft, ob es unbesetzte Stellen im Array gibt, also Felder ohne Zahlen
 *
 * @param row
 * @param col
 * @return
 */
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

/**
 * @brief SudokuSolver::isSafe
 * Gibt True zurück, wenn die Zahl an der Stelle erlaubt ist
 *
 * @param aktuelle Zeile
 * @param aktuelle Spalte
 * @param num aktuelle Zahl
 * @return
 */
bool SudokuSolver::isSafe(int row, int col, int num) {
    return !usedInRow(row, num) &&
           !usedInCol(col, num) &&
           !usedInBox(row - row%3, col - col%3, num);
}

/**
 * @brief SudokuSolver::usedInRow
 * Prüft, ob die Zahl in der aktuellen Zeile vorkommt
 *
 * @param row die zu prüfende Zeile
 * @param num Zahl, welche nur einmal vorkommen darf
 * @return
 */
bool SudokuSolver::usedInRow(int row, int num) {
    for(int col = 0; col < 9; col++) {
        if(mBoard[row][col] == num)
            return true;
    }
    return false;
}

/**
 * @brief SudokuSolver::usedInCol
 * Prüft, ob die Zahl in der aktuellen Spalte vorkommt
 *
 * @param col die zu prüfende Spalte
 * @param num Zahl, welche nur einmal vorkommen darf
 * @return
 */
bool SudokuSolver::usedInCol(int col, int num) {
    for(int row = 0; row < 9; row++) {
        if(mBoard[row][col] == num)
            return true;
    }
    return false;
}

/**
 * @brief SudokuSolver::usedInBox
 * Prüft, ob die Zahl nur einmal in dem Block vorkommt
 *
 * @param boxStartRow die erste Zeile des Blocks
 * @param boxStartCol die erste Spalte des Blocks
 * @param num die Zahl darf nur einmal vorkommen
 * @return
 */
bool SudokuSolver::usedInBox(int boxStartRow, int boxStartCol, int num) {
    for(int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if(mBoard[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }

    return false;
}

/**
 * @brief SudokuSolver::printGrid
 * Für Test-Zwecke ist es möglich, sich das Sudoku in der Konsole ausgeben zu lassen.
 */
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

/**
 * @brief SudokuSolver::getNumber
 * Gibt die Nummer an der Zeile/Spalte zurück
 *
 * @param row die Zeil, in der die Nummer steht
 * @param col die Spalte in der die Nummer steht
 * @return gibt die Nummer zurück
 */
int SudokuSolver::getNumber(int row, int col)
{
    return mBoard[row][col];
}
