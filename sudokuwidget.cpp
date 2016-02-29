#include "sudokuwidget.h"

SudokuWidget::SudokuWidget(QWidget *parent)
{
    board = new SudokuBoard();
    scene = new QGraphicsScene();
    view = new QGraphicsView(this);

    setMinimumHeight(511);
    setMaximumHeight(511);
    setMinimumWidth(511);
    setMaximumWidth(511);

    displayItems();

    scene->addItem(board);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
}

void SudokuWidget::displayItems()
{
    int offset = 4;
    int xoffset = 0;
    int yoffset = 0;

    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0 && row != 0) {
            xoffset++;
        }
        for (int col = 0; col < 9; col++) {
            items[row][col] = new SudokuItem();
            if (col % 3 == 0 && col != 0) {
                yoffset++;
            }
            items[row][col]->setX((row*56)+(offset*xoffset));
            items[row][col]->setY((col*56)+(offset*yoffset));
            items[row][col]->setRow(row+1);
            items[row][col]->setCol(col+1);
            items[row][col]->setNumber(5);
            scene->addItem(items[row][col]);
        }
        yoffset = 0;
    }
}

