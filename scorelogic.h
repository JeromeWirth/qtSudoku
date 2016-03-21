/**
  * ScoreLogic übernimmt die berechnung der aktuellen Punktzahl,
  * der mMultiplier nimmt von Zeit ab, oder wenn der Spieler eine falsche
  * eingabe getätigt hat.
  *
  * @author Jerome Wirth (532939)
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
