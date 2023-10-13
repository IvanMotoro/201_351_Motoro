#include "gamepage.h"
#include "ui_gamepage.h"

GamePage::GamePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePage)
{
    ui->setupUi(this);
    connect(ui->gametable, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
}

void GamePage::onTableClicked(const QModelIndex &index)
{
    summary += array[index.row()];
    ui->summ->setText(QString::number(summary));
    ui->gametable->itemFromIndex(index)->setText(QString::number(array[index.row()]));
}

void GamePage::createTable()
{
    summary = 0;

    // Задаем кол-во строк
    ui->gametable->setRowCount(0);

    // Задаем кол-во столбцов
    ui->gametable->setColumnCount(1);

    // Растягиваем последнюю колонку на всё доступное пространство
    ui->gametable->horizontalHeader()->setStretchLastSection(true);

    // Устанавливаем заголовки колонок
    ui->gametable->setHorizontalHeaderLabels({"Числа"});

    // Разрешаем выделение только одного элемента
    ui->gametable->setSelectionMode(QAbstractItemView::SingleSelection);

    // Запрещаемм редактирование элементов
    ui->gametable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // Создаём 12 элементов списка
    for (int i = 0; i < 12; i++)
    {
        array[i] = rand() % 9999;
        // Добавляем строку в таблицу
        ui->gametable->insertRow(ui->gametable->rowCount());
        // Сщздаём элемент таблицы
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText("****");
        item->setTextAlignment(Qt::AlignCenter);

        // Добавляем элеммент таблицы (row, column, item)
        ui->gametable->setItem(ui->gametable->rowCount()-1, 0, item);
    }
}

GamePage::~GamePage()
{
    delete ui;
}
