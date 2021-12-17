#include "Score.h"
#include"mainwindow.h"

//Constructor de Score
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){

    //Establecemos el valor inicial del Score en 0

    score = 0;

    //Mostramos en pantalla el Score actual

    setPlainText(QString("Score: ") + QString::number(score)); //valor inicial 0
    setDefaultTextColor(Qt::white);  //Color del texto
    setFont(QFont("Helvetica [Cronyx]",18)); //Estilo del texto
}

//FUNCION - Incrementar Score

void Score::increase(){

    score++;  //aumenta en uno el Score
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

//Obtener el Score (Puntuacion del jugador)

int Score::getScore(){
    return score;
}
