#include "boardlogic.h"

BoardLogic::BoardLogic() {
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            m_board[row][col] = 0;
        }
    }
}

void BoardLogic::generateEmptySudoku() {
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            m_board[row][col] = 0;
        }
    }
}

void BoardLogic::generateSudoku() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1,9);

    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            auto number = uni(rng);
            insertNumber(row, col, number);
        }
    }
}

bool BoardLogic::insertNumber(int row, int col, int number) {
    if (isNumberValid(row, col, number)) {
        m_board[col][row] = number;
        return true;
    } else {
        cout << "Zahl: " << number << "; X: " << row << "; Y: " << col << " wurde an die Falsche stelle gesetzt." << endl;
        return false;
    }
}

bool BoardLogic::isNumberValid(int row, int col, int number) {
    if (checkCol(row, number) && checkRow(col, number) && checkBlock(row, col, number)) {
        return true;
    }
    return false;
}

bool BoardLogic::checkCol(int row, int number) {
    for (int col = 0; col < 9; col++) {
      if (m_board[row][col] == number) {
        return false;
      }
    }
    return true;
}

bool BoardLogic::checkRow(int col, int number) {
    for (int row = 0; row < 9; row++) {
      if (m_board[row][col] == number) {
        return false;
      }
    }
    return true;

}

bool BoardLogic::checkBlock(int row, int col, int number) {
    int startRow = row - (row%3);
    int startCol = col - (col%3);

    for (int tempCol = startCol; tempCol < (startCol + 3); tempCol++) {
      for (int tempRow = startRow; tempRow < (startRow + 3); tempRow++) {
        if (m_board[tempCol][tempRow] == number) {
          return false;
        }
      }
    }
    return true;
}

void BoardLogic::printBoard() {
    cout << "  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |" << endl;
    for (int row = 0; row < 9; row++) {
        cout << "----------------------------------------" << endl;
        cout << row+1 << " ";
        for(int col = 0; col < 9; col++) {
            cout << "| " << m_board[row][col] << " ";
        }
        cout << "|" << endl;
    }
    cout << "----------------------------------------" << endl;
}

int BoardLogic::getNumber(int row, int col) {
    cout << "[BoardLogic] Row: " << row << " Col: " << col << " Number: " << m_board[row][col] << endl;
    return m_board[row][col];
}
