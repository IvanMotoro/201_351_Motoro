
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new GamePage;
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_loginbtn_clicked()
{
    QString password = "1234";
    if (ui->passedit->text()==password){
        this->close();
        game->show();
        game->createTable();
    }

}

