#ifndef SUDOKUITEM_H
#define SUDOKUITEM_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QDebug>

class SudokuItem : public QGraphicsItem
{
public:
    SudokuItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    QGraphicsTextItem *number;
};

#endif // SUDOKUITEM_H
