/*
 * The NewGameClas sets up the difficulty. The user can choose between 3
 * difficulty settings: Easy, Normal and Hard.
 * A Signal, with the information on which button was pressed will be send to the MainWindow,
 * where it gets connected to the SudokuWidget to load a new Sudoku with the correct difficulty.
 *
 * Author: Jerome Wirth
 * Matrikel-Nr.: 532939
 */
#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>

class NewGameWindow : public QDialog
{
    Q_OBJECT

public:
    NewGameWindow();

private:
    QHBoxLayout *buttonLayout;
    QVBoxLayout *layout;
    QLabel      *text;
    QPushButton *easyGame;
    QPushButton *normalGame;
    QPushButton *hardGame;
    QButtonGroup *buttonGroup;


signals:
    void signalNewGame(int difficult);

public slots:
};

#endif // NEWGAMEWINDOW_H
