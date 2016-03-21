#include "randompathgenerator.h"

/**
 * @brief RandomPathGenerator::RandomPathGenerator
 * Konstruktor schreibt gleich den passenden prefix für den Datei-Pfad in
 * seine Member-Variable
 *
 * @param diff die ID für den gewählten Schwierigkeitsgrad
 */
RandomPathGenerator::RandomPathGenerator(int diff) {
    QString tempDiff;

    switch(diff) {
    case -2:
        tempDiff = "E";
        break;
    case -3:
        tempDiff = "M";
        break;
    case -4:
        tempDiff = "H";
        break;
    default:
        break;
    }

    int rndNumber = createRandomNumber();

    mFile = ":files/level/" + QString("%1").arg(tempDiff) + QString("-%1.txt").arg(rndNumber, 3, 10, QLatin1Char('0'));
}

/**
 * @brief RandomPathGenerator::getFilePath
 * Gibt den erstellten Pfad zurück
 *
 * @return gibt QString, welcher den erstellten Pfad enthält
 */
QString RandomPathGenerator::getFilePath() {
    return mFile;
}

/**
 * @brief RandomPathGenerator::createRandomNumber
 * Gibt eine zufällige zahl zurück, da es bisher nur 3 Level pro Schwierigkeitsgrad vorhanden sind
 * beschränkt sich die Zahl zwischen 1 und 3.
 *
 * @return integer der zufälligen zahl zwischen 1 und 3
 */
int RandomPathGenerator::createRandomNumber() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 3);
    auto random_integer = uni(rng);

    return random_integer;
}
