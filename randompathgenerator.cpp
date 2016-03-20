#include "randompathgenerator.h"

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

    m_file = "level/" + QString("%1").arg(tempDiff) + QString("-%1.txt").arg(rndNumber, 3, 10, QLatin1Char('0'));
}

QString RandomPathGenerator::getFilePath() {
    return m_file;
}

int RandomPathGenerator::createRandomNumber() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 3);
    auto random_integer = uni(rng);

    return random_integer;
}
