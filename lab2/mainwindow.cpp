#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<int> arr = {7, 9, 12, 4, 8, 20, 55, 32, 48, 24, 19, 51, 39, 44, 10, 19, 22, 42,3,10,12,50,9,49,29,30,17};
    sort.merge_sort(arr);
    dw = new DrawWindow(sort);
    start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::start()
{
    dw->show();
}
