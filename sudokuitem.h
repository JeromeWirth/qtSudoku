#ifndef SUDOKUITEM_H
#define SUDOKUITEM_H

#include <QPainter>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class SudokuItem : public QGraphicsItem
{
public:
    SudokuItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setRow(int row);
    void setCol(int col);
    void setNumber(int num);
    int getRow();
    int getCol();
    int getNumber();

private:
    int m_row, m_col, m_number;
    QGraphicsTextItem *number;
    bool pressed;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SUDOKUITEM_H
