/**
  * RandomPathGenerator ereugt einen zufälligen Dateipfad zu einer
  * vorhanden Datei, um ein neues Sudoku zu laden.
  *
  * @author Jerome Wirth (532939)
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
    QString mFile;

    int createRandomNumber();

};

#endif // RANDOMPATHGENERATOR_H
