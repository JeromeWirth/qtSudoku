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
    void decreaseMultiplier(int x);
    void setScore(int x);
    void decreaseScore(int x);
    void increaseScore(int x);
    void resetScoreLogic();

private:
    int m_score;
    int m_multiplier;
};

#endif // SCORE_H
