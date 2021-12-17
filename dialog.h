#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

//UI Inicial - Iniciar Juego o Salir de la aplicacion
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_PlayAgain_clicked(); //Iniciar juego

    void on_Quit_clicked();      //Salir de la aplicacion

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
