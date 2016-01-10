#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QLabel>

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = 0);

private:
    QTimer *m_timer;
    QTime *m_timeValue;
    QLabel *m_display;

signals:

public slots:

private slots:
    void slotShowTimer();
    void slotResetTimer();
};

#endif // TIMERWIDGET_H
