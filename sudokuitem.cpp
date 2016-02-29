#include "sudokuitem.h"

SudokuItem::SudokuItem()
{
    m_row = 0;
    m_col = 0;
    m_number = 0;
    pressed = false;

    number = new QGraphicsTextItem(this);
    setNumber(m_number);
}

QRectF SudokuItem::boundingRect() const
{
    return QRectF(2, 2, 50, 50);
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

void SudokuItem::setRow(int row)
{
    m_row = row;
}

void SudokuItem::setCol(int col) {
    m_col = col;
}

void SudokuItem::setNumber(int num)
{
    m_number = num;

    QFont font;
    font.setPointSize(40);

    number->setPlainText(QString::number(m_number));
    number->setDefaultTextColor(Qt::black);
    number->setFont(font);
    number->setX(this->boundingRect().center().x() - number->boundingRect().center().x());
    number->setY(this->boundingRect().center().y() - number->boundingRect().center().y());
}

int SudokuItem::getRow()
{
    return m_row;
}

int SudokuItem::getCol() {
    return m_col;
}

void SudokuItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    qDebug() << "Row: " << m_row << ", Col: " << m_col << endl;
}
