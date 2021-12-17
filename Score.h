#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <iostream>
#include <QFont>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase();    //Funcion Incrementar Score
    int getScore();     //Funcion Obtener Score
private:
    int score;
};

#endif // SCORE_H
