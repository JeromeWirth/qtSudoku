#include "boardwidget.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <iostream>

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
    connect(boardWidget, SIGNAL (cellClicked(int,int)), this, SLOT (slotReturnCellNumber(int,int)));
    connect(boardWidget, SIGNAL (cellChanged(int,int)), this, SLOT (slotCheckEnteredNumber(int, int)));
}

void BoardWidget::displaySudoku() {
    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            QTableWidgetItem *item = new QTableWidgetItem();
            QString number = QString::number(boardLogic->getNumber(row, col));
            item->setText(number);

            if (number.toInt() != 0) {
                item->setText(number);
                item->setBackgroundColor(Qt::green);
                item->setFlags(Qt::ItemIsEditable);
            } else {
                item->setText(QString(""));
            }

            boardWidget->setItem(row, col, item);
        }
    }
}

void BoardWidget::slotCreateNewSudoku() {
    boardLogic->generateEmptySudoku();
    boardLogic->generateSudoku();
    displaySudoku();
}

void BoardWidget::slotReturnCellNumber(int row, int col) {
    cout << "--------------------------------" << endl;
    boardLogic->getNumber(row, col);
    QString number = boardWidget->item(row, col)->text();
    cout << "[BoardWidget] Row: " << row << " Col: " << col << " Number: " << number.toStdString() << endl;
    cout << "--------------------------------" << endl;
}

void BoardWidget::slotCheckEnteredNumber(int row, int col) {
    QString sNumber = boardWidget->item(row, col)->text();

    if (sNumber.toInt()) {
        cout << "Entered number ist accepted (" << sNumber.toInt() << ")" << endl;
        if (boardLogic->insertNumber(row, col, sNumber.toInt())) {
            cout << "Entered number is valid (" << sNumber.toInt() << ")" << endl;
            boardWidget->item(row, col)->setBackgroundColor(Qt::green);
            boardWidget->item(row, col)->setFlags(Qt::ItemIsEditable);
        } else {
            cout << "Entered number is not valid (" << sNumber.toStdString() << ")" << endl;
            boardWidget->item(row,col)->setText(QString(""));
        }
    } else {
        cout << "Entered number is not accpeted (" << sNumber.toStdString() << ")" << endl;
        boardWidget->item(row,col)->setText(QString(""));
    }
}
