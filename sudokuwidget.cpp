#include "sudokuwidget.h"

SudokuWidget::SudokuWidget(QWidget *parent)
{
    board = new SudokuBoard();
    scene = new QGraphicsScene();
    view = new QGraphicsView(this);
    loader = new SudokuLoader("level/003.txt");
    input = new QLineEdit(this);
    finishGame = new QMessageBox();


    QFont font;
    font.setPointSize(40);

    input->setMinimumSize(50, 50);
    input->setMaximumSize(50, 50);
    input->setMaxLength(1);
    input->setFont(font);
    input->hide();

    setMinimumHeight(512);
    setMaximumHeight(512);
    setMinimumWidth(512);
    setMaximumWidth(512);

    slotLoadSudoku();

    scene->addItem(board);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);

    connect(input, SIGNAL(returnPressed()), this, SLOT(slotCheckInput()));
    connect(this, SIGNAL(signalFinishedGame()), this, SLOT(slotFinishGame()));
    connect(finishGame, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(loadSudoku()));
}

void SudokuWidget::slotLoadSudoku()
{
    emit signalNewSudoku();

    int offset = 4;
    int xoffset = 0;
    int yoffset = 0;

    for (int row = 0; row < 9; row++) {
        if (row % 3 == 0 && row != 0) {
            yoffset++;
        }
        for (int col = 0; col < 9; col++) {
            items[row][col] = new SudokuItem();
            connect(items[row][col], SIGNAL(signalOnClick(int, int)), this, SLOT(slotInputNumber(int, int)));

            if (col % 3 == 0 && col != 0) {
                xoffset++;
            }
            int temp_num = loader->getNumber(row, col, false);

            if (temp_num == 0) {
                items[row][col]->setStatus(false);
            } else {
                items[row][col]->setStatus(true);
            }

            items[row][col]->setX((col*56)+(offset*xoffset));
            items[row][col]->setY((row*56)+(offset*yoffset));
            items[row][col]->setRow(row+1);
            items[row][col]->setCol(col+1);
            items[row][col]->setNumber(temp_num);
            scene->addItem(items[row][col]);
        }
        xoffset = 0;
    }
}

int SudokuWidget::countCorrectNumbers()
{
    int correct = 0;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if(items[row][col]->getStatus()) {
                correct++;
            }
        }
    }

    return correct;
}

void SudokuWidget::slotInputNumber(int row, int col)
{
    input->clear();

    if(!items[row-1][col-1]->getStatus()) {
        int x = items[row-1][col-1]->pos().x()+3;
        int y = items[row-1][col-1]->pos().y()+3;

        input->setGeometry(x, y, 50, 50);

        tempRow = row-1;
        tempCol = col-1;

        input->show();
        input->setFocus();
    } else {
        input->hide();
    }

}

void SudokuWidget::slotCheckInput()
{
    input->hide();

    int num = input->text().toInt();

    if (num == loader->getNumber(tempRow, tempCol, true)) {
        items[tempRow][tempCol]->setNumber(num);
        items[tempRow][tempCol]->setStatus(true);

        emit signalCorrectNumber();
    } else {
        emit signalFalseNumber();
    }

    if(countCorrectNumbers() == 81) {
        qDebug() << "Spiel beendet!";
        emit signalFinishedGame();
    } else {
        qDebug() << "Noch weite Züge möglich: " << countCorrectNumbers();
    }

    input->clear();
}

void SudokuWidget::slotFinishGame() {
    finishGame->setWindowTitle("Glückwunsch!");
    finishGame->setText("DU hast gewonnen!");
    finishGame->show();
}

void SudokuWidget::loadSudoku() {
    loader->loadLevel("level/001.txt");

    slotLoadSudoku();
}
