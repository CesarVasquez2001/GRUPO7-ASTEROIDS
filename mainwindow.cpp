#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QCoreApplication>
#include <QDebug>
#include <rocks.h>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <qmovie.h>

//CONSTRUCTOR - Mainwindows
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);        //Determinamos el tamaño de la ventana
    ui->setupUi(this);
}

//DESTRUCTOR -  Mainwindows
MainWindow::~MainWindow()
{
    delete ui;
}

//EVENTOS - pulsaciones realizadas por el Mouse
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    ply->setFocus();    //el widget Player recibirá el foco cuando la ventana se active.
    return;
}

//EVENTOs - pulsaciones realizadas por el teclado

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //el widget Player recibirá el foco cuando la ventana se active.
    ply->setFocus();
    return;
}


//INICIAR JUEGO
void MainWindow::StartGame() {

    //CREAMOS LA ESCENA
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QImage(":/img/background01.jpg"))); // IMAGEN PARA EL FONDO - BACKGROUND

    //CREAMOS AL JUGADOR - y definimos que sera el centro - mediante setFocus
    ply = new Player();

    ply->setFlag(QGraphicsItem::ItemIsFocusable); // Que el jugador sea enfocable
    ply->QGraphicsItem::setFocus();               // set focus
    scene->addItem(ply);                            //añadimos la nave al escensario
    //===================================================================================//

    //CREAMOS EL SCORE - LA VIDA Y LAS AÑADIMOS AL ESCESARIO
    score = new Score();        //Crear Score
    scene->addItem(score);      //Añadir Escore
    health = new Health();      //Crear Vida
    health->setPos(health->x(),health->y()+25); //Establecesmos la posicion
    scene->addItem(health);                     //Añadimos la vida al escensario


    //CREAMOS LA VISTA DE ESCENARIO Y PROCEDESMOS A CONFIGURAR EL TAMAÑO
    view = new QGraphicsView(scene);    //Creamoa la vista


    //PERMITE ELIMINAR LAS BARRAS DE DESPLAZAMIENTO
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //HORIZONTAL
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);       // VERTICAL


    view->setFixedSize(800,600);    //Tamaño de la vista
    setCentralWidget(view); //Estabelces la vista en el centro
    view->setFocus();
    view->show();

    //CORRIGE EL TAMAÑO DE LA VENTANA
    scene->setSceneRect(0,0,800,600);


    //El jugador se centra en la ventana para obtener su posición

    ply->setPos(view->width()/2,view->height()/2); //Establecemos la posicion de la nave en el medio
    ply->QGraphicsItem::setTransformOriginPoint(30,30); //Estabelecemos el origen
    ply->setTransformationMode(Qt::SmoothTransformation); // Transicion suave para q aparesca la nave




    //Creamos los Asteroides (rocas)  que seran añadidas al escenario
    rock = new rocks;               // creamos las rocas
    scene->addItem(rock);           // Añadimos las rocas al escenario
    QTimer * timers = new QTimer(); // Creamos un timer
    QObject::connect(timers,SIGNAL(timeout()),rock,SLOT(spawn())); // Coneexcion mediante una señal
    timers->start(5000); // timer start

    rock1 = new rocks;              // creamos las rocas
    scene->addItem(rock1);          // Añadimos las rocas al escenario
    QTimer * timer = new QTimer();  //Creamos un timer
    QObject::connect(timer,SIGNAL(timeout()),rock1,SLOT(spawn())); // Coneccion mediante una señal
    timer->start(5000);             //Inica el Time


    music = new QMediaPlayer(); //Creator elemento multimedia
    music->setMedia(QUrl("qrc:/sounds/corward_interstellar.mp3")); //Seleccionamos el archivo de musica

    //declaración if else para comprobar y reproducir música con ajuste de posición
    if (music->state() == QMediaPlayer::PlayingState){
        music->setPosition(0);
    }
    else if (music->state() == QMediaPlayer::StoppedState){
        music->play();
    }

}
//FUNCION - REINICIAR EL JUEGO
void MainWindow::reset()
{
    music->stop();         // DETENER MUSICA
    StartGame();      //iniciar juego
}


//FUNCION -PARA ELIMINAR ELEMENTOS
void MainWindow::removeItem()
{
    scene->removeItem(ply); //Remover al jugador
}



//BOTON PARA INCIAR EL JUEGO
void MainWindow::on_PlayButton_clicked()
{
    StartGame(); //Llamada a iniciar un nuevo juego
}
//Menú de botones para salir del juego
void MainWindow::on_QuitButton_clicked()
{
    close(); // close
}
//Menú Archivo para iniciar un nuevo juego
void MainWindow::on_New_triggered()
{
    reset(); // calls reset button
}

//Menú Archivo para cerrar el juego
void MainWindow::on_Close_triggered()
{
    close(); //close
}

