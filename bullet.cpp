#include "bullet.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QList>
#include "rocks.h"
#include "mainwindow.h"

extern MainWindow * game; // Global

bullet::bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    //Imagen de tipo PNG para la bala

    setPixmap(QPixmap(":/img/bullet_laser.png"));

    //Temporizador - conectar la bala

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); //Conectar con el temporizador con el slot

    timer->start(33); //Tiempo de inicio

}


//FUNCION - mover la bala

void bullet::move(){

    //Movimiento de la bala

    setPos(x()+(10*qSin( 0.0174533*rotation() )),y()-(10*qCos( 0.0174533*rotation() )));


    //Eliminar la bala desde arriba

    if (pos().y()  < 0){
        scene()->removeItem(this);
        delete this;
    }

    //Elimininar la bala desde abajo

    else if (pos().y()  >650)  {
        scene()->removeItem(this);
        delete this;
    }

    //Eliminar la bala desde la izquierda

    else if (pos().x()  < 0)  {
        scene()->removeItem(this);
        delete this;
    }

    //Eliminar la bala desde la derecha

    else if (pos().x()  >850)  {
        scene()->removeItem(this);
        delete this;
    }
}
