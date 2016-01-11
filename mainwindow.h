#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QMenuBar>
#include <QGroupBox>

#include "boardwidget.h"
#include "timerwidget.h"
#include "scorewidget.h"

class MainWindow : public QDialog
{
public:
    MainWindow();

private:
    void createMenu();
    void createScoreAndTimeBox();
    void createControlGroupBox();

    QMenuBar *menuBar;
    QGroupBox *scoreAndTimeBox;
    QGroupBox *controlGroupBox;
    QPushButton *buttons[9];

    QMenu *fileMenu;
    QAction *exitAction;
    QAction *newSudokuAction;
    TimerWidget *timer;
    ScoreWidget *score;
    BoardWidget *board;

signals:

public slots:
};

#endif // MAINWINDOW_H
