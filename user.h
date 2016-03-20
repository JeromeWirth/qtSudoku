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
