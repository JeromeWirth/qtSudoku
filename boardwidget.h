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
    QPushButton *one, *two, *three, *four, *five, *six, *seven, *eight, *nine;
    QTableWidget *boardWidget;
    BoardLogic *boardLogic;

    void initSudoku();
    void displaySudoku();

signals:

public slots:

private slots:
    void slotCreateNewSudoku();
    void slotReturnCellNumber(int row, int col);
    void slotCheckEnteredNumber(int row, int col);
};

#endif // BOARDWIDGET_H
