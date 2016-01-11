#ifndef SCOREWIDGET_H
#define SCOREWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "scorelogic.h"

class ScoreWidget : public QWidget
{
public:
    explicit ScoreWidget(QWidget *parent = 0);

private:    
    ScoreLogic *scoreLogic;
    QLabel *scoreLabel;
    QLabel *multiplierLabel;
    QHBoxLayout *hLayout;

signals:

public slots:
};

#endif // SCOREWIDGET_H
