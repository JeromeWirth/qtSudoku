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
