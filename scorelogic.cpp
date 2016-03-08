#include "scorelogic.h"

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

void ScoreLogic::increaseScore(int x) {
    m_score = (x * (m_multiplier/10)) + m_score;
}

void ScoreLogic::decreaseScore(int x) {
    m_score -= x;

    if(m_score < 0) {
        m_score = 0;
    }
}

void ScoreLogic::decreaseMultiplier(int x) {
    m_multiplier -= x;
}

void ScoreLogic::setScore(int x) {
    m_score = x;
}

void ScoreLogic::resetScoreLogic() {
    m_score = 0;
    m_multiplier = 150;
}
