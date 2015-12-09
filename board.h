#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <random>

using namespace std;

class QPushButton;
class QTableWidget;
class Board : public QWidget
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);

private:
    QTableWidget *m_board;
    QPushButton *newSudokuButton;

    void createEmptySudoku();
    void insertNumber(int row, int col, int number);
    bool isNumberValid(int row, int col, int number);
    bool checkRow(int col, int number);
    bool checkCol(int row, int number);
    bool checkBlock(int row, int col, int number);

signals:

public slots:

private slots:
    void slotCreateSudoku();
};

#endif // BOARD_H
