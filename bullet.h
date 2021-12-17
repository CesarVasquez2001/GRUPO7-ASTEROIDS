#ifndef BULLET_H
#define BULLET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>


class bullet: public QObject, public QGraphicsPixmapItem
{
        //Q_Object Para recibir las señales
    Q_OBJECT
public:
    bullet(QGraphicsItem * parent=0);
public slots:
    void move();

};

#endif // BULLET_H
