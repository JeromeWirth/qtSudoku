/**
  * User-Klasse verwaltet die Spieler, welche am ende eines Sudoku spiels in die
  * Datenbank eingetragen werden.
  *
  * @author Jerome Wirth (532939)
  */
#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User();
    QString getName();
    int getScore();

    void setName(QString name);
    void setScore(int score);

private:
    QString mName;
    int mScore;
};

#endif // USER_H
