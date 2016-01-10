#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include "scorelogic.h"
#include "timerwidget.h"

class ScoreWidget : public QWidget
{
public:
    explicit ScoreWidget(QWidget *parent = 0);

private:
    ScoreLogic *scoreLogic;
    QLabel *scoreLabel;
    QLabel *multiplierLabel;
    TimerWidget *timerWidget;

signals:

public slots:
};

#endif // SCOREWIDGET_H
