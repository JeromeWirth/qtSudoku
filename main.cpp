#include <QtWidgets>
#include <QHBoxLayout>
#include "window.h"
#include "board.h"
#include "boardlogic.h"
#include "boardwidget.h"

int main(int argc, char **argv) {
    QApplication app (argc, argv);

//    // Create a container Window
//    QWidget window;
//    window.setFixedSize(200, 80);

//    // Create a progress bar
//    // with the range between 0 and 100 and a starting value of 0
//    QProgressBar *progressBar = new QProgressBar(&window);
//    progressBar->setRange(0, 100);
//    progressBar->setValue(0);
//    progressBar->setGeometry(10, 10, 180, 30);

//    // Create a horizontal Slider
//    // with the range between 0 and 100, an a starting value of 0
//    QSlider *slider = new QSlider(&window);
//    slider->setOrientation(Qt::Horizontal);
//    slider->setRange(0,100);
//    slider->setValue(0);
//    slider->setGeometry(10, 40, 180, 30);

//    window.show();

//    // Connection
//    // This connection set the value of the progress bar
//    // while the sliders value change
//    QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int)));

//    Board board;
//    board.show();

    QWidget window;
    window.setFixedSize(600, 600);


//    Board *newBoard = new Board(&window);
//    window.show();

    BoardWidget *testWidget = new BoardWidget(&window);
    window.show();

    return app.exec();
}
