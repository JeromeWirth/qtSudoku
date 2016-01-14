#ifndef BOARDLOGIC_H
#define BOARDLOGIC_H

#include <stdio.h>
#include <iostream>
#include <random>
#include <QString>

using namespace std;

class BoardLogic
{
public:
    BoardLogic();
    void generateSudoku();
    bool insertNumber(int row, int col, int number);
    bool insertNumber(int row, int col, QString number);
    bool isNumberValid(int row, int col, int number);
    void printBoard();
    void setNumber(int row, int col, int number);
    int getNumber(int row, int col);
    void generateEmptySudoku();

private:
    bool checkRow(int col, int number);
    bool checkCol(int row, int number);
    bool checkBlock(int row, int col, int number);

    int m_board[9][9];
};

#endif // BOARDLOGIC_H
