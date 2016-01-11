#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QDialog>
#include <QWidget>
#include <QMenuBar>
#include <QGroupBox>

class MainWindow : public QDialog
{
public:
    MainWindow();

private:
    void createMenu();
    void createHorizontalGroupBox();

    QMenuBar *menuBar;
    QGroupBox *horizontalGroupBox;
    QPushButton *buttons[9];

    QMenu *fileMenu;
    QAction *exitAction;

signals:

public slots:
};

#endif // MAINWINDOW_H
