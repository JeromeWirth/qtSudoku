#include "sudokuwidget.h"

SudokuWidget::SudokuWidget()
{
}

QRectF SudokuWidget::boundingRect() const
{
    return QRectF(0, 0, 450, 450);
}

void SudokuWidget::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::blue, 3, Qt::SolidLine, Qt::SquareCap, Qt::BevelJoin);

    painter->setPen(pen);
    painter->drawLine(0, 0, 0, 450);
}

