#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "globals.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initialization();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialization()
{
    //set general categories
    ui->tW_categories->setHeaderLabel(QS("Категории"));

    QTreeWidgetItem* it_routine = new QTreeWidgetItem(ui->tW_categories);
    it_routine->setText(0, QS("Рутина"));

    QTreeWidgetItem* it_week = new QTreeWidgetItem(ui->tW_categories);
    it_week->setText(0, QS("Неделя"));

    QTreeWidgetItem* it_calendar = new QTreeWidgetItem(ui->tW_categories);
    it_calendar->setText(0, QS("Календарь"));

    QTreeWidgetItem* it_types = new QTreeWidgetItem(ui->tW_categories);
    it_types->setText(0, QS("Тематические списки"));

    QTreeWidgetItem* it_goals = new QTreeWidgetItem(ui->tW_categories);
    it_goals->setText(0, QS("Глобальные цели"));
}
