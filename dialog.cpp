#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

extern  MainWindow * game;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_PlayAgain_clicked()   //Iniciar juego
{
    game->reset();
    close();
}

void Dialog::on_Quit_clicked()         //Salir de la aplicacion
{
    game->close();
    close();
}
