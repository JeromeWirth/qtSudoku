#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QtDebug>
#include <QString>

#include "scorelogic.h"

class ScoreWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ScoreWidget(QWidget *parent = 0);

    int getScore();

private:    
    ScoreLogic *scoreLogic;
    QLabel *scoreLabel;
    QLabel *multiplierLabel;
    QHBoxLayout *hLayout;

    void updateScore();

signals:

public slots:
    void slotCorrectNumber();
    void slotFalseNumber();
    void slotResetScore();
    void slotDecreaseMultiplier();
};

#endif // SCOREWIDGET_H
