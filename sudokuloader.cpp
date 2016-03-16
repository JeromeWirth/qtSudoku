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
            m_unsolvedBoard[row][col] = line.at(col).digitValue();
        }

        row++;
    }

    solveSudoku();
}

void SudokuLoader::printLevel()
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            qDebug() << "Row: " << row << ", Col: " << col << " Num: " << m_unsolvedBoard[row][col];
        }
    }
}

void SudokuLoader::loadLevel(QString fileName)
{
    int row = 0;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << "Could not read file" << endl;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();


        for (int col = 0; col < 9; col++) {
            m_unsolvedBoard[row][col] = line.at(col).digitValue();
        }

        row++;
    }

    solveSudoku();
}

int SudokuLoader::getNumber(int row, int col, bool solved)
{
    if (solved) {
        return m_solvedBoard[row][col];
    } else {
        return m_unsolvedBoard[row][col];
    }
}

void SudokuLoader::solveSudoku()
{
    SudokuSolver solver(m_unsolvedBoard);

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            m_solvedBoard[row][col] = solver.getNumber(row, col);
        }
    }
}
