#ifndef SUDOKUWIDGET_H
#define SUDOKUWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>

#include "sudokuboard.h"
#include "sudokuitem.h"
#include "sudokuloader.h"
#include "randompathgenerator.h"

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

    int countCorrectNumbers();
    void displaySudoku();

signals:
    void signalCorrectNumber();
    void signalFalseNumber();
    void signalFinishedGame();
    void signalNewSudoku();

public slots:
    void slotInputNumber(int row, int col);
    void slotCheckInput();
    void loadSudoku();
    void slotLoadSudoku(int difficult);

};

#endif // SUDOKUWIDGET_H
