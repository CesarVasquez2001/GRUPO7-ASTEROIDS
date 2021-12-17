#include "rocks.h"
#include <QtCore/qmath.h>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>
#include <typeinfo>
#include "bullet.h"
#include "player.h"
#include "mainwindow.h"


extern MainWindow * game; // Global object

//CONSTRUCTOR DE LOS ASTEROIDES (rocas)
rocks::rocks(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    destroysound1 = new QMediaPlayer();
    destroysound1->setMedia(QUrl("qrc:/sounds/explosion1.mp3"));

    //Generar numero aleatorio - para la poscion de los Asteroides

    int random_number = qrand () % 700;

    //Posicion generada de forma aleatoria para los Asteroides

    int pos_x = rand () %2;
    if(pos_x == 0)
        xvel = qrand () % 5;
    else
        xvel = (qrand () % 5)* (-1);
    int pos_y = rand () %2;
    if (pos_y == 0)
        yvel = qrand () % 5;
    else
        yvel = (qrand() %5)*(-1);

    if (pos_x == 0)
        setPos(x() + random_number, y() - 60);
    else
        setPos(x() - 20, y() - random_number);


    //Asteroides

    size = 3;
    setPixmap(QPixmap(":/img/Grey_1.png"));

    //Conectar las rocas mediante Signal

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

rocks::rocks(int size)
{
    int pos_x = rand () %2;
    if(pos_x == 0)
        xvel = qrand () % 5+1;
    else
        xvel = (qrand () % 5+1)* (-1);
    int pos_y = rand () %2;
    if (pos_y == 0)
        yvel = qrand () % 5+1;
    else
        yvel = (qrand() %5+1)*(-1);
    switch (size)
    {
    case 3:
        setPixmap(QPixmap(":/img/Grey_2.png"));
        this->size = 2;

        break;
    case 2:
        setPixmap(QPixmap(":/img/Grey_3.png"));

        break;

    }
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(33);
    return;
}

//FUNCION - movimientos de las rocas

void rocks::move()
{
    //Movimiento realizado por los Asteroides - rectriccion por tamaño

    if(x() > 800)
        setPos(x() -800,y()-60);
    else if(x()<0)
        setPos(x() + 800,y()-60);

    if (y() > 650)
        setPos(x() ,y()-650);
    else if(y()<0)
        setPos(x(),y()+650);

    //Establecemos la posicion de los asteroides

    int xdir = xvel;
    int ydir = yvel;
    setPos(x()+xdir, y()+ydir);

    //Los Asteroides desaparecen si chocan con la nave

    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i<n; i++){
        //Condicion - si colisionan
        if (typeid(*(colliding_items[i])) == typeid (Player))
        {

            //Disminuye la vida de la nave en 1
            game->health->decrease();       //Disminye la vida
            scene()->removeItem(this);      //Remover roca de la escena
            delete this;                   //Borrar roca
            return;

        }
    }

    //Los Asteroides desaparecen sin chocan con las balas
    for (int i = 0, n = colliding_items.size(); i<n; i++){
        //Condicion - si colisionan
        if (typeid(*(colliding_items[i])) == typeid (bullet))   //Referencia al asteroide
        {


            //llama a la funcion incrementar el Score
            game->score->Score::increase();
            //Funcion Explosion

            //Los Asteroides y las balas son retiradas de la escena

            this->split();
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Liberamos la memoria

            delete colliding_items[i];
            delete this;

            return;
        }
    }

}

//FUNCION - generar Asteroides

void rocks::spawn(){
    rocks * rock = new rocks();     //Crear Asteroides
    scene()->addItem(rock);         //Añadir Asteroides a la esccena
}

//FUNCION - Generar asteroides en una posicion respectiva en los ejes X - Y
void rocks::split()
{
    switch (size)
    {
    case 3:
    {
        rocks * rocks1 = new rocks(3);
        rocks * rocks2 = new rocks(3);
        rocks1 -> setPos(x(), y());
        rocks2 -> setPos(x(), y());

        scene()->addItem(rocks1);
        scene()->addItem(rocks2);
        break;
    }

    case 2:
    {
        rocks * rocks1 = new rocks(2);
        rocks * rocks2 = new rocks(2);
        rocks1 -> setPos(x(), y());
        rocks2 -> setPos(x(), y());

        scene()->addItem(rocks1);
        scene()->addItem(rocks2);
        break;
    }

    default:
    {

        break;
    }
    }
}


//FALLA
/*
void rocks::explosion()
{
    //SONIDO - de explosion

    if (destroysound1->state() == QMediaPlayer::PlayingState){
        destroysound1->setPosition(0);
    }
    else if (destroysound1->state() == QMediaPlayer::StoppedState){
        destroysound1->play();
    }

}

*/
