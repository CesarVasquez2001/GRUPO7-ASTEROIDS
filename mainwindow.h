#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QKeyEvent>
#include "player.h"
#include "Score.h"
#include "Health.h"
#include "rocks.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
     //Q_Object Para recibir las señales
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);


    QGraphicsScene* scene ;
    QGraphicsView* view;
    Player *ply ;
    Score * score;
    Health * health;


private:
    Ui::MainWindow *ui;
    QMediaPlayer * music;
     rocks *rock1;
      rocks *rock;


public slots:
    void StartGame();
    void reset();
    void removeItem();


private slots:
    void on_PlayButton_clicked();
    void on_QuitButton_clicked();
    void on_New_triggered();
    void on_Close_triggered();

};

#endif // MAINWINDOW_H
