#include "sudokuitem.h"

/**
 * @brief SudokuItem::SudokuItem
 * Konstruktor, der die Klassen-Variablen initalisiert
 */
SudokuItem::SudokuItem()
{
    mRow = 0;
    mCol = 0;
    mNumber = 0;
    pressed = false;
    mStatus = false;

    number = new QGraphicsTextItem(this);
    setNumber(mNumber);
}

QRectF SudokuItem::boundingRect() const
{
    return QRectF(2, 2, 50, 50);
}

/**
 * @brief SudokuItem::paint
 * Zeichnet ein Feld für das Sudoku-Brett, je nach Status wird es ausgemalt und enthält
 * eine Nummer, oder es hat die gleich Farbe wie der Hintgrund, sodass man es immernoch
 * anklicken, aber nicht sehen kann.
 *
 * @param painter
 * @param option
 * @param widget
 */
void SudokuItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QBrush brushCorrect(Qt::gray);
    QBrush brushIncorrect(Qt::white);
    QPen penCorrect(Qt::black);
    QPen penIncorrect(Qt::white);

    if(mStatus) {
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

/**
 * @brief SudokuItem::setRow
 * Speichert die aktuelle Reihe des Items
 *
 * @param row interge, mit aktueller Reihen-Zahl
 */
void SudokuItem::setRow(int row)
{
    mRow = row;
}

/**
 * @brief SudokuItem::setCol
 * Speichert die aktuelle Spalte des Items
 *
 * @param col integer mit aktueller Spalten-Zahl
 */
void SudokuItem::setCol(int col) {
    mCol = col;
}

/**
 * @brief SudokuItem::setNumber
 * Schreibt die Nummer in ein SudokuItem, falls die Nummer des geladenen
 * Sudokus an der Stelle "0" beträgt, wird nichts reingeschrieben.
 *
 * @param num integer, mit Zahl des Sudoku Feldes
 */
void SudokuItem::setNumber(int num)
{
    mNumber = num;

    QFont font;
    font.setPointSize(40);

    if (mNumber == 0) {
        number->setPlainText("");
    } else {
        number->setPlainText(QString::number(mNumber));
    }

    number->setDefaultTextColor(Qt::black);
    number->setFont(font);
    number->setX(this->boundingRect().center().x() - number->boundingRect().center().x());
    number->setY(this->boundingRect().center().y() - number->boundingRect().center().y());
}

/**
 * @brief SudokuItem::getRow
 * Gibt die aktuelle Reihe zurück
 *
 * @return integer, mit aktueller Reihen-Zahl
 */
int SudokuItem::getRow()
{
    return mRow;
}

/**
 * @brief SudokuItem::getCol
 * Gibt die aktuelle Spalte zurück
 *
 * @return integer, mit aktueller Spalten-Zahl
 */
int SudokuItem::getCol() {
    return mCol;
}

/**
 * @brief SudokuItem::getNumber
 * Gibt die Nummer des SudokuItems zurück
 *
 * @return integer, mit der Nummer
 */
int SudokuItem::getNumber()
{
    return mNumber;
}

/**
 * @brief SudokuItem::setStatus
 * Setzt den Status für das SudokuItem
 *
 * @param status bool, ob die Zahl schon gesetzt wurde.
 */
void SudokuItem::setStatus(bool status)
{
    mStatus = status;
}

/**
 * @brief SudokuItem::getStatus
 * Gibt den Status des Feldes wieder zurück
 *
 * @return bool, mit gesetzten Status
 */
bool SudokuItem::getStatus()
{
    return mStatus;
}

/**
 * @brief SudokuItem::mousePressEvent
 * mousePressEvent wurde so überschrieben, das es ein Signal auslöst, welche die
 * aktuelle Reihe und Spalte übergibt.
 *
 * @param event
 */
void SudokuItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit signalOnClick(mRow, mCol);
}
