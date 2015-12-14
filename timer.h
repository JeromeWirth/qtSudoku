#ifndef TIMER_H
#define TIMER_H

#include <QLCDNumber>

class Timer : public QLCDNumber
{
    Q_OBJECT

public:
    Timer(QWidget *parent = 0);

private:
    QTimer *m_timer;
    QTime *m_timeValue;

signals:

public slots:

private slots:
    void slotShowTime();
    void slotResetTime();
};

#endif // TIMER_H
