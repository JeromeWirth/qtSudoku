#include "sudokuwidget.h"

/**
 * @brief SudokuWidget::SudokuWidget
 * Erstellt das Widget, welches einmal das Sudoku Feld enthält und die SudokuItems
 */
SudokuWidget::SudokuWidget()
{
    board = new SudokuBoard();
    scene = new QGraphicsScene();
    view = new QGraphicsView(this);
    loader = new SudokuLoader("level/003.txt");
    input = new QLineEdit(this);

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

    displaySudoku();

    scene->addItem(board);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);

    connect(input, SIGNAL(returnPressed()), this, SLOT(slotCheckInput()));
}

/**
 * @brief SudokuWidget::displaySudoku
 * Platziert die SudokuItems so, dass sie genau auf das Feld passen.
 * Items die den status auf false gesetzt haben, werden nicht angezeigt
 * Damit man Nummern eingeben kann, wird jedes Item mit dem mouseEvent Signal verknüpft
 */
void SudokuWidget::displaySudoku()
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

/**
 * @brief SudokuWidget::countCorrectNumbers
 * Zähl und gibt die möglichen Züge, bei 81 ist das Spiel beendet
 * @return Anzahl der möglichen Züge
 */
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


/**
 * @brief SudokuWidget::slotInputNumber
 * Funktion ermöglicht das eingeben von Zahlen, sobald ein leeres Feld angeklickt wurde
 * öffnet sich ein QEditLine, welche die größe und position des angeklickten SudokuItems kriegt.
 *
 * @param row die Reihe, in die geklickt wurde
 * @param col die Spalte in die geklickt wurde
 */
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

/**
 * @brief SudokuWidget::slotCheckInput
 * Nachdem der Spieler seine Eingabe mit 'Enter' bestätitgt, wird die eingabe geprüft.
 * Stimm die Zahl mit der Zahl im gelösten Sudoku überein, kriegt das SudokuItem an dieser
 * Position den Status True, und wird auf dem Spielfeld angezeigt.
 *
 * Nach der eingabe, wird geprüft, ob das Spiel beendet ist.
 */
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

/**
 * @brief SudokuWidget::loadSudoku
 * Läd das erste Sudoku-Feld
 */
void SudokuWidget::loadSudoku() {
    loader->loadLevel("level/003.txt");

    displaySudoku();
}

/**
 * @brief SudokuWidget::slotLoadSudoku
 * Läd ein Sudoku-Feld mit dem angegeben Schwierigkeitsgrad
 *
 * @param difficult der Schwierigkeitsgrad
 */
void SudokuWidget::slotLoadSudoku(int difficult) {
    RandomPathGenerator path(difficult);
    qDebug() << path.getFilePath();

    loader->loadLevel(path.getFilePath());
    displaySudoku();
}


/**
 * @brief SudokuWidget::slotSolveSudoku
 * Die Funktion setzt alle verbleibenen SudokuItems auf true,
 * um das Sudoku lösen zu lassen
 */
void SudokuWidget::slotSolveSudoku() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if(!items[row][col]->getStatus()) {
                int number = loader->getNumber(row, col, true);
                items[row][col]->setNumber(number);
                items[row][col]->setStatus(true);
            }
        }
    }

    emit signalFinishedGame();
}
