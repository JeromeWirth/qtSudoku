#include "scorelogic.h"
#include <iostream>

ScoreLogic::ScoreLogic()
{
    m_score = 0;
    m_multiplier = 150;

    cout << "Current score: " << m_score << endl;
}

int ScoreLogic::getScore() {
    return m_score;
}

int ScoreLogic::getMultiplier() {
    return m_multiplier;
}

void ScoreLogic::decreaseMultiplier() {
    m_multiplier -= 1;
}

