#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = nullptr;
    this->setFixedSize(800,600);
    start();      
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::start()
{
    std::vector<int> arr = {7, 9, 12, 4, 8, 20, 55, 32, 48, 24, 19, 51, 39, 44, 10, 19, 22};
    for(std::size_t i = 0; i < 60; i++) arr.push_back(60 - i);
    sorts::merge_sort(arr);
    view = new sd::MyGraphicsView<int>("Merge sort",arr);
    //view->show();


    qDebug(sorts::array_to_string(arr).c_str());
}

void MainWindow::on_visualizationButton_clicked()
{
    ui->verticalWidget->setEnabled(false);
    ui->verticalWidget->setVisible(false);
    ui->graphicsView->setEnabled(true);
    ui->graphicsView->setScene(view->get_scene());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->fitInView( ui->centralwidget->rect(), Qt::KeepAspectRatio );
}
