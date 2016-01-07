#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include "scorelogic.h"

class QLabel;
class ScoreWidget : public QWidget
{
public:
    explicit ScoreWidget(QWidget *parent = 0);

private:
    ScoreLogic *scoreLogic;
    QLabel *scoreLabel;
    QLabel *multiplierLabel;

signals:

public slots:
};

#endif // SCOREWIDGET_H
