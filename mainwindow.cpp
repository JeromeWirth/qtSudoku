#include <QtWidgets>

#include "mainwindow.h"

MainWindow::MainWindow()
{
    createMenu();
    createHorizontalGroupBox();

    QVBoxLayout *mainLayout = new QVBoxLayout;

    mainLayout->setMenuBar(menuBar);
    mainLayout->addWidget(horizontalGroupBox);

    setLayout(mainLayout);
    setWindowTitle(tr("qtSudoku"));
}

void MainWindow::createMenu() {
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    menuBar->addMenu(fileMenu);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(accept()));
}

void MainWindow::createHorizontalGroupBox() {
    horizontalGroupBox = new QGroupBox(tr("Horizontal Layout"));
    QHBoxLayout *layout = new QHBoxLayout;

    for (int i = 0; i < 9; ++i) {
        buttons[i] = new QPushButton(tr("Button %1").arg(i+1));
        layout->addWidget(buttons[i]);
    }

    horizontalGroupBox->setLayout(layout);
}

