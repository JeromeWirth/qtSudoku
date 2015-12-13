#include <QtWidgets>

#include "timer.h"

Timer::Timer(QWidget *parent) : QLCDNumber(parent)
{
    setSegmentStyle(Filled);

    QTimer *qTimer = new QTimer(this);
    connect(qTimer, SIGNAL(timeout()), this, SLOT (showTime()));
    qTimer->start(1000);

    showTime();

    resize(80, 40);
}


void Timer::showTime() {
    QTime time;
    time.restart();
    QString text = time.toString("hh:mm");
    if ((time.second() % 2) == 0) {
        text[2] = ' ';
    }
    display(text);
}
