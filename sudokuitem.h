/**
  * SudokuItem stellt die einzelnen Felder des Sudoku Feldes dar.
  * Dabei werden Felder, welche noch keine Zahl haben, so dargestellt, dass
  * sie für den Spieler nicht sichtbar, aber anklickbar sind.
  *
  * @author Jerome Wirth (532939)
  */
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
