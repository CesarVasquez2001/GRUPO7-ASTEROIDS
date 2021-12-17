#include "player.h"
#include <QDebug>
#include "QTimer"
#include <QtCore/qmath.h>
#include <QObject>
#include <QGraphicsItem>
#include "bullet.h"
#include "rocks.h"

//CONSTRUCTOR - Player

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{

    bulletsound = new QMediaPlayer(); // Creamos un elemento multimedia
    bulletsound->setMedia(QUrl("qrc:/sounds/Disparo.mp3")); // Estabelecemos el archivo de audio


    setPixmap(QPixmap(":/img/Ship_space.png"));  //Imagen de la Nave
    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT (move()));
    timer->start(30);

}

//DESTRUCTOR de Player

Player::~Player() {

}


//FUNCION  - movimiento del Player (nave)

void Player::move() {

    if(xvel <= -5.0) { xvel = -5.0; }
    if(xvel >= 5.0) { xvel = 5.0; }
    if(yvel <= -5.0) { yvel = -5.0; }
    if(yvel >= 5.0) { yvel = 5.0; }
    setPos(x()+xvel, y()+yvel);

    //Realizar la vuelta tipo cilindo en el escenario

    if(x() > 800)
        setPos(x() -800,y());
    else if(x()<0)
        setPos(x() + 800,y());

    if (y() > 600)
        setPos(x() ,y()-600);
    else if(y()<0)
        setPos(x(),y()+600);
}


//FUNCION - Movimiento realizados por las pulsaciones en el teclado

void Player::keys() {

    foreach(Qt::Key k, keysPressed)
    {
        switch(k)
        {
        case Qt::Key_Up:    //tecla direccionnal - arriba
        case Qt::Key_W:      //tecla - W
        {
            xvel += 0.5*(qSin( 0.0174533*rotation() ));
            yvel += -0.5*(qCos( 0.0174533*rotation() ));

            break;
        }

        case Qt::Key_Left:       //tecla direccionnal - izquierda
        case Qt::Key_A:          //tecla - A
        {
            setRotation(rotation() -15);
            break;
        }

        case Qt::Key_Right:      //tecla direccionnal - Derecha
        case Qt::Key_D:          //tecla D
        {
            setRotation(rotation() +15);
            break;
        }


        case Qt::Key_Space:      //tecla - barra espaciadora
        {

            angle = rotation();              // Se establece el angulo de disparo
            bullet * bull = new bullet();    // Crear balas
            bull->setPos(x()+20,y()+20);     // Posicion de la bala con respecto a la posicion de la nave
            bull->QGraphicsItem::setTransformOriginPoint(10,10); //Establecemos el origen de la bala
            bull->setRotation(angle);         //Establecemos el angulo de la bala
            scene()->addItem(bull);          //añadimos la bala la escenario


            //SONIDO - de la bala

            if (bulletsound->state() == QMediaPlayer::PlayingState){
                bulletsound->setPosition(0);
            }
            else if (bulletsound->state() == QMediaPlayer::StoppedState){
                bulletsound->play();
            }

            break;
        }
        default:
        {

            break;
        }
        }
    }
}


//FUNCIONES REALIZADAS AL PRESIONAR LA TECLA CORRESPONDIENTE

void Player::keyPressEvent(QKeyEvent *event)
{
    keysPressed += (Qt::Key)event->key();
    QTimer::singleShot(10, this, SLOT(keys())); //SEÑAL  - pulsacion de la tecla

}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    keysPressed -= (Qt::Key)event->key();
    QTimer::singleShot(10, this, SLOT(keys())); //SEÑAL  - pulsacion de la tecla
}
