#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <QSignalBlocker>

#include <iostream>

#include "boardlogic.h"
#include "sudokusolver.h"

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
    SudokuSolver *solver;

    QHBoxLayout *layout;

    void initSudoku();
    void displaySudoku();
    bool checkSolved();

signals:
    void signalCorrectNumber();
    void signalFalseNumber();

public slots:
    void slotCreateNewSudoku();
    void slotReturnCellNumber(int row, int col);
    void slotCheckEnteredNumber(int row, int col);
};

#endif // BOARDWIDGET_H
