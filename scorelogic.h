/* ScoreLogic handles the calculation of the current score, the multiplier
 * decreases from time to time, that means, that the users has to finish the
 * Sudoku fast, when he wants to get into the leaderboard.
 *
 * @author Jerome Wirth
 * Matrikel-Nr.: 532939
 */
#ifndef SCORELOGIC_H
#define SCORELOGIC_H

#include <iostream>
#include <QDebug>

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
    int mScore;
    int mMultiplier;
};

#endif // SCORE_H
