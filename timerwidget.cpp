#include "timerwidget.h"

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

void TimerWidget::slotShowTimer() {
    this->mTimeValue->setHMS(0, this->mTimeValue->addSecs(1).minute(),
            this->mTimeValue->addSecs(1).second());
    this->mDisplay->setText(mTimeValue->toString("mm:ss"));

    mSeconds++;

    if (mSeconds%5 == 0) {
        emit signal5ScondsPass();
    }
}

void TimerWidget::slotResetTimer() {
    this->mTimeValue->setHMS(0,0,0);
    this->mDisplay->setText(this->mTimeValue->toString("mm:ss"));
}
