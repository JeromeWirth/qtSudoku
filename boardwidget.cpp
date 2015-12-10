#include "boardwidget.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent)
{
    boardLogic = new BoardLogic();

    boardLogic->generateSudoku();
    boardLogic->printBoard();

    boardWidget = new QTableWidget(9,9,this);

    boardWidget->verticalHeader()->sectionResizeMode(QHeaderView::Fixed);
    boardWidget->verticalHeader()->setDefaultSectionSize(20);

    boardWidget->horizontalHeader()->sectionResizeMode(QHeaderView::Fixed);
    boardWidget->horizontalHeader()->setDefaultSectionSize(20);

    boardWidget->setFixedSize(200,210);

    displaySudoku();

    newSudokuButton = new QPushButton("New Sudoku", this);
    newSudokuButton->setGeometry(300, 10, 100, 20);

    connect(newSudokuButton, SIGNAL (clicked()), this, SLOT (slotCreateNewSudoku()));
}

void BoardWidget::displaySudoku() {
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            QTableWidgetItem *item = new QTableWidgetItem();
            QString number = QString::number(boardLogic->getNumber(row, col));
            item->setText(number);
            boardWidget->setItem(row, col, item);
        }
    }
}

void BoardWidget::slotCreateNewSudoku() {
    boardLogic->generateEmptySudoku();
    boardLogic->generateSudoku();
    displaySudoku();
}

