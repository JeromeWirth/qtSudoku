#include "user.h"

User::User()
{
    mName = "";
    mScore = 0;
}

QString User::getName() {
    return mName;
}

void User::setName(QString name)
{
    mName = name;
}

void User::setScore(int score) {
    mScore = score;
}

int User::getScore() {
    return mScore;
}

