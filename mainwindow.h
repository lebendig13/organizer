#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Current.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void add();
    void remove();
    void save();

    void setPathFile();

private:
    void initialization();

    void routine();
    void goals();
    void buys();

private:

    Current curFile;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
