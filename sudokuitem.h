
#ifndef SUDOKUITEM_H
#define SUDOKUITEM_H

#include <QObject>
#include <QPainter>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class SudokuItem : public QGraphicsObject
{
    Q_OBJECT

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
    void setStatus(bool status);
    bool getStatus();

private:
    int mRow, mCol, mNumber;
    QGraphicsTextItem *number;
    bool pressed;
    bool mStatus;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void signalOnClick(int row, int col);

public slots:
};

#endif // SUDOKUITEM_H
