#include "sudokuloader.h"

SudokuLoader::SudokuLoader(QString fileName)
{
    int row = 0;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Could not read file" << endl;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();


        for (int col = 0; col < 9; col++) {
            m_board[row][col] = line.at(col).digitValue();
        }

        row++;
    }
}

void SudokuLoader::printLevel()
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            qDebug() << "Row: " << row << ", Col: " << col << " Num: " << m_board[row][col];
        }
    }
}

int SudokuLoader::getNumber(int row, int col)
{
    return m_board[row][col];
}
