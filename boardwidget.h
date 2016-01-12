#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "boardlogic.h"

class QPushButton;
class QTableWidget;
class BoardWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BoardWidget(QWidget *parent = 0);

private:
    QPushButton *newSudokuButton;
    QTableWidget *boardWidget;
    BoardLogic *boardLogic;

    QHBoxLayout *layout;

    void initSudoku();
    void displaySudoku();

signals:

public slots:
    void slotCreateNewSudoku();

private slots:
    void slotReturnCellNumber(int row, int col);
    void slotCheckEnteredNumber(int row, int col);
};

#endif // BOARDWIDGET_H
