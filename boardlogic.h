#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include <stdio.h>
#include <iostream>
#include <random>

using namespace std;

class BoardLogic
{
public:
    BoardLogic();
    void generateSudoku();
    bool insertNumber(int row, int col, int number);
    bool isNumberValid(int row, int col, int number);
    void printBoard();
    int getNumber(int row, int col);
    void generateEmptySudoku();

private:
    bool checkRow(int col, int number);
    bool checkCol(int row, int number);
    bool checkBlock(int row, int col, int number);

    int m_board[9][9];
};

#endif // BOARDLOGIC_H
