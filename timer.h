#ifndef TIMER_H
#define TIMER_H

#include <QLCDNumber>

class Timer : public QLCDNumber
{
    Q_OBJECT

public:
    Timer(QWidget *parent = 0);

signals:

public slots:

private slots:
    void showTime();
};

#endif // TIMER_H
