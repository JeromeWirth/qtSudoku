#include "user.h"

User::User()
{
    m_name = "";
    m_score = 0;
}

QString User::getName() {
    return m_name;
}

void User::setName(QString name)
{
    m_name = name;
}

void User::setScore(int score) {
    m_score = score;
}

int User::getScore() {
    return m_score;
}

