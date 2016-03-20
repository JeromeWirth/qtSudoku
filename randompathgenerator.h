/*
 * RandomPathGenerator class generates a random path with the given difficulty.
 * The Path is also formatted by the class, so the SudokuWidget can load a new Sudoku.
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 532939
 */
#ifndef RANDOMPATHGENERATOR_H
#define RANDOMPATHGENERATOR_H

#include <QString>
#include <random>

using namespace std;

class RandomPathGenerator
{
public:
    RandomPathGenerator(int diff);
    QString getFilePath();

private:
    QString m_file;

    int createRandomNumber();

};

#endif // RANDOMPATHGENERATOR_H
