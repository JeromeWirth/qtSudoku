#ifndef SUDOKUWIDGET_H
#define SUDOKUWIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "sudokuboard.h"
#include "sudokuitem.h"

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

    void displayItems();

signals:

public slots:
};

#endif // SUDOKUWIDGET_H
