#ifndef SUDOKUWIDGET_H
#define SUDOKUWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>

#include "sudokuboard.h"
#include "sudokuitem.h"
#include "sudokuloader.h"

class SudokuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SudokuWidget(QWidget *parent = 0);

private:
    QGraphicsView   *view;
    QGraphicsScene  *scene;
    SudokuItem      *items[9][9];
    SudokuBoard     *board;
    SudokuLoader    *loader;
    QLineEdit       *input;

    int tempRow;
    int tempCol;

    void displayItems();
    void loadSudoku();
    int countCorrectNumbers();

signals:
    void signalCorrectNumber();
    void signalFalseNumber();
    void signalFinishedGame();

public slots:
    void slotInputNumber(int row, int col);
    void slotCheckInput();
};

#endif // SUDOKUWIDGET_H
