#include "mainwindow.h"
#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include <QProgressBar>


MainWindow * game; // Objeto game de tipo global

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new MainWindow();    //Creamos un objetode Tipo MainWindows
    game-> show();       // Iniciar la ventana principal
    return a.exec();
}
