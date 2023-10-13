
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <Windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    game = new GamePage;
    ui->debug->setVisible(false);

    m_antidebug_timer.setInterval(1000);
    connect(&m_antidebug_timer, &QTimer::timeout, this, &MainWindow::antidebug_timer);
    m_antidebug_timer.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::antidebug_timer() {
    if (IsDebuggerPresent()) {
        ui->debug->setVisible(true);
    }
}

void MainWindow::on_loginbtn_clicked()
{
    QFile file("hash.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    //считываем файл для шифрования
    QString value = file.readAll();
    QByteArray pin = value.toUtf8();

    qDebug() << QString::fromStdString(game->check_pincode(ui->passedit->text()).toStdString());

    //если хеш пин-кода совпадет с имеющимся, то вход в приложение будет успешным
    if (game->check_pincode(ui->passedit->text()) == pin){
        this->close();
        game->show();
        game->createTable();
    }

}

