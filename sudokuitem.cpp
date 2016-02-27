#include "sudokuitem.h"

SudokuItem::SudokuItem()
{
    QFont font;
    font.setPointSize(40);

    number = new QGraphicsTextItem(this);

    number->setPlainText("1");
    number->setDefaultTextColor(Qt::black);
    number->setFont(font);
    number->setX(this->boundingRect().center().x() - number->boundingRect().center().x());
    number->setY(this->boundingRect().center().y() - number->boundingRect().center().y());
}

QRectF SudokuItem::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void SudokuItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brush(Qt::gray);
    QPen pen(Qt::black);
    pen.setWidth(3);

    painter->fillRect(rect, brush);
    painter->setPen(pen);
    painter->drawRect(rect);
}
