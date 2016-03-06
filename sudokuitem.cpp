#include "sudokuitem.h"

SudokuItem::SudokuItem()
{
    m_row = 0;
    m_col = 0;
    m_number = 0;
    pressed = false;
    m_status = false;

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
    QBrush brushCorrect(Qt::gray);
    QBrush brushIncorrect(Qt::white);
    QPen penCorrect(Qt::black);
    QPen penIncorrect(Qt::white);

    if(m_status) {
        penCorrect.setWidth(3);
        painter->fillRect(rect, brushCorrect);
        painter->setPen(penCorrect);
        painter->drawRect(rect);
    } else {
        penIncorrect.setWidth(3);
        painter->fillRect(rect, brushIncorrect);
        painter->setPen(penIncorrect);
        painter->drawRect(rect);
    }
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

    if (m_number == 0) {
        number->setPlainText("");
    } else {
        number->setPlainText(QString::number(m_number));
    }

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

int SudokuItem::getNumber()
{
    return m_number;
}

void SudokuItem::setStatus(bool status)
{
    m_status = status;
}

bool SudokuItem::getStatus()
{
    return m_status;
}

void SudokuItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalOnClick(m_row, m_col);
}
