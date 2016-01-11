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

