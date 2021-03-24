#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<int> arr = {7, 9, 12, 4, 8, 20, 55, 32, 48, 24, 19, 51, 39, 44, 10, 19, 22};
    view = new sd::MyGraphicsView<int>("Sorting", arr);
    view->show();
    auto oneSecondTimer = new QTimer(this);
    connect(oneSecondTimer, &QTimer::timeout, this, &MainWindow::start);
    oneSecondTimer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::start()
{
   std::vector<int> arr = {7, 9, 12, 4, 8, 20, 55, 32, 48, 24, 19, 51, 39, 44, 10, 19, 22};
   arr[0] = rand()%55;
   view->create_new_scene(arr);

}
