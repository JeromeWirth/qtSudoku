/*
 * TimerWidget display a timer, wich gets decreased every second,
 * when a new Sudoku is loaded, the timer resets.
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 532939
 */

#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QtWidgets>

class TimerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TimerWidget(QWidget *parent = 0);

private:
    QTimer *m_timer;
    QTime *m_timeValue;
    QLabel *m_display;
    QHBoxLayout *hLayout;
    int m_seconds = 0;

signals:
    void signal5ScondsPass();

public slots:
    void slotShowTimer();
    void slotResetTimer();
};

#endif // TIMERWIDGET_H
