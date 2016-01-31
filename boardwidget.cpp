#include "boardwidget.h"

BoardWidget::BoardWidget(QWidget *parent) : QWidget(parent)
{
    solver = new SudokuSolver();
    boardWidget = new QTableWidget(9,9);
    layout = new QHBoxLayout;

    boardWidget->verticalHeader()->setDefaultSectionSize(20);
    boardWidget->verticalHeader()->sectionResizeMode(QHeaderView::Fixed);

    boardWidget->horizontalHeader()->setDefaultSectionSize(20);
    boardWidget->horizontalHeader()->sectionResizeMode(QHeaderView::Fixed);

    layout->addWidget(boardWidget);

    this->setLayout(layout);
    this->setMinimumHeight(230);

    initSudoku();

    connect(boardWidget, SIGNAL (cellClicked(int,int)), this, SLOT (slotReturnCellNumber(int,int)));
    connect(boardWidget, SIGNAL (cellChanged(int,int)), this, SLOT (slotCheckEnteredNumber(int,int)));
}

void BoardWidget::initSudoku() {
    const QSignalBlocker blocker(boardWidget);

        for (int col = 0; col < 9; col++) {
            for (int row = 0; row < 9; row++) {
                boardWidget->setItem(row, col, new QTableWidgetItem(QString("")));
            }
        }
        displaySudoku();
}

void BoardWidget::displaySudoku() {
    const QSignalBlocker blocker(boardWidget);

    Qt::ItemFlags flags;

    for (int col = 0; col < 9; col++) {
        for (int row = 0; row < 9; row++) {
            QString number = QString::number(solver->getNumber(row, col, false));
            flags = boardWidget->item(row, col)->flags();

            if (number.toInt() != 0) {
                flags &= ~Qt::ItemIsEditable;

                boardWidget->item(row, col)->setText(number);
                boardWidget->item(row, col)->setBackgroundColor(Qt::green);
                boardWidget->item(row, col)->setFlags(flags);
            } else {
                flags |= Qt::ItemIsEditable;

                boardWidget->item(row, col)->setText(QString(""));
                boardWidget->item(row, col)->setBackgroundColor(Qt::white);
                boardWidget->item(row, col)->setFlags(flags);
            }
        }
    }

    checkSolved();
}

bool BoardWidget::checkSolved() {
    if (solver->countNumbers() == 81) {
        cout << "Gratulatin Sudoku ist fertig !!!!!" << endl;

        return true;
    } else {
        cout << "Nächster Zug!" << endl;

        return false;
    }
}

void BoardWidget::slotCreateNewSudoku() {
    solver->initPreSetSudoku();
    if(solver->solveSudoku()) {
        solver->createUnsolvedBoard();
        displaySudoku();
    }
    emit signalNewSudoku();
}

void BoardWidget::slotReturnCellNumber(int row, int col) {
    cout << "--------------------------------" << endl;
    solver->getNumber(row, col, false);
    QString number = boardWidget->item(row, col)->text();
    cout << "[BoardWidget] Row: " << row << " Col: " << col << " Number: " << number.toStdString() << endl;
    cout << "--------------------------------" << endl;
}

void BoardWidget::slotCheckEnteredNumber(int row, int col) {
    // Store the entered Number in a QString
    const QSignalBlocker blocker(boardWidget);

    QString qNumber = boardWidget->item(row, col)->text();

    if (solver->checkEnteredNumber(row, col, qNumber.toInt())) {
        solver->setNumber(row, col);
        displaySudoku();

        emit signalCorrectNumber();
    } else {
        boardWidget->item(row, col)->setBackground(Qt::red);
        boardWidget->item(row, col)->setText(QString(""));
        boardWidget->clearSelection();

        cout << "FALSE NUMBER ENTERED!!!!!" << endl;

        emit signalFalseNumber();
    }

}
