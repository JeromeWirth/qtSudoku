#include "board.h"
#include <QTableWidget>
#include <QHeaderView>
#include <QPushButton>
#include <iostream>

Board::Board(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 400);

    m_board = new QTableWidget(9,9,this);

    createEmptySudoku();

    m_board->verticalHeader()->sectionResizeMode(QHeaderView::Fixed);
    m_board->verticalHeader()->setDefaultSectionSize(20);

    m_board->horizontalHeader()->sectionResizeMode(QHeaderView::Fixed);
    m_board->horizontalHeader()->setDefaultSectionSize(20);

    m_board->setFixedSize(200,210);

    newSudokuButton = new QPushButton("New Sudoku",this);
    newSudokuButton->setGeometry(300, 10, 100, 20);

    connect(newSudokuButton, SIGNAL (clicked()), this, SLOT (slotCreateSudoku()));
}

void Board::slotCreateSudoku() {
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int>uni(1,9);

    for(int col = 0; col < 9; col++) {
        for(int row = 0; row < 9; row++) {
            auto number = uni(rng);
            insertNumber(row, col, number);

//            QTableWidgetItem *item = new QTableWidgetItem;
//            item->setText(QString::number(number));
//            m_board->setItem(row, col, item);

//            QString text = m_board->item(row, col)->text();
//            QString test = QString::number(1);

//            if(text == test) {
//                cout << "TEST and TEXT are the SAME" << endl;
//            }
        }
    }
}

void Board::createEmptySudoku() {
    for(int col = 0; col < 9; col++) {
        for(int row = 0; row < 9; row++) {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(QString::number(0));
            m_board->setItem(row, col, item);
        }
    }

}

void Board::insertNumber(int row, int col, int number) {
    if(isNumberValid(row, col, number)) {
        QString s = QString::number(number);
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(s);

        if(number != 0) {
            item->setBackgroundColor(Qt::green);
            item->setFlags(Qt::ItemIsEditable);
        } else {
            item->setText(QString(""));
        }
    m_board->setItem(row,col,item);
    }
}

/*
 prüft ob die Zahl ein gültiger Zug ist
*/
bool Board::isNumberValid(int row, int col, int number) {
    if (checkCol(row, number) && checkRow(col, number) && checkBlock(row, col, number)) {
        return true;
    }
    return false;
}

bool Board::checkCol(int row, int number) {
    QString sNumber = QString::number(number);
    for(int col = 0; col < 9; col++) {
        QString temp = m_board->item(row,col)->text();
        if(sNumber == temp) {
            return false;
        }
    }
    return true;
}

bool Board::checkRow(int col, int number) {
    QString sNumber = QString::number(number);
    for(int row = 0; row < 9; row++) {
        QString temp = m_board->item(row, col)->text();

        if(sNumber == temp) {
            return false;
        }
    }
    return true;
}

bool Board::checkBlock(int row, int col, int number) {
  int startx = row - (row%3);
  int starty = col - (col%3);

  QString sNumber = QString::number(number);

  for (int col = starty; col < (starty + 3); col++) {
    for (int row = startx; row < (startx + 3); row++) {
      QString temp = m_board->item(row, col)->text();

      if (sNumber == temp) {
            return false;
      }
    }
  }

  return true;
}
