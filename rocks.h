#ifndef ROCKS_H
#define ROCKS_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>


class rocks :public QObject , public QGraphicsPixmapItem
{
    //Q_Object Para recibir las señales
    Q_OBJECT
public:
    rocks(QGraphicsItem * parent=0);
    rocks(int size);
    void explosion();
public slots:
    void move();
    void spawn();
    void split();

private:
    int size;
    qreal xvel;
    qreal yvel;
    QMediaPlayer * destroysound1;
    QMediaPlayer * destroysound2;
    QMediaPlayer * destroysound3;

    QMediaPlayer * shiphitsound;
};

#endif // ROCKS_H
