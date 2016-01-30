#ifndef SCORELOGIC_H
#define SCORELOGIC_H

#include <iostream>

using namespace std;

class ScoreLogic
{
public:
    ScoreLogic();

    int getScore();
    int getMultiplier();
    void decreaseMultiplier();
    void setScore(int x);

private:
    int m_score;
    int m_multiplier;
};

#endif // SCORE_H
