#include <QtWidgets>

#include "timer.h"

Timer::Timer(QWidget *parent) : QLCDNumber(parent)
{
    m_timer = new QTimer();
    m_timeValue = new QTime(0, 0, 0);

    this->setParent(parent);
    this->display(m_timeValue->toString());

    m_timer->start(1000);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(slotShowTime()));
}


void Timer::slotShowTime() {
    this->m_timeValue->setHMS(0,this->m_timeValue->addSecs(1).minute(),
                            this->m_timeValue->addSecs(1).second());
    this->display(this->m_timeValue->toString());

}

void Timer::slotResetTime() {
    this->m_timeValue->setHMS(0,0,0);
    this->display(this->m_timeValue->toString());
}
