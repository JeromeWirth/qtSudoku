/**
  * SudokuBoard zeichnet ein Gitternetzt, welches das Sudoku Feld darstellt.
  *
  * @author Jerome Wirth (532939)
  */
#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QDebug>

class SudokuBoard : public QGraphicsItem
{
public:
    SudokuBoard();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SUDOKUBOARD_H
