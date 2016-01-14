#include "scorewidget.h"
#include <QLabel>
#include <QString>

ScoreWidget::ScoreWidget(QWidget *parent) : QWidget(parent)
{
    scoreLogic = new ScoreLogic();
    scoreLabel = new QLabel();
    multiplierLabel = new QLabel();

    QString scoreString = "Score: " + QString::number(scoreLogic->getScore());
    QString multiplierString = "x" + QString::number(scoreLogic->getMultiplier());

    scoreLabel->setText(scoreString);
    multiplierLabel->setText(multiplierString);

    hLayout = new QHBoxLayout;

    hLayout->addWidget(scoreLabel);
    hLayout->addWidget(multiplierLabel);

    this->setLayout(hLayout);
}

void ScoreWidget::slotCorrectNumber() {
    int points = scoreLogic->getScore() * scoreLogic->getMultiplier();

    QString scoreString = "Score: " + QString::number(points);

    qDebug() << "Adding Points = " << scoreLogic->getScore() << " x " << scoreLogic->getMultiplier() << " = " << points;

    scoreLogic->setScore(points);
    scoreLabel->setText(scoreString);
}

