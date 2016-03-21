#include "scorelogic.h"

/**
 * @brief ScoreLogic::ScoreLogic
 * Setzt die Standertwerde der Punkte fest
 */
ScoreLogic::ScoreLogic()
{
    mScore = 0;
    mMultiplier = 150;

    qDebug() << "Current score: " << mScore << endl;
}

/**
 * @brief ScoreLogic::getScore
 * Gibt die aktuelle Punktzahl zurück
 *
 * @return integer mit aktuellen Punktstand
 */
int ScoreLogic::getScore() {
    return mScore;
}

/**
 * @brief ScoreLogic::getMultiplier
 * Gibt den aktuellen Multiplier zurück
 *
 * @return integer mit aktuellen Multiplier
 */
int ScoreLogic::getMultiplier() {
    return mMultiplier;
}

/**
 * @brief ScoreLogic::increaseScore
 * Wenn der Spieler einen Stein richtig gesetzt hat, wird der aktuelle
 * Punktestand um X erhöht.
 * Damit keine übergroßen Zahlen entstehen, wird der variable Wert mit 10% des
 * Multipliers multipliziert und dem aktuellen Punktestand addiert,
 *
 * @param x intgeger, um wieviel die Punkte erhöht werden sollen.
 */
void ScoreLogic::increaseScore(int x) {
    mScore = (x * (mMultiplier/10)) + mScore;
}

/**
 * @brief ScoreLogic::decreaseScore
 * Wenn der Spieler eine falsche Zahl setzt, werden die Punkte um X verringert.
 * Der Spieler kann nicht weniger als 0 Punkte haben.
 *
 * @param x integer, um wieviel die Punkte verringert werden sollen
 */
void ScoreLogic::decreaseScore(int x) {
    mScore -= x;

    if(mScore < 0) {
        mScore = 0;
    }
}

/**
 * @brief ScoreLogic::decreaseMultiplier
 * Sowohl nach einer gewissen Zeit, als auch wenn der Spieler eine falsche Zahl
 * setzt, wird der Multiplier um X verringert
 *
 * @param x integer, um wieviel der multiplier verringert werden soll
 */
void ScoreLogic::decreaseMultiplier(int x) {
    mMultiplier -= x;
}

/**
 * @brief ScoreLogic::setScore
 * Setz den aktuellen Punktestand auf X
 *
 * @param x integer, mit dem Wert des aktuellen Punktestandes
 */
void ScoreLogic::setScore(int x) {
    mScore = x;
}

/**
 * @brief ScoreLogic::resetScoreLogic
 * Setzt die Werte der Klassen-Variablen wieder zurück
 */
void ScoreLogic::resetScoreLogic() {
    mScore = 0;
    mMultiplier = 150;
}
