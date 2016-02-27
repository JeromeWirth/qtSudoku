#ifndef SUDOKUWIDGET_H
#define SUDOKUWIDGET_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsTextItem>
#include <QDebug>

class SudokuWidget : public QGraphicsItem
{
public:
    SudokuWidget();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SUDOKUWIDGET_H
