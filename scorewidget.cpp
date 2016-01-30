#include "scorewidget.h"

ScoreWidget::ScoreWidget(QWidget *parent) : QWidget(parent)
{
    scoreLogic = new ScoreLogic();
    scoreLabel = new QLabel();
    multiplierLabel = new QLabel();

    updateScore();

    hLayout = new QHBoxLayout;

    hLayout->addWidget(scoreLabel);
    hLayout->addWidget(multiplierLabel);

    this->setLayout(hLayout);
}

void ScoreWidget::updateScore() {
    QString scoreString = "Score: " + QString::number(scoreLogic->getScore());
    QString multiplierString = "x" + QString::number(scoreLogic->getMultiplier());

    scoreLabel->setText(scoreString);
    multiplierLabel->setText(multiplierString);
}

void ScoreWidget::slotCorrectNumber() {
    int points = scoreLogic->getScore() * scoreLogic->getMultiplier();

    qDebug() << "Adding Points = " << scoreLogic->getScore() << " x " << scoreLogic->getMultiplier() << " = " << points;

    scoreLogic->setScore(points);

    updateScore();
}

void ScoreWidget::slotFalseNumber() {
    int points = scoreLogic->getScore() - 100;

    qDebug() << "Substracting Points = " << scoreLogic->getScore() << " x " << scoreLogic->getMultiplier() << " = " << points;

    scoreLogic->setScore(points);

    updateScore();
}
