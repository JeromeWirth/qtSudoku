#ifndef SUDOKUCREATOR_H
#define SUDOKUCREATOR_H

#include <iostream>
#include <vector>

using namespace std;

class SudokuCreator
{
public:
    SudokuCreator();
    void initPreSetSudoku();
    void loadSudoku();
    bool solveSudoku();
    void printSudoku();
    void test();
    void checkRow(int row);
    void checkCol(int col);
    void checkBox(int row, int col);

private:
    int m_board[9][9];
    int m_status[9][9];
    bool m_usedNumber[9];

    bool solveSudoku(int row, int col);
    void initEmptySudoku();
    void initUsedNumbersToFalse();
    void setStatus();
    int countValues();
    void printUsedNumbers(int row, int col);
};

#endif // SUDOKUCREATOR_H
