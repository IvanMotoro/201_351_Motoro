
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include "gamepage.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loginbtn_clicked();


private:
    Ui::MainWindow *ui;
    GamePage *game;
    QTimer m_antidebug_timer;
    void antidebug_timer();
};

#endif // MAINWINDOW_H
