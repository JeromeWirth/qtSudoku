#include "timerwidget.h"

/**
 * @brief TimerWidget::TimerWidget
 * Erstellt ein neues Widget für die Zeitanzeige
 *
 * @param parent
 */
TimerWidget::TimerWidget(QWidget *parent) : QWidget(parent)
{
    mTimer = new QTimer();
    mTimeValue = new QTime(0,0,0);
    mDisplay = new QLabel();
    hLayout = new QHBoxLayout;

    mDisplay->setText(mTimeValue->toString("mm:ss"));

    hLayout->addWidget(mDisplay);

    this->setLayout(hLayout);

    mTimer->start(1000);

    connect(mTimer, SIGNAL(timeout()), this, SLOT(slotShowTimer()));
}

/**
 * @brief TimerWidget::slotShowTimer
 * Slot wird nach jeder Sekunde ausgeführt und auf den aktuellen Timer
 * wird eine Sekunde addiert.
 *
 * Nach 5 Sekunden wird ein Signal ausgegeben, damit der Multiplier im ScoreWidget
 * heruntergesetzt werden kann.
 */
void TimerWidget::slotShowTimer() {
    this->mTimeValue->setHMS(0, this->mTimeValue->addSecs(1).minute(),
            this->mTimeValue->addSecs(1).second());
    this->mDisplay->setText(mTimeValue->toString("mm:ss"));

    mSeconds++;

    if (mSeconds%5 == 0) {
        emit signal5ScondsPass();
    }
}

/**
 * @brief TimerWidget::slotResetTimer
 * Stellt den Timer wieder zurück auf Null.
 */
void TimerWidget::slotResetTimer() {
    this->mTimeValue->setHMS(0,0,0);
    this->mDisplay->setText(this->mTimeValue->toString("mm:ss"));
}
