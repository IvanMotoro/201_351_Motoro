#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QWidget>
#include <ctime>
#include <QTableWidgetItem>
#include <QMessageBox>

namespace Ui {
class GamePage;
}

class GamePage : public QWidget
{
    Q_OBJECT

public:
    explicit GamePage(QWidget *parent = nullptr);
    ~GamePage();
    int array[12];
    int summary;
    int k;
    void createTable();

public slots:
    void onTableClicked(const QModelIndex &index);

private:
    Ui::GamePage *ui;
};

#endif // GAMEPAGE_H
