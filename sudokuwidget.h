/*
 * SudokuWidget holds the SudokuBoard and the SudokuItems.
 * The Class iterates through the array from the loaded Sudoku
 * and places each item on to its corresponding position.
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 532939
 */
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
    explicit SudokuWidget();

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
    void slotSolveSudoku();

};

#endif // SUDOKUWIDGET_H
