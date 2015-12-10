#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include "boardlogic.h"

class QPushButton;
class QTableWidget;
class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = 0);

private:
    QPushButton *newSudokuButton;
    QTableWidget *boardWidget;
    BoardLogic *boardLogic;

    void displaySudoku();

signals:

public slots:

private slots:
    void slotCreateNewSudoku();
};

#endif // BOARDWIDGET_H
