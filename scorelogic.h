#ifndef SCORELOGIC_H
#define SCORELOGIC_H

class ScoreLogic
{
public:
    ScoreLogic();

    int getScore();
    int getMultiplier();
    void decreaseMultiplier();

private:
    int m_score;
    int m_multiplier;
};

#endif // SCORE_H
