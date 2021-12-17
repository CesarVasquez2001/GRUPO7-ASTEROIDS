#include "Health.h"
#include"dialog.h"
#include <QFont>
#include"mainwindow.h"


extern MainWindow * game;
//Constructor de la vida (Healt)

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){


    destroysound1 = new QMediaPlayer();
    destroysound1->setMedia(QUrl("qrc:/sounds/explosion1.mp3"));

    //Valor predeterminado de la salud - iniciado en 5

    health = 5; //

    //Mostrar la salud

    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::white);//Definimos el color
    setFont(QFont("Helvetica [Cronyx]",18)); //Estilo del texto
}



//FUNCION - Disminuir la vida

void Health::decrease(){

    health--;  //Disminuiar vida en 1

    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
    if (health == 0)
    {
        game->removeItem(); // LLama  a la funcion - Eliminar elemento en la ventana principal
        Dialog Dialog;
        explosion();
        Dialog.setModal(true); //Cuadro de dialogo para el final de juego  en verddero
        Dialog.exec();          //Mostrar el cuadro
    }
}

//FUNCION - Obtener la vida

int Health::getHealth(){

    return health;
}

void Health::explosion()
{
    //SONIDO - de explosion

    if (destroysound1->state() == QMediaPlayer::PlayingState){
        destroysound1->setPosition(0);
    }
    else if (destroysound1->state() == QMediaPlayer::StoppedState){
        destroysound1->play();
    }

}
