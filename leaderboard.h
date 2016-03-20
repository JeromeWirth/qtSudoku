/*
 * The LeaderBoard Class handles the connections and querys
 * to the PostgreSQL database.
 *
 * The LeaderBoard gets names and scores from the GameOverWindow Class
 * and inserts the data into the database.
 *
 * It also selectes the best 5 sudoku players and sends it to the GameOverWindow.
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 582939
 */

#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

#include "user.h"

class LeaderBoard
{
public:
    LeaderBoard();
    void printRankings(User users[5]);
    void insertRaninking(QString name, int score);
    void closeConn();

private:
    QSqlDatabase db;
    bool ok;
};

#endif // LEADERBOARD_H
