/**
  * TimerWidget-Klasse, zeigt die Zeit an, welche jede Sekunde zunimmt.
  * Wenn ein neues Sudoku gespielt wird, startet der Timer wieder bei Null.
  *
  * @author Jerome Wirth (532939)
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
    QTimer      *mTimer;
    QTime       *mTimeValue;
    QLabel      *mDisplay;
    QHBoxLayout *hLayout;

    int mSeconds = 0;

signals:
    void signal5ScondsPass();

public slots:
    void slotShowTimer();
    void slotResetTimer();
};

#endif // TIMERWIDGET_H
