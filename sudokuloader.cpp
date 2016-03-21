#include "sudokuloader.h"

/**
 * @brief SudokuLoader::SudokuLoader
 * Die Klasse liest eine Datei zeilenweise aus und überträgt den Inhalt in ein array.
 * Zudem wird das Sudoku gelöst und in ein weiteres Array geschrieben.
 *
 * @param fileName der zu öffnende Dateiname
 */
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
            mUnsovledBoard[row][col] = line.at(col).digitValue();
        }

        row++;
    }

    solveSudoku();
}

/**
 * @brief SudokuLoader::printLevel
 * Für Testzwecke kann das Sudoku auch Feld für Feld in der Konsole ausgegeben werden
 */
void SudokuLoader::printLevel()
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            qDebug() << "Row: " << row << ", Col: " << col << " Num: " << mUnsovledBoard[row][col];
        }
    }
}

/**
 * @brief SudokuLoader::loadLevel
 * siehe Konstruktor
 *
 * @param fileName
 */
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
            mUnsovledBoard[row][col] = line.at(col).digitValue();
        }

        row++;
    }

    solveSudoku();
}

/**
 * @brief SudokuLoader::getNumber
 * Gibt die Zahl an der ausgewählten Stelle zurück
 *
 * @param row integer mit der Reihen-Zahl
 * @param col integer mit der Spalten-Zahl
 * @param solved bool, ob die gelöste oder ungelöste Zahl zurückgegeben werden soll
 * @return gibt die Zahl zurück
 */
int SudokuLoader::getNumber(int row, int col, bool solved)
{
    if (solved) {
        return mSolvedBoard[row][col];
    } else {
        return mUnsovledBoard[row][col];
    }
}

/**
 * @brief SudokuLoader::solveSudoku
 * Löst das geladene Sudoku und speichert es in ein weiteres Array.
 */
void SudokuLoader::solveSudoku()
{
    SudokuSolver solver(mUnsovledBoard);

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            mSolvedBoard[row][col] = solver.getNumber(row, col);
        }
    }
}
