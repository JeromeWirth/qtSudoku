/**
  * Die Klasse steuert den Schwierigkeitsgrad des Sudokus.
  *
  * Das Fenster wird angezeigt, sobald der Benutzer ein neues Sudoku
  * spielen will.
  *
  * @author Jerome Wirth (532939)
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
