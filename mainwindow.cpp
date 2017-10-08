#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileDialog>
#include <QDebug>

#include "globals.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pB_add, SIGNAL(clicked()), this, SLOT(add()));
    connect(ui->pB_remove, SIGNAL(clicked()), this, SLOT(remove()));
    connect(ui->pB_save, SIGNAL(clicked()), this, SLOT(save()));

    connect(ui->tB_pathFile, SIGNAL(clicked()), this, SLOT(setPathFile()));

    connect(ui->tW_categories, SIGNAL(itemSelectionChanged()), this, SLOT(showCategory()));

    connect(ui->actionHide, &QAction::triggered, this, &MainWindow::hideView);
    connect(ui->actionShow, &QAction::triggered, this, &MainWindow::showView);

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

    QString catName;

    catName = QS("Рутина");
    QTreeWidgetItem* it_routine = new QTreeWidgetItem(ui->tW_categories);
    it_routine->setText(0, catName);
    nameCategories[it_routine] = catName;

    catName = QS("Неделя");
    QTreeWidgetItem* it_week = new QTreeWidgetItem(ui->tW_categories);
    it_week->setText(0, catName);
    nameCategories[it_week] = catName;

    catName = QS("Календарь");
    QTreeWidgetItem* it_calendar = new QTreeWidgetItem(ui->tW_categories);
    it_calendar->setText(0, catName);
    nameCategories[it_calendar] = catName;

    catName = QS("Тематические списки");
    QTreeWidgetItem* it_types = new QTreeWidgetItem(ui->tW_categories);
    it_types->setText(0, catName);
    nameCategories[it_types] = catName;

    catName = QS("Глобальные цели");
    QTreeWidgetItem* it_goals = new QTreeWidgetItem(ui->tW_categories);
    it_goals->setText(0, catName);
    nameCategories[it_goals] = catName;

    catName = QS("Список покупок");
    QTreeWidgetItem* it_buys = new QTreeWidgetItem(ui->tW_categories);
    it_buys->setText(0, catName);
    nameCategories[it_buys] = catName;
}

void MainWindow::showCategory()
{
    foreach (QTreeWidgetItem* item, nameCategories.keys())
    {
        if (!item->isSelected())
            continue;

        qDebug() << QS("Выбрана категория '%1'").arg(nameCategories[item]);
    }
}

void MainWindow::showView()
{
    ui->splitter->setSizes(QList<int>() << ui->splitter->width() << 0);
}

void MainWindow::hideView()
{
    ui->splitter->setSizes(QList<int>() << ui->splitter->width()/2 << ui->splitter->width()/2);
}

void MainWindow::add()
{

}

void MainWindow::remove()
{

}

void MainWindow::save()
{

}

void MainWindow::setPathFile()
{
    QString path = ui->lE_pathFile->text();

    if (path.isEmpty())
        path = QDir::currentPath() + QS("/currentFile.txt");

    ui->lE_pathFile->setText(QFileDialog::getOpenFileName(this, QS("Укажите путь к файлу"), path, tr("Text (*.txt);; All files *.*")));

    curFile.setPath(ui->lE_pathFile->text());
    qDebug() << "curFile =" << curFile.getPath();
}

void MainWindow::routine()
{

}

void MainWindow::goals()
{

}

void MainWindow::buys()
{

}
