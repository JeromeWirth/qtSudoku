#include "leaderboard.h"

LeaderBoard::LeaderBoard()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("db.f4.htw-berlin.de");
    db.setDatabaseName("_s0532939__qtsudokuleaderboard");
    db.setUserName("s0532939");
    db.setPassword("sn#582jW");

    ok = db.open();
}

void LeaderBoard::printRankings(User users[5]) {
    if (ok) {
        QSqlQuery query(db);

        query.exec("SELECT * FROM scores ORDER BY score DESC LIMIT 5");

        int i = 0;
        while (query.next()) {
            QString name = query.value(0).toString();
            int score = query.value(1).toInt();

            users[i].setName(name);
            users[i].setScore(score);

            qDebug() << "Name: " << name << ", Punkte: " << score;
            i++;
        }
    } else {
        qDebug() << "ERROR DB";
    }
}

void LeaderBoard::insertRaninking(QString name, int score)
{
    if (ok) {
        QSqlQuery query(db);

        query.prepare("INSERT INTO scores (name, score) "
                      "VALUES (:name, :score)");
        query.bindValue(":name", name);
        query.bindValue(":score", score);
        query.exec();
    }
}

void LeaderBoard::closeConn()
{
    QString connection;
    connection = db.databaseName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);
    qDebug() << "Verbindung getrennt";
}


