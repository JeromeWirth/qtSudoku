#include <QtWidgets>
#include "timerwidget.h"

TimerWidget::TimerWidget(QWidget *parent) : QWidget(parent)
{
    m_timer = new QTimer();
    m_timeValue = new QTime(0,0,0);
    m_display = new QLabel(this);

    m_display->setText(m_timeValue->toString("mm:ss"));
    // m_display->setGeometry(10, 10, 80, 10);

    m_timer->start(1000);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(slotShowTimer()));
}

void TimerWidget::slotShowTimer() {
    this->m_timeValue->setHMS(0, this->m_timeValue->addSecs(1).minute(),
            this->m_timeValue->addSecs(1).second());
    this->m_display->setText(m_timeValue->toString("mm:ss"));
}

void TimerWidget::slotResetTimer() {
    this->m_timeValue->setHMS(0,0,0);
    this->m_display->setText(this->m_timeValue->toString("mm:ss"));
}