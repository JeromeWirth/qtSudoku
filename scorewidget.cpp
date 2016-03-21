#include "scorewidget.h"

/**
 * @brief ScoreWidget::ScoreWidget
 * Erstellt ein Widget, welches die Punkte und den Multiplier darstellt
 *
 * @param parent
 */
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

/**
 * @brief ScoreWidget::updateScore
 * aktualisiert die Anzeige.
 */
void ScoreWidget::updateScore() {
    QString scoreString = "Score: " + QString::number(scoreLogic->getScore());
    QString multiplierString = "x" + QString::number(scoreLogic->getMultiplier());

    scoreLabel->setText(scoreString);
    multiplierLabel->setText(multiplierString);
}

/**
 * @brief ScoreWidget::getScore
 * Gibt den aktuellen Punktestand von der scoreLogic-Klasse zurück
 *
 * @return integer, mit aktuellen Punktestand
 */
int ScoreWidget::getScore()
{
    return scoreLogic->getScore();
}

/**
 * @brief ScoreWidget::slotCorrectNumber
 * Slot, wird ausgeführt, sobald der Spieler eine korrekte Zahl eingibt.
 */
void ScoreWidget::slotCorrectNumber() {
    scoreLogic->increaseScore(1);

    updateScore();
}

/**
 * @brief ScoreWidget::slotFalseNumber
 * Slot, wird ausgeführt, wenn der Spieler eine Falsche zahl eingibt.
 */
void ScoreWidget::slotFalseNumber() {
    scoreLogic->decreaseScore(3);
    scoreLogic->decreaseMultiplier(3);

    updateScore();
}

/**
 * @brief ScoreWidget::slotResetScore
 * Setzt die anzeige wieder zurück.
 */
void ScoreWidget::slotResetScore() {
    scoreLogic->resetScoreLogic();

    updateScore();
}

/**
 * @brief ScoreWidget::slotDecreaseMultiplier
 * Slot, wird ausgeführt, wenn 5 Sekunden vergehen, oder der Spieler eine falsche Zahl
 * eingibt.
 */
void ScoreWidget::slotDecreaseMultiplier()
{
    scoreLogic->decreaseMultiplier(1);

    updateScore();
}
