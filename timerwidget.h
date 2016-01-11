#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>

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

signals:

public slots:

private slots:
    void slotShowTimer();
    void slotResetTimer();
};

#endif // TIMERWIDGET_H
