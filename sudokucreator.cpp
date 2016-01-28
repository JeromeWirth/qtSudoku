#include "sudokucreator.h"

enum m_status{noSet, weSet, correct};

SudokuCreator::SudokuCreator() {
    initEmptySudoku();
    initUsedNumbersToFalse();
}

/*
 * Erstellt ein leeres Sudoku
 */
void SudokuCreator::initEmptySudoku() {
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            m_board[row][col] = 0;
            m_status[row][col] = noSet;
        }
    }
}

void SudokuCreator::initUsedNumbersToFalse() {
    for(int i = 0; i < 9; i++) {
        m_usedNumber[i] = false;
    }
    cout << "UsedNumbers werden zurückgesetzt" << endl;
}

void SudokuCreator::initPreSetSudoku() {
    m_board[0][6] = 9;
    m_board[1][4] = 3;
    m_board[1][5] = 4;
    m_board[1][7] = 2;
    m_board[1][8] = 8;
    m_board[2][0] = 1;
    m_board[2][3] = 7;
    m_board[2][6] = 6;
    m_board[3][2] = 4;
    m_board[3][5] = 8;
    m_board[3][7] = 7;
    m_board[4][0] = 2;
    m_board[5][0] = 7;
    m_board[5][3] = 1;
    m_board[5][5] = 5;
    m_board[6][0] = 9;
    m_board[6][1] = 6;
    m_board[6][3] = 5;
    m_board[6][5] = 1;
    m_board[7][5] = 6;
    m_board[8][4] = 9;
    m_board[8][6] = 4;
    m_board[8][8] = 3;
}

void SudokuCreator::test() {
    setStatus();

    printSudoku();

    checkRow(0);
    checkCol(0);
    checkBox(0, 0);

    printUsedNumbers(0, 0);

        // Durchlaufe das Array und prüfe Status
        // Prüfe mögliches Value für die aktuelle Position
        // trage die kleinste mögliche Zahl in die Position ein
        // änder den status des feldes auf 1
        // guck die nächste zeile an und beginne von vorne

        int row;
        int col;

        for (row = 0; row < 9; row++) {
            for (col = 0; col < 9; col++) {
                initUsedNumbersToFalse();

                checkRow(row);
                checkCol(col);
                checkBox(row, col);

                printUsedNumbers(row, col);
            }
        }

//    for (int i = 0; i < 9; i++) {
//        if (!m_usedNumber[i]) {
//            m_board[0][0] = i+1;
//            cout << "Row: 0, Col: 0, Number: " << i << endl;
//        }
//    }
   printSudoku();
}

/*
 * Löst das Sudoku
 */
bool SudokuCreator::solveSudoku() {
    setStatus();

    return solveSudoku(0, 0);
}

bool SudokuCreator::solveSudoku(int row, int col) {

    cout << "START SOLVESUDOKU: ROW: " << row << ", COL: " << col << endl;

    if(row == 9) {
        if (countValues() == 81) {
            return true; // eine lösung wurde gefunden!
        } else {
            return false;
        }
    }

    // wenn wir nicht in der letzten Zeile sind geht es weiter
    if(m_status[row][col]>=1) {
        //aktuelle Position wurde schon gesetzt
        //wir gucken uns die nächste position an
        int nextRow = row;
        int nextCol = col+1;

        if(nextCol == 9) {
            //Wenn wir in der letzten Spalte angekommen sind, gehe in die nöchste Zeile
            nextRow = row+1;
            nextCol = 0;
        }
        return solveSudoku(nextRow, nextCol);
    } else {
        cout << "IN DER ELSE SCHLEIFE; ROW: " << row << ", COL: " << col << endl;
        // Setzte usedNumbers wieder auf false
        initUsedNumbersToFalse();

        // Wenn noch kein Status gesetzt wurde, prüfe Zeile, Spalte und Box
        checkRow(col);
        checkCol(row);
        checkBox(col, row);

        printUsedNumbers(row, col);

        //iterate through the array!!
        for(int i = 0; i < 9; i++) {
            if(!m_usedNumber[i]) {
                cout << "Iterating through the Array" << endl;
                //Es können nur leere Stellen besetzt werden
                m_status[row][col] = weSet; // ändere den Status von nonSet auf weSet
                m_board[row][col] = i+1; // i+1 ist der Wert an dieser Stelle

                cout << "NUMMER: " << i+1 << "IN FELD: " << row << ", " << col << " gesetzt!" << endl;

                printSudoku();

                int nextRow = row;
                int nextCol = col+1;

                if(nextCol == 9) {
                    nextRow = row+1;
                    nextCol = 0;
                }

                if(solveSudoku(nextRow, nextCol)) {
                    cout << "solveSoduku gibt true zurück" << endl;
                    return true;
                }

                //wenn das einsetzen fehlgeschlagen ist
                for (int m = 0; m < 9; m++) {
                    for (int n = 0; n < 9; n++) {
                        if(m>row || (m==row && n >= col)) {
                            if(m_status[m][n] == 1) {
                                cout << "Row: " << m << ", Col: " << n << " set to 0" << endl;
                                m_status[m][n] = 0;
                                m_board[m][n] = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

void SudokuCreator::checkCol(int row) {
    //prüfe Spalte
//    cout << "==================" << endl;
//    cout << "CHECKCOL" << endl;
    for(int i = 0; i < 9; i++) {
        if(m_status[row][i]>=1) {
//            cout << "Row: " << row << ", Col: " << i << "Number: " << m_board[row][i] << " set to true" << endl;
            m_usedNumber[m_board[row][i]-1] = true; //Stelle hat bereits eine Zahl, also setzte den Wert auf true
        }
    }
//    cout << "==================" << endl;
    cout << "CHECKCOL USEDNUMBERS: ";
    printUsedNumbers(row, 9);
}

void SudokuCreator::checkRow(int col) {
    //prüfe Zeile
//    cout << "==================" << endl;
//    cout << "CHECKROW" << endl;
    cout << "CHECKROW, COL: " << col << endl;
    for(int i = 0; i < 9; i++) {
        if(m_status[i][col]>=1) {
            cout << "Row: " << i << ", Col: " << col << "Number: " << m_board[i][col] << " set to true" << endl;
            m_usedNumber[m_board[i][col]-1] = true; //Stelle hat bereits eine Zahl, also setzte den Wert auf true
        }
    }
//    cout << "==================" << endl;
    cout << "CHECKROW USEDNUMBERS: ";
    printUsedNumbers(9, col);
}

void SudokuCreator::checkBox(int row, int col) {
    int startRow = row - (row%3);
    int startCol = col - (col%3);
//    cout << "==================" << endl;
//    cout << "CHECKBOX" << endl;
    for (int tempRow = startRow; tempRow < (startRow + 3); tempRow++) {
        for (int tempCol = startCol; tempCol < (startCol + 3); tempCol++) {
            if (m_status[tempRow][tempCol] >= 1) {
//                cout << "Row: " << tempRow << ", Col: " << tempCol << "Number: " << m_board[tempRow][tempCol] << " set to true" << endl;

                m_usedNumber[m_board[tempRow][tempCol]-1] = true; //Stelle hat bereits eine Zahl, also setzte den Wert auf true
            }
        }
    }
//    cout << "==================" << endl;
    cout << "CHECKBOX USEDNUMBERS";
    printUsedNumbers(row, col);
}

void SudokuCreator::setStatus() {
    // Durchlaufe das Array, bei 0 setzte eine mögliche Nummer
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            if (m_board[row][col] > 0) {
                m_status[row][col] = correct;
            }
        }
    }
}

int SudokuCreator::countValues() {
    int count = 0;

    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            if (m_board[row][col] > 0) {
                count++;
            }
        }
    }
    return count;
}

/*
 * Gibt das aktuelle Sudoku über die Konsole aus
 */
void SudokuCreator::printSudoku() {
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

void SudokuCreator::printUsedNumbers(int row, int col) {
    cout << "Used Numbsers (" << row << "," << col << "): ";
    for (int i = 0; i < 9; i++) {
        cout << m_usedNumber[i];
    }
    cout << endl;
}
