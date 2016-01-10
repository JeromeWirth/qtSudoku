#include "scorewidget.h"
#include <QLabel>
#include <QString>

ScoreWidget::ScoreWidget(QWidget *parent) : QWidget(parent)
{
    scoreLogic = new ScoreLogic();
    scoreLabel = new QLabel(this);
    multiplierLabel = new QLabel(this);
    timerWidget = new TimerWidget(this);

    QString scoreString = "Score: " + QString::number(scoreLogic->getScore());
    QString multiplierString = "x" + QString::number(scoreLogic->getMultiplier());

    scoreLabel->setText(scoreString);
    scoreLabel->setGeometry(10, 10, 60, 10);

    multiplierLabel->setText(multiplierString);
    multiplierLabel->setGeometry(75, 10, 40, 10);

    timerWidget->setGeometry(125, 10, 50, 10);

}

