/*
 * User Class gets a name and score and will be displayed on the rankings.
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 532939
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
    QString m_name;
    int m_score;
};

#endif // USER_H
