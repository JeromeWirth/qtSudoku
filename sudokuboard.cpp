#include "sudokuboard.h"

SudokuBoard::SudokuBoard()
{
}

QRectF SudokuBoard::boundingRect() const
{
    return QRectF(0, 0, 510, 510);
}

/**
 * @brief SudokuBoard::paint
 * Zeichnet die Linien für das Sudoku Feld
 *
 * @param painter
 * @param option
 * @param widget
 */
void SudokuBoard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black, 4, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);

    painter->setPen(pen);
    painter->drawLine(169, 0, 169, 510);
    painter->drawLine(341, 0, 341, 510);

    painter->drawLine(0, 169, 510, 169);
    painter->drawLine(0, 341, 510, 341);

    pen.setWidth(2);
    painter->setPen(pen);
    painter->drawLine(55, 0, 55, 510);
    painter->drawLine(111, 0, 111, 510);
    painter->drawLine(227, 0, 227, 510);
    painter->drawLine(283, 0, 283, 510);
    painter->drawLine(399, 0, 399, 510);
    painter->drawLine(455, 0, 455, 510);

    painter->drawLine(0, 55, 510, 55);
    painter->drawLine(0, 111, 510, 111);
    painter->drawLine(0, 227, 510, 227);
    painter->drawLine(0, 283, 510, 283);
    painter->drawLine(0, 399, 510, 399);
    painter->drawLine(0, 455, 510, 455);
}

