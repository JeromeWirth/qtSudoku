#include "user.h"

/**
 * @brief User::User
 * Erstellt ein neues User-Objekt mit Standart-Werten
 */
User::User()
{
    mName = "anon";
    mScore = 0;
}

/**
 * @brief User::getName
 * Gibt den Namen der User-Instanz zurück
 *
 * @return QString, Name des aktuellen benutzers
 */
QString User::getName() {
    return mName;
}

/**
 * @brief User::setName
 * Übergibt den Namen, der aktuellen User-Instanz
 *
 * @param name QString, Name des Benutzers
 */
void User::setName(QString name)
{
    mName = name;
}

/**
 * @brief User::setScore
 * Übergibt den aktuellen Spielstand an die User-Instanz
 *
 * @param score integer, setzt aktuellen Spielstand fest
 */
void User::setScore(int score) {
    mScore = score;
}

/**
 * @brief User::getScore
 * Gibt die aktuelle Punktzahl zurück
 *
 * @return Punktzahl wird als integer zurückgegeben
 */
int User::getScore() {
    return mScore;
}

