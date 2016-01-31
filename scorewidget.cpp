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
    scoreLogic->increaseScore();

    updateScore();
}

void ScoreWidget::slotFalseNumber() {
    scoreLogic->decreaseScore(5);

    updateScore();
}

void ScoreWidget::slotDecreaseMultiplier() {
    scoreLogic->decreaseMultiplier();

    updateScore();
}

void ScoreWidget::slotResetScore() {
    scoreLogic->resetScoreLogic();

    updateScore();
}
