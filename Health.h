#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();        //Funcion disminuir vida
    int getHealth();        // Obtener vida actual
    void explosion();
private:
    int health;
    QMediaPlayer * destroysound1;
};

#endif // HEALTH_H
